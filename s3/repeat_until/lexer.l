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
    yylval.node=createNode(INT,num,NODE_NUM,NULL,NULL,NULL,NULL);
    return NUM;
}

[a-z] {
    var=(char *)malloc(sizeof(yytext));
    strcpy(var,yytext);
    yylval.node=createNode(INT,0,NODE_ID,var,NULL,NULL,NULL);
    return ID;
}

"begin" { return START;}
"end" { return END;}
"read" { return READ;}
"write" { return WRITE;}
"if" { return IF;}
"then" { return THEN;}
"else" { return ELSE;}
"endif" { return ENDIF;}
"while" { return WHILE;}
"do" { return DO;}
"endwhile" { return ENDWHILE;}
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
"=" { return ASSIGN;}
[();] { return *yytext;}
[ \n\t] {}
. {
    fprintf(stderr,"unknown character encountered %s\n",yytext);
    exit(1);
}
%%

int yywrap()
{
    return 1;
}
