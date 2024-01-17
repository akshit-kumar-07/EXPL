%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "init.c"
    #include "exprtree.c"
    #include "codegen.c"
    int yylex();
    int yyerror();
    void print();
    FILE *fp;
    FILE *target_file;
    extern FILE *yyin;
%}

%union
{
    struct tnode *node;
};

%token START END READ WRITE PLUS MINUS MUL DIV ASSIGN NUM ID
%left PLUS MINUS
%left MUL DIV

%type <node> NUM ID START END READ WRITE PLUS MINUS MUL DIV ASSIGN
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt expr

%%
program : START Slist END ';'
        {
            $$=$3;
            init();
            codegen($2);
            print();
            fclose(target_file);
            exit(0);
        }
        | START END ';'
        ;
Slist   : Slist Stmt
        {
            $$=createNode(1,0,NODE_CONN,NULL,$1,$2);
        }
        | Stmt { $$=$1;}
Stmt    : InputStmt { $$=$1;}
        | OutputStmt { $$=$1;}
        | AsgStmt { $$=$1;}
        ;
InputStmt: READ '(' ID ')' ';'  {$$ = createNode(1, 0, NODE_READ, NULL, $3, NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';' {$$ = createNode(1, 0, NODE_WRITE, NULL, $3, NULL);}
          ;

AsgStmt: ID ASSIGN expr ';'      {$$ = createNode(1, 0, NODE_ASSIGN, NULL, $1, $3);}
       ;

expr : expr PLUS expr	{$$ = createNode(1, 0, NODE_PLUS, NULL, $1, $3);}
     | expr MINUS expr  {$$ = createNode(1, 0, NODE_MINUS, NULL, $1, $3);}
     | expr MUL expr	{$$ = createNode(1, 0, NODE_MUL, NULL, $1, $3);}
     | expr DIV expr	{$$ = createNode(1, 0, NODE_DIV, NULL, $1, $3);}
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | ID		{$$ = $1;}
     ;

%%

yyerror(char const *s) {
    printf("yyerror %s",s);
}

void print()
{
    fprintf(target_file, "MOV R2, \"Exit\"\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "PUSH R2\n");
    fprintf(target_file, "CALL 0\n");
    exit(0);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an input filename\n");
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Invalid input file specified\n");
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
