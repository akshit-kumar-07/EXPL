int counter=-1;
extern FILE *target_file;
int getReg()
{
	if(counter<20)
		return ++counter;
	printf("Registers Exhausted\n");
	exit(1);
}

int freeReg()
{
	if(counter>=0)
		counter--;
}

int codeGen(struct tnode *t)
{
	if(t==NULL)
		return -1;
	if(t->op==NULL)
	{
		int reg=getReg();
		fprintf(target_file,"MOV R%d,%d\n",reg,t->val);
		return reg;
	}
	int reg1=codeGen(t->left);
	int reg2=codeGen(t->right);
	switch(*(t->op))
	{
		case '+':
			fprintf(target_file,"ADD R%d,R%d\n",reg1,reg2);
			freeReg();
			return reg1;
		case '-':
			fprintf(target_file,"SUB R%d,R%d\n",reg1,reg2);
			freeReg();
			return reg1;
		case '*':
			fprintf(target_file,"MUL R%d,R%d\n",reg1,reg2);
			freeReg();
			return reg1;
		case '/':
			fprintf(target_file,"DIV R%d,R%d\n",reg1,reg2);
			freeReg();
			return reg1;
		default:
			break;
	}
}

