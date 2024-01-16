%{
#include <stdio.h>
#include <stdlib.h>
int lines=0;
int words=0;
int chr=0;
%}

%%
[a-zA-Z]+ { words++; chr+=strlen(yytext);}
"\n" { chr++; lines++; }
. { chr++;}
%%

int main()
{
    yylex();
    printf("The number of lines, words and characters are %d, %d and %d respectively\n",lines,words,chr);
    return 0;
}
