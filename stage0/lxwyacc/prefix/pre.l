%option noyywrap
%{
    #include "pre.tab.h"
    #include<string.h>
%}

op [*+-/()]
var [a-zA-Z]+

%%

{op} {yylval.str=strdup(yytext);return yytext[0];}
{var} {yylval.str=strdup(yytext);return VAR;}
\n {return NL;}

%%
