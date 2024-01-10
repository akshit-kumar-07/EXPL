%{
#include <stdio.h>
#include <stdlib.h>
%}

upl [A-Z]
lol [a-z]
upa [A]
%%
{upa}{upl|lol}{upl|lol} printf("Matching string found: %s\n",yytext);
%%

