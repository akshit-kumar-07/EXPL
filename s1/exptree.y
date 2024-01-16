%{
#include <stdio.h>
#include <stdlib.h>
#include "exptree.h"
#include "exptree.c"
#include "codegen.c"
int yylex();
int yyerror();
void print(int);
FILE *fp;
FILE *target_file;
extern FILE *yyin;
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
            int r=codeGen($1);
            print(r);
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

void print(int r) {
    fprintf(target_file, "MOV R2, \"Write\"\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "MOV R2, -1\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R%d\n", r);
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "CALL 0\n");
    fprintf(target_file, "POP R0\n");
    fprintf(target_file, "POP R1\n");
    fprintf(target_file, "POP R1\n");
    fprintf(target_file, "POP R1\n");
    fprintf(target_file, "POP R1\n");
    fprintf(target_file, "MOV R2, \"Exit\"\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "CALL 0\n");
    exit(0);
}

int main(int argc,char *argv[])
{
	if(argc<2)
		exit(1);
	else
	{
		target_file=fopen("target_file.xsm","w");
		fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
		fp=fopen(argv[1],"r");
		yyin=fp;
	}
	yyparse();
	return 0;
}
