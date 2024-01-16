%{
#include <stdio.h>
#include <stdlib.h>
#include "exptree.tab.h"
#include "exptree.h"
int number;
int yywrap();
%}

%%
[0-9]+ { number=atoi(yytext); yylval.no=makeLeafNode(number); return NUM;}
"+" { return PLUS;}
"-" { return MINUS;}
"*" { return MUL;}
"/" { return DIV;}
[ \t] {}
[()] { return *yytext;}
[\n] { return END;}
. { yyerror("Unknown character\n"); exit(1);}
%%

int yywrap()
{
    return 1;
}
