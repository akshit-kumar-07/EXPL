%{
#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"
#include "exprtree.c"
int yyerror();
int yylex();
%}

%union
{
    struct tnode *no;
};
%type <no> NUM expr program END
%token NUM PLUS MINUS MUL DIV END
%left MINUS 
%left PLUS
%left MUL
%left DIV

%%
program : expr  END 
        {
            $$=$2;
            printf("Answer = %d\n",evaluate($1));
            exit(0);
        }
        ;

expr: expr PLUS expr
    {$$=makeOperatorNode('+',$1,$3);}
    | expr MINUS expr
    {$$=makeOperatorNode('-',$1,$3);}
    | expr MUL expr
    {$$=makeOperatorNode('*',$1,$3);}
    | expr DIV expr
    {$$=makeOperatorNode('/',$1,$3);}
    | '(' expr ')'
    {$$=$2;}
    | NUM {$$=$1;}
    ;
%%

int yyerror(char const *s)
{
    printf("Error : %s\n",s);
}

int main()
{
    yyparse();
    return 0;
}
