%{
#include <stdio.h>
%}

number [0-9]+
point [.]

%%
{number} printf("The number of digits before the decimal point is %d\n",strlen(yytext));
{point}{number} printf("The number of digits after the decimal point is %d\n",strlen(yytext)-1);
%%
