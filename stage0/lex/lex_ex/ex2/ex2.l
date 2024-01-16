%{
#include <stdio.h>
#include <stdlib.h>
%}

number [0-9]
point .

%%
{number}+ printf("the number of integral digits are %d\n",yyleng);
{point}{number}+ printf("The number of decimal digits are %d\n",yyleng-1);
%%


