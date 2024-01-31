int counter = -1, i, j, label=0;
int whileStart = -1, whileEnd = -1;
int codegen(struct tnode *);
extern FILE *target_file;

int getlabel() {
    return ++label;
}
int getReg() {
    if(counter < 20)
        return ++counter;
    printf("Out of Registers");
    exit(1);
}
int freeReg() {
    if(counter >= 0)
        counter--;
}

int getMemoryAddress(struct tnode* t) {
    int r;
    if(t->nodetype == NODE_ID) {
        r = getReg();
        fprintf(target_file, "MOV R%d, %d\n", r, t->Gentry->binding);
        return r;
    } else if(t->nodetype == NODE_ARRAY) {
        r = codegen(t->right);
        fprintf(target_file, "ADD R%d, %d\n", r, t->left->Gentry->binding);
        return r;
    } else {
        return -1;
    }
}

int codegen(struct tnode* t) {
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) {
        return -1;
    } else if(t->nodetype == NODE_CONN) {
        codegen(t->left);
        codegen(t->right);
        return -1;
    }

    switch(t->nodetype) {
        case NODE_NUM:
            r1 = getReg();
            fprintf(target_file, "MOV R%d, %d\n", r1, t->val);
            return r1;
        case NODE_STRVAL:
            r1 = getReg();
            fprintf(target_file, "MOV R%d, %s\n", r1, t->varname);
            return r1;
        case NODE_ID:
            r1 = getMemoryAddress(t);
            fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_ARRAY:
            r1 = getMemoryAddress(t);
            fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_PLUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "SUB R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "MUL R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "DIV R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MOD:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "MOD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "NE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_AND:
			r1 = codegen(t->left);
			r2 = getReg();
			fprintf(target_file, "MOV R%d,1\n", r2);
			l1 = getlabel();
			fprintf(target_file, "JZ R%d,L%d\n", r1, l1);
			r3 = codegen(t->right);
			fprintf(target_file, "MOV R%d,R%d\n", r2, r3);
			freeReg();
			fprintf(target_file, "L%d:\n", l1);
			fprintf(target_file, "MUL R%d,R%d\n", r1, r2);
			freeReg();
			return r1;
			break;
        case NODE_ASSIGN:
            r1 = getMemoryAddress(t->left);
            r2 = codegen(t->right);
            fprintf(target_file, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();
            return 0;
        case NODE_WRITE:
            for (i = 0; i <= counter; i++)
                fprintf(target_file, "PUSH R%d\n", i);
            status = counter;

            fprintf(target_file, "MOV R0,\"Write\"\n");
            fprintf(target_file, "PUSH R0\n"); // function code "Write"
            fprintf(target_file, "MOV R0,-2\n");
            fprintf(target_file, "PUSH R0\n"); //Argument 1

            r1 = codegen(t->left);
            fprintf(target_file, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(target_file, "ADD SP,2\n");
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(target_file, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_READ:
            for (i = 0; i <= counter; i++)
                fprintf(target_file, "PUSH R%d\n", i);
            status = counter;

            fprintf(target_file, "MOV R0,\"Read\"\n");
            fprintf(target_file, "PUSH R0\n"); // function code "Write"
            fprintf(target_file, "MOV R0,-1\n");
            fprintf(target_file, "PUSH R0\n"); //Argument 1

            r1 = getMemoryAddress(t->left);
            fprintf(target_file, "PUSH R%d\n", r1); //Argument 2
            freeReg();

            fprintf(target_file, "ADD SP,2\n");
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(target_file, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_IF:
            r1 = codegen(t->left); 
            l1 = getlabel();
            fprintf(target_file, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->right);
            fprintf(target_file, "L%d:\n", l1);
            freeReg();
            break;
        case NODE_IF_ELSE:
            r1 = codegen(t->left);
            l1 = getlabel();
            l2 = getlabel();
            fprintf(target_file, "JZ R%d,L%d\n", r1, l1);
            freeReg();
            number = codegen(t->mid);
            fprintf(target_file, "JMP L%d\n", l2);
            fprintf(target_file, "L%d:\n", l1);
            number = codegen(t->right);
            fprintf(target_file, "L%d:\n", l2);
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

            fprintf(target_file, "L%d:\n", l1);
            r1 = codegen(t->left);
            fprintf(target_file, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->right);
            fprintf(target_file, "JMP L%d\n", l1);
            fprintf(target_file, "L%d:\n", l2);

            // Restore while start and end labels
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            break;
        case NODE_BREAK:
            if(whileEnd != -1)
                fprintf(target_file, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONTINUE:
            if(whileStart != -1)
                fprintf(target_file, "JMP L%d\n", whileStart);
            break;
    }
}
