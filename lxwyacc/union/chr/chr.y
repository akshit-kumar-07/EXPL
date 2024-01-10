%{
#include <stdio.h>
#include <stdlib.h>
int yyerror();
%}

%union
{
    char ch;
};

%token LETTER
%type <ch>LETTER
%left '+'
%left '*'

%%
start: expr ';' {exit(0);}
expr : expr '+' expr 
     {printf("+ "); }
     | expr '*' expr
     {printf("* ");}
     | '(' expr ')'
     | LETTER 
     {printf("%c",$<ch>1);}
     ;
%%

int yyerror(char *s)
{
    printf("Error : %s\n",s);
}

int main()
{
    yyparse();
    return 0;
}
