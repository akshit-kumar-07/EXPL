int counter=-1;
int i,j;
extern FILE *target_file;

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
    int stack_pos; //stack position of variables
    int context; //stores the position of current context on the stack
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
    }
}
