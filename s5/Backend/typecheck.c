void typecheck(int t1, int t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror("Expected Boolean in WHILE check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror("Expected Boolean in IF ELSE check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror("Expected Boolean in IF check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for arithmetic operation\n", NULL);
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n", NULL);
                      exit(1);
                  }
                  break;
        case 'l': if(t1 != TYPE_BOOL || t2 != TYPE_BOOL) {
                      yyerror("Invalid type for logical operation\n", NULL);
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      yyerror("Invalid type for assignment operation\n", NULL);
                      exit(1);
                  }
                  break;
    }
}

//Checks if the identiifer name is already present
int checkAvailability(char *name, int global)
{
    if(global)
    {
        Gtemp = GLookup(name);
        if(Gtemp != NULL)
        {
            yyerror("Variable %s is alreadt declared in the global scope\n",name);
            exit(1);
        }
    }
    else
    {
        Ltemp = LLookup(name);
        Ptemp = PLookup(name);
        if(Ptemp != NULL || Ltemp != NULL)
        {
            yyerror("the variable %s is already declarad in the function scope\n",name);
            exit(1);
        }
    }

    return 1; //the identifier name is valid
}

//This function checks/finds the variable/fucntion in scope
//The following are various codes
/* Code 0 : Local or Global variable
 * Code 1 : Function
 * Code 2 : Array
 */
//the type needs to be assigned using this to avoid scope conflicts

void assignType(struct ASTNode *node, int code)
{
    //First check in the local scope
    Ltemp = LLookup(node->name);
    if(Ltemp != NULL && code == 0) //found the var in local scope
    {
        node->Lentry = Ltemp;
        node->type = Ltemp->type;
    }
    else //not found in local scope
    {
        //look in the global scope first
        Gtemp = GLookup(node->name);
        if(Gtemp != NULL) //the variable is found in the Global scope
        {
            node->Gentry = Gtemp;
            node->type = Gtemp->type;

            //Check if the function declaration is valid or not
            if(code == 1 && Gtemp->size != -1)
            {
                yyerror("Expected a function declaration for %s\n",node->name);
                exit(1);
            }
        }
        else //identifier not found in either global or local scope
        {
            if(code == 1)
                yyerror("Function %s is not declarad\n",node->name);
            else
                yyerror("Variable %s is not declarad\n",node->name);
            exit(1);
        }
    }

    return;
}
