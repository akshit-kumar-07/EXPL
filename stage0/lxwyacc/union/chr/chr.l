%{
#include <stdio.h>
#include <stdlib.h>
#include "chr.tab.h"
int yywrap();
char buff;
%}

%%
[A-Za-z] { buff=*yytext; yylval.ch=buff; return LETTER; }
.   return *yytext;
%%

int yywrap()
{
    return 1;
}
