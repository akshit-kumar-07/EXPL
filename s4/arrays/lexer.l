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

id [a-zA-Z_][a-zA-Z0-9_]*
str \"(\\.|[^\\\"])*\"

%%
[0-9]+ {
    num=atoi(yytext);
    yylval.node=createNode(TYPE_INT,num,NODE_NUM,NULL,NULL,NULL,NULL);
    return NUM;
}
"begin" { return START;}
"end" { return END;}
"decl" { return DECL;}
"enddecl" { return ENDDECL;}
"int" { return INT;}
"str" { return STR;}
"read" { return READ;}
"write" { return WRITE;}
"if" { return IF;}
"then" { return THEN;}
"else" { return ELSE;}
"endif" { return ENDIF;}
"while" { return WHILE;}
"do" { return DO;}
"endwhile" { return ENDWHILE;}
"enddowhile" { return ENDDOWHILE;}
"repeat" { return REPEAT;}
"until" { return UNTIL;}
"endrepeat" { return ENDREPEAT;}
"break" { return BREAK;}
"continue" { return CONTINUE;}
">" { return GT;}
"<" { return LT;}
">=" { return GE;}
"<=" { return LE;}
"==" { return EQ;}
"!=" { return NEQ;}
"+" { return PLUS;}
"-" { return MINUS;}
"*" { return MUL;}
"/" { return DIV;}
"%" { return MOD;}
"=" { return ASSIGN;}
[();,\[\]] { return *yytext;}
[ \n\t] {}
{id} {
    var=(char *)malloc(sizeof(yytext));
    strcpy(var,yytext);
    yylval.node=createNode(TYPE_INT,0,NODE_ID,var,NULL,NULL,NULL);
    return ID;
}
{str} {
    var=(char *)malloc(sizeof(yytext));
    strcpy(var,yytext);
    yylval.node=createNode(TYPE_STR,0,NODE_STRVAL,var,NULL,NULL,NULL);
    return STRVAL;
}
. {
    fprintf(stderr,"unknown character encountered %s\n",yytext);
    exit(1);
}
%%

int yywrap()
{
    return 1;
}
