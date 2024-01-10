%{
#include <stdio.h>
#include <stdlib.h>
%}

number [0-9]+

%%
{number} { if(atoi(yytext)%2==0) printf("Number found is even\n"); 
            else printf("Number found is odd\n"); }
%%
