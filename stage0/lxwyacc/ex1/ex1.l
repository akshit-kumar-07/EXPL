%{
#include "ex1.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]+ {
            yylval=atoi(yytext);
            return DIGIT;
        }
"+" return *yytext;
"-" return *yytext;
[()] return *yytext;
[\n] return NEWLINE;
%%

int yywrap()
{
    return 1;
}
