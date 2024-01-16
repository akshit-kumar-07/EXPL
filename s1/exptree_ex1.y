%{
#include <stdio.h>
#include <stdlib.h>
#include "exptree.h"
#include "exptree.c"
#include "codegen.c"
int yylex();
int yyerror();
%}

%union
{
    struct tnode *no;
};

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%
program : expr END
        {
            $$=$2;
            printf("The prefix expression is:");prefix($1);
            printf("\nThe postfix expression is:");postfix($1);
            printf("\nThe evaluated value is %d\n",evaluate($1));
            exit(0);
        }
        ;

expr : expr PLUS expr  {$$ = makeOperatorNode('+',$1,$3);}
  | expr MINUS expr   {$$ = makeOperatorNode('-',$1,$3);}
  | expr MUL expr {$$ = makeOperatorNode('*',$1,$3);}
  | expr DIV expr {$$ = makeOperatorNode('/',$1,$3);}
  | '(' expr ')'  {$$ = $2;}
  | NUM   {$$ = $1;}
  ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 1;
}


int main(void) {
FILE *fp=fopen("target_file.xsm","w");
 yyparse();
 return 0;
}
