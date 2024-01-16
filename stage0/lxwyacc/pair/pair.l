%{
#include "pair.tab.h"
#include <stdlib.h>
#include <stdio.h>
%}

%%
[0-9]+ {
        yylval=atoi(yytext);
        return DIGIT;
       }
. return *yytext;
%%

int yywrap()
{
    return 1;
}
