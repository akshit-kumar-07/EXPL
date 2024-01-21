%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "exprtree.h"
    #include "parser.tab.h"
    int yywrap();
    int num;
    char *var;
%}

%%
[0-9]+ {
    num=atoi(yytext);
    yylval.node=createNode(0,num,NODE_NUM,NULL,NULL,NULL);
    return NUM;
}

[a-z] {
    var=(char *)malloc(sizeof(yytext));
    strcpy(var,yytext);
    yylval.node=createNode(1,0,NODE_ID,var,NULL,NULL);
    return ID;
}

"begin" { return START;}
"end" { return END;}
"read" { return READ;}
"write" { return WRITE;}
"+" { return PLUS;}
"-" { return MINUS;}
"*" { return MUL;}
"/" { return DIV;}
"=" { return ASSIGN;}
[();] { return *yytext;}
[ \n\t] {}
. {
    yyerror("unknown character encountered\n");
    exit(1);
}
%%

int yywrap()
{
    return 1;
}