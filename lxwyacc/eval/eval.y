%{
#include <stdio.h>
#include <stdlib.h>
int yyerror();
%}

%token DIGIT
%left '+' '-'
%left '*'
%left '\\'

%%
start : expr ';' 
      {printf("The value of the evaluated expression is : %d\n",$1); exit(0); }
      ;

expr  : expr '+' expr 
      {$$=$1+$3;}
      | expr '-' expr
      {$$=$1-$3;}
      | expr '*' expr
      {$$=$1*$3;}
      | expr '\\' expr
      {$$=$1\$3;}
      | '(' expr ')'
      {$$=$2;}
      | DIGIT 
      {$$=$1;}
      ;
%%

int yyerror(char *s)
{
    printf("Error %s\n",s);
}

int main()
{
    yyparse();
    return 1;
}
