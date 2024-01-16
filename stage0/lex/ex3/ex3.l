%{
#include <stdio.h>
#include <stdlib.h>
%}
%option noyywrap
number [0-9]+

%%
{number} return atoi(yytext);
%%

int main()
{
    int num=yylex();
    printf("Found the number %d\n",num);
    return 0;
}
