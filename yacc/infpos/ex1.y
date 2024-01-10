%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
%}

%token DIGIT
%left '+' '-'
%left '*' '/'

%% 
start : expr '\n' {printf("Completed the expression\n");}
      ;
expr  : expr '+' expr {printf("+ ");}
      | expr '-' expr {printf("- ");}
      | expr '*' expr {printf("* ");}
      | expr '/' expr {printf("/ ");}
      | '(' expr ')'
      | DIGIT {printf("%d ",$1);}
      ;
%%

void yyerror(char *s)
{
    printf("yyerror %s\n",s);
}

int yylex()
{
    int c;
    c=getchar();
    if(isdigit(c))
    {
        yylval = c-'0';
        return DIGIT;
    }
    return c;
}

int main()
{
    yyparse();
    return 1;
}
