%{
#include <stdio.h>
#include <stdlib.h>
%}

%token DIGIT NEWLINE

%%
start: expr NEWLINE 
     {
        printf("\n Completed \n");
        exit(0);
     }
     ;

expr: expr '+' expr
    { printf("+ ");}
    | expr '-' expr
    {printf("- "); }
    | '(' expr ')'
    | DIGIT 
    {printf("%d ", $1);} 
    ;
%%

void yyerror(char *s)
{
    printf("yyerror %s\n",s);
    return;
}

int main()
{
    yyparse();
    return 0;
}
