#include "symbol_table.h"

Gsymbol *Lookup(char *name)
{
    Gsymbol *tmp=head;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->name,name)==0)
            return tmp;
        tmp=tmp->next;
    }
    return NULL;
}

void Install(char *name, int type, int size) //inserts the new token at the beginning
{
   //first check if the token is not already installed in the symbol symbol_table
    Gsymbol *tmp=Lookup(name);
    if(tmp)
    {
        yyerror("The token %s is already installed in the symbol table\n",name);
        exit(1);
    }
    //check if the size field is greater than 0
    if(size<1)
    {
        yyerror("the size declared for token %s is invalid\n",name);
        exit(1);
    }
    //Symbol is not installed already:
    tmp=(Gsymbol *)malloc(sizeof(Gsymbol));
    tmp->name=(char *)malloc(sizeof(name));
    strcpy(tmp->name,name);
    tmp->type=type;
    tmp->size=size;
    tmp->binding=variable_position;
    variable_position+=size;
    tmp->next=head;
    head=tmp;
}

void print_symbol_table()
{
    Gsymbol *tmp=head;
    while(tmp!=NULL)
    {
        fprintf(stdout,"The entry is-> Name : %s, Size : %d, Type : %d, Binding : %d\n",tmp->name,tmp->size,tmp->type,tmp->binding);
        tmp=tmp->next;
    }
}
