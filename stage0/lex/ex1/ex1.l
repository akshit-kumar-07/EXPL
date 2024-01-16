%{
    #include <stdio.h>
%}

number [0-9]+
op [-+*/^=]

%%
{number} printf("Number\n");
{op} printf("Operator\n");
%%

