struct Gsymbol *Lookup(char *name) {
    struct Gsymbol *tmp = head;
    while (tmp != NULL && (strcmp(tmp->name, name) != 0)) {
        tmp = tmp->next;
    }

    // Debug print statement
    printf("Lookup function: Variable '%s', Found: %s\n", name, (tmp ? "Yes" : "No"));

    return tmp;
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
    tmp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    tmp->name=(char *)malloc(sizeof(strlen(name)+1));
    strcpy(tmp->name,name);
    tmp->type=type;
    tmp->size=size;
    tmp->binding=variable_position;
    variable_position+=tmp->size;
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
