int counter=-1;
extern FILE *target_file;

int getReg()
{
    if(counter<20)
        return ++counter;
    printf("Out of registers\n");
    exit(1);
}

void freeReg()
{
    if(counter>=0)
        counter--;
}

int codegen(struct tnode *t)
{
    int stack_pos;//for storing the position of variables in the stack
    int r1,r2,r3; //for storing the register numbers
    if(t==NULL)
        return -1;
    else if(t->nodetype==NODE_CONN)
    {
        codegen(t->left);
        codegen(t->right);
    }
    
    switch(t->nodetype)
    {
        case NODE_NUM:
            r1=getReg();
            fprintf(target_file,"MOV R%d,%d",r1,t->val);
            return r1;
        case NODE_ID:
            r1=getReg();
            stack_pos=4096+t->varname[0]-'a'; //calculate the position on the stack where the variable
                                              //is located
            fprintf(target_file,"MOV R%d,[%d]\n",r1,stack_pos);
            return r1;
        case NODE_PLUS:
            r1=codegen(t->left);
            r2=codegen(t->right);
            fprintf(target_file,"ADD R%d,R%d\n",r1,r2);
            freeReg(); //as result is stored in the lower reg so only that is required
            return r1;
        case NODE_MINUS:
            r1=codegen(t->left);
            r2=codegen(t->right);
            fprintf(target_file,"SUB R%d,R%d\n",r1,r2);
            freeReg(); //as result is stored in the lower reg so only that is required
            return r1;
        case NODE_MUL:
            r1=codegen(t->left);
            r2=codegen(t->right);
            fprintf(target_file,"MUL R%d,R%d\n",r1,r2);
            freeReg(); //as result is stored in the lower reg so only that is required
            return r1;
        case NODE_DIV:
            r1=codegen(t->left);
            r2=codegen(t->right);
            fprintf(target_file,"DIV R%d,R%d\n",r1,r2);
            freeReg(); //as result is stored in the lower reg so only that is required
            return r1;
        case NODE_ASSIGN:
            stack_pos=4096+t->left->varname[0]-'a';
            r2=codegen(t->right);
            fprintf(target_file,"MOV [%d],R%d\n",stack_pos,r2);
            freeReg();
            return 0;
        case NODE_WRITE:
            //We need to implement the library write code here
            //Push all the registers first to save the context
            for(int i=0;i<=counter;i++)
                fprintf(target_file,"PUSH R%d\n",i);
            //now we implement the code to call the Write function from 
            //the library
            fprintf(target_file,"MOV R0,\"Write\"\n");
            fprintf(target_file,"PUSH R0\n"); //First push the fn code
            fprintf(target_file,"MOV R0,-2\n"); //second arg a/c to ABI for write
            fprintf(target_file,"PUSH R0\n");
            //The next arg is value to be written so we first calculate the value 
            //of the arg of write(x) and find which reg it's stored in
            r1=codegen(t->left);
            fprintf(target_file,"PUSH R%d\n",r1);
            freeReg(); //the value is already in the stack so we don't need to remember it in a 
                       //register anymore
            //The third arg is arbitary and the fourth is blank for holding the return value
            fprintf(target_file,"MOV R
    }
}
