%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "exprtree.h"
int yywrap();
int num;
char *var;
%}

%%
"begin" { return BEGIN;}
"end" { return END;}
"read" { return READ;}
"write" { return WRITE;}
"+" { return PLUS;}
"-" { return MINUS;}
"*" { return MUL;}
"/" { return DIV;}
"=" { return ASSIGN;}
[ \t\n] {}
[();] { return *yytext;}
[0-9]+ {
        num=atoi(yytext);
        yylval.node=createTree(num,0,NODE_NUM,NULL,NULL,NULL);
        return NUM;
       }
[a-z]  {
        var=(char *)malloc(sizeof(char));
        strcpy(var,yytext);
        yylval.node=createTree(0,1,var,NODE_VAR,NULL,NULL);
       }
. { yyerror("Unknow Character"); exit(1);}
%%

int yywrap()
{
    return 1;
}
