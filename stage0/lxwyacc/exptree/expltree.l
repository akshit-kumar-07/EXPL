%{
 #include <stdlib.h>
 #include <stdio.h>
 #include "exprtree.tab.h"
 #include "exprtree.h"

 int number;

%}

%%

[0-9]+ {number = atoi(yytext); yylval.no = makeLeafNode(number); return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
[ \t] {}
[()] {return *yytext;}
[\n] {return END;}
. {exit(1);}

%%

int yywrap(void) {
 return 1;
}
