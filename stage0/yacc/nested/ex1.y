%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int level=0;
%}

%token IF THEN ELSE ENDIF

%%
stmt : IF '(' cond ')' THEN {level++;} 
     stmt {level--;}
     ELSE {level++;}
     stmt {level--;}
     ENDIF {printf("The number of nesting levels are : %d\n",level);}
     | IF '(' cond ')' THEN {level++;}
     stmt {level--;}
     | TER
%%

void yyerror(char *s)
{
    printf("yyerror %s\n",s);
}

int main()
{
    yyparse();
    return 0;
}
