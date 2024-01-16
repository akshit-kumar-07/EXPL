%{
#include <stdio.h>
#include <stdlib.h>
%}

single_line "\\"
multi_line_start "/*"
multi_line_end "*/"
newline "\n"

%%
{single_line}(.)*{newline} printf("%s\n",yytext);
{multi_line_start}(.)*{multi_line_end} printf("%s\n",yytext);
. ;
%%
