int counter=-1;
int i,j;
int label=0;

//to check if break and continue are inside the loop we use these variables
int while_start=-1;
int while_end=-1;
//break statements will be encountered in the codegen() part of t->right in while during which these labels will not be -1
extern FILE *target_file;

int getLabel()
{
    return ++label;
}

int getReg()
{
    if(counter<20) return ++counter;
    printf("Out of registers\n");
    exit(1);
}

int freeReg()
{
    if(counter>=0) counter--;
}

int codegen(struct tnode *t)
{
    int r1,r2,r3; //registers
    int l1,l2; //labels for conditionals and loops
    int stack_pos; //stack position of variables
    int context; //stores the position of current context on the stack
    int prev_start; //store the previous value of while_start
    int prev_end; //store the previous value of while_end
    if(t==NULL)
        exit(1);
    else if(t->nodetype==NODE_CONN)
    {
        codegen(t->left);
        codegen(t->right);
    }

    switch(t->nodetype)
    {
        case NODE_NUM:
            r1=getReg();
            fprintf(target_file,"MOV R%d,%d\n",r1,t->val);
            return r1;
        case NODE_ID:
            stack_pos=4096+t->varname[0]-'a';
            r1=getReg();
            fprintf(target_file,"MOV R%d,[%d]\n",r1,stack_pos);
            return r1;
        case NODE_PLUS:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file,"ADD R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file,"SUB R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file,"MUL R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file,"DIV R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_ASSIGN:
            stack_pos=4096+t->left->varname[0]-'a';
            r1=codegen(t->right);
            fprintf(target_file,"MOV [%d],R%d\n",stack_pos,r1);
            freeReg();
            return 0;
        case NODE_READ:
            stack_pos=4096+t->left->varname[0]-'a';
            //save the context first
            for(i=0;i<=counter;i++)
                fprintf(target_file,"PUSH R%d\n",i);
            context=counter;
            //Fill the stack arguments for read library call
            fprintf(target_file,"MOV R0,\"Read\"\n"); //first arg
            fprintf(target_file,"PUSH R0\n");
            fprintf(target_file,"MOV R0,-1\n"); //second arg
            fprintf(target_file,"PUSH R0\n");
            fprintf(target_file,"MOV R0,%d\n",stack_pos); //read buffer-third arg
            fprintf(target_file,"PUSH R0\n");
            fprintf(target_file,"ADD SP,2\n");//fourth & fifth arg
            fprintf(target_file,"CALL 0\n");
            fprintf(target_file,"SUB SP,5\n"); //pop and discard the five arguments
            
            for(int i=context;i>=0;i--)
                fprintf(target_file,"POP R%d\n",i);
            counter=context;
            break;
        case NODE_WRITE:
            for (i = 0; i <= counter; i++)
                fprintf(target_file, "PUSH R%d\n", i);
            context = counter;

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

            for (i = context; i >= 0; i--)
                fprintf(target_file, "POP R%d\n", i);
            counter = context;
            break;
        case NODE_GT:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "GT R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_LT:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "LT R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "GE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "LE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "EQ R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1=codegen(t->left); r2=codegen(t->right);
            fprintf(target_file, "NE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case NODE_IF:
            l1=getLabel();
            r1=codegen(t->left); fprintf(target_file,"JZ R%d,L%d\n",r1,l1); //false condition
            freeReg();
            stack_pos=codegen(t->right); //true condition
            //end the if
            fprintf(target_file,"L%d:\n",l1);
            break;
        case NODE_IF_ELSE:
            l1=getLabel(); l2=getLabel();
            r1=codegen(t->left); fprintf(target_file,"JZ R%d,L%d\n",r1,l1); //false condition
            freeReg();
            stack_pos=codegen(t->mid); //true condition
            fprintf(target_file,"JMP L%d\n",l2); //end of if else statement
            //else condition
            fprintf(target_file,"L%d:\n",l1);
            stack_pos=codegen(t->right);
            fprintf(target_file,"L%d:\n",l2);
            break;
        case NODE_WHILE:
            prev_start=while_start;
            prev_end=while_end;
            //Since the loop start we can safely have break and continue statements
            l1=getLabel(); l2=getLabel();
            while_start=l1; while_end=l2;
            //start of the loop
            fprintf(target_file,"L%d:\n",l1);
            r1=codegen(t->left); //evaluate the condition
            //if condition not true, jump to end of loop
            fprintf(target_file,"JZ R%d,L%d\n",r1,l2);
            freeReg();
            //if true,evaluate it
            stack_pos=codegen(t->right);
            fprintf(target_file,"JMP L%d\n",l1);
            //loop over
            fprintf(target_file,"L%d:\n",l2);
            //restore the check variables
            while_start=prev_start; while_end=prev_end;
            break;
        case NODE_BREAK:
            if(while_end != -1)
                fprintf(target_file, "JMP L%d\n", while_end);
            break;
        case NODE_CONTINUE:
            if(while_start != -1)
                fprintf(target_file, "JMP L%d\n", while_start);
            break;
    }
}
