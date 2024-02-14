int counter = -1, i, j, label=0;
int whileStart = -1, whileEnd = -1;
extern FILE *intermediate;

int getlabel() {
    return ++label;
}
int getReg() {
    if(counter < 20)
        return ++counter;
    yyerror("Out of Registers", NULL);
    exit(1);
}
int freeReg() {
    if(counter >= 0)
        counter--;
}
int freeAllReg() {
    counter = -1;
}

int pushArguments(struct ASTNode *t) {
    int r;
    while(t != NULL) {
        r = codegen(t);
        fprintf(intermediate, "PUSH R%d\n", r);
        freeReg();
        t = t->arglist;
    }
}

int popArguments(struct ASTNode *t) {
    int r = getReg();
    while(t != NULL) {
        fprintf(intermediate, "POP R%d\n", r);
        t = t->arglist;
    }
    freeReg();
}

int getMemoryAddress(struct ASTNode* t) {
    int r;
    if(t->nodetype == NODE_ID && t->Gentry != NULL) {
        r = getReg();
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        return r;
    } else if(t->nodetype == NODE_ID) {
        r = getReg();
        fprintf(intermediate, "MOV R%d,BP\n", r);
        fprintf(intermediate, "ADD R%d,%d\n", r, t->Lentry->binding);
        return r;
    } else if(t->nodetype == NODE_ARRAY) {
        r = codegen(t->ptr2);
        fprintf(intermediate, "ADD R%d, %d\n", r, t->ptr1->Gentry->binding);
        return r;
    } else {
        printf("Cannot find memory address of nodetype %d", t->nodetype);
        exit(1);
    }
    return -1;
}

int codegen(struct ASTNode* t) {
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) {
        return -1;
    } else if(t->nodetype == NODE_CONNECTOR) {
        codegen(t->ptr1);
        codegen(t->ptr2);
        return -1;
    }

    switch(t->nodetype) {
        case NODE_NUM:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %d\n", r1, t->value.intval);
            return r1;
        case NODE_STRVAL:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %s\n", r1, t->value.strval);
            return r1;
        case NODE_ID:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_ARRAY:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_PLUS:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "SUB R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MUL R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "DIV R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MOD:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MOD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LT:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "NE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_AND:
			r1 = codegen(t->ptr1);
			r2 = getReg();
			fprintf(intermediate, "MOV R%d,1\n", r2);
			l1 = getlabel();
			fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
			r3 = codegen(t->ptr2);
			fprintf(intermediate, "MOV R%d,R%d\n", r2, r3);
			freeReg();
			fprintf(intermediate, "L%d:\n", l1);
			fprintf(intermediate, "MUL R%d,R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
		case NODE_OR:
			r1 = codegen(t->ptr1);
			r2 = getReg();
			fprintf(intermediate, "MOV R%d,1\n", r2);
			l1 = getlabel();
			fprintf(intermediate, "JNZ R%d,L%d\n", r1, l1);
			r3 = codegen(t->ptr2);
			fprintf(intermediate, "MOV R%d,R%d\n", r2, r3);
			freeReg();
			fprintf(intermediate, "L%d:\n", l1);
			fprintf(intermediate, "ADD R%d,R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
        case NODE_ASSGN:
            r1 = getMemoryAddress(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();
            return 0;
            
        case NODE_WRITE:
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Write\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-2\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = codegen(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_READ:
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = getMemoryAddress(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();

            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_IF:
            r1 = codegen(t->ptr1); 
            l1 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->ptr2);
            fprintf(intermediate, "L%d:\n", l1);
            freeReg();
            break;
        case NODE_IF_ELSE:
            r1 = codegen(t->ptr1);
            l1 = getlabel();
            l2 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            freeReg();
            number = codegen(t->ptr3);
            fprintf(intermediate, "JMP L%d\n", l2);
            fprintf(intermediate, "L%d:\n", l1);
            number = codegen(t->ptr2);
            fprintf(intermediate, "L%d:\n", l2);
            break;
        case NODE_WHILE:
            l1 = getlabel();
            l2 = getlabel();

            // Store old while start and end
            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;
            // Change to new start and end labels
            whileStart = l1;
            whileEnd = l2;

            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->ptr1);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->ptr2);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);

            // Restore while start and end labels
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            break;
        case NODE_BREAK:
            if(whileEnd != -1)
                fprintf(intermediate, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONT:
            if(whileStart != -1)
                fprintf(intermediate, "JMP L%d\n", whileStart);
            break;
        case NODE_RET:
            r1 = getReg();
            r2 = codegen(t->ptr1); //to get what we need to return from the function

            fprintf(intermediate,"MOV R%d,BP\n", r1); //BP points to the beginning of the activation record of the stack

            //1. first step is to store the return value which is stored at the position BP-2 on the stack
            /*
             * return value
             * return address
             * start of activation record of the new function(BP)
            */

            //move the pointer to the return value space BP-2
            fprintf(intermediate,"ADD R%d,%d\n",r1,-2);

            //store the value generated in r2 over this location
            fprintf(intermediate,"MOV [R%d],R%d\n",r1,r2);

            //now we dont require r1 and r2
            freeReg();
            freeReg();

            //2. Now the next step is to pop out all the local variables

            Ltemp = Lhead; //Point to the beginning of the Local Symbol Table

            while(Ltemp != NULL)
            {
                if(Ltemp->binding > 0) //actual local variables and not the formal parametrs that are stored
                    fprintf(intermediate, "POP R0\n");
                Ltemp = Ltemp->next;
            }

            //3. Last step is to pop out the value of the old BP and save it to the BP register

            fprintf(intermediate, "POP BP\n");
            fprintf(intermediate, "RET\n");
            break;

        case NODE_FUNC:
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;
            freeAllReg();

            pushArguments(t->ptr1); //Push Arguments
            fprintf(intermediate, "PUSH R0\n"); //Space for return value
            fprintf(intermediate, "CALL F%d\n", t->Gentry->flabel); //Space for return value

            r1 = status + 1;
            fprintf(intermediate, "POP R%d\n", r1); // for return value

            popArguments(t->ptr1); // Pop Arguments

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            r1 = getReg();
            return r1;
            break;
        default:
            printf("%d: This shouldn't have happened", t->nodetype);
            exit(1);
    }
}
