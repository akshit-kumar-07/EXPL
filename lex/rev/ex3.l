%{
#include <stdio.h>
%}

letter [a-zA-Z]

%%
{letter}+ { char* word=yytext;
            if(strlen(word)==3 && word[0]=='A')
                printf("Found a matching word : %s\n", word);
        }
. ;
%%
