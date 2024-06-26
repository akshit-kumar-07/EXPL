%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "init.c"
    #include "exprtree.c"
    #include "evaluator.c"
    int vars[26];
    int result;
    int yylex();
    int evaluate();
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

%token START END READ WRITE PLUS MINUS MUL DIV ASSIGN NUM ID IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE LT GT EQ NEQ LE GE
%left PLUS MINUS
%left MUL DIV

%type <node> NUM ID START END READ WRITE PLUS MINUS MUL DIV ASSIGN IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE LT GT EQ NEQ LE GE
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt expr BreakStmt ContStmt IfStmt WhileStmt

%%
program : START Slist END ';'
        {
            $$=$3;
            init();
            evaluate($2);
            print();
            fclose(target_file);
            exit(0);
        }
        | START END ';'
        ;
Slist   : Slist Stmt
        {
            $$=createNode(VOID,0,NODE_CONN,NULL,$1,$2,NULL);
        }
        | Stmt { $$=$1;}
        ;
Stmt    : InputStmt { $$=$1;}
        | OutputStmt { $$=$1;}
        | AsgStmt { $$=$1;}
        | IfStmt { $$=$1;}
        | WhileStmt { $$=$1;}
        | BreakStmt { $$=$1;}
        | ContStmt { $$=$1;}
        ;
InputStmt: READ '(' ID ')' ';'  {$$ = createNode(VOID, 0, NODE_READ, NULL, $3, NULL,NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';' {$$ = createNode(VOID, 0, NODE_WRITE, NULL, $3, NULL, NULL);}
          ;

AsgStmt: ID ASSIGN expr ';'      {$$ = createNode(VOID, 0, NODE_ASSIGN, NULL, $1, $3, NULL);}
       ;

IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';' {  $$=createNode(VOID,0,NODE_IF_ELSE,NULL,$3,$8,$6);}
      | IF '(' expr ')' THEN Slist ENDIF ';' {  $$=createNode(VOID,0,NODE_IF,NULL,$3,$6,NULL);}
      ;

WhileStmt : WHILE '(' expr ')' DO Slist ENDWHILE';' { $$=createNode(VOID, 0, NODE_WHILE,NULL,$3,$6,NULL);}
          ;

BreakStmt: BREAK ';' { $$=createNode(VOID, 0, NODE_BREAK,NULL,NULL,NULL,NULL);}
        ;

ContStmt : CONTINUE ';' { $$=createNode(VOID,0,NODE_CONTINUE,NULL,NULL,NULL,NULL);}

ContStmt : CONTINUE

expr : expr PLUS expr	{  $$ = createNode(INT, 0, NODE_PLUS, NULL, $1, $3, NULL);}
     | expr MINUS expr  {  $$ = createNode(INT, 0, NODE_MINUS, NULL, $1, $3, NULL);}
     | expr MUL expr	{  $$ = createNode(INT, 0, NODE_MUL, NULL, $1, $3, NULL);}
     | expr DIV expr	{  $$ = createNode(INT, 0, NODE_DIV, NULL, $1, $3, NULL);}
     | expr LT expr     {  $$ = createNode(BOOL,0, NODE_LT, NULL, $1, $3, NULL);}
     | expr GT expr     {  $$ = createNode(BOOL,0, NODE_GT, NULL, $1, $3, NULL);}
     | expr LE expr     {  $$ = createNode(BOOL,0, NODE_LE, NULL, $1, $3, NULL);}
     | expr GE expr     {  $$ = createNode(BOOL,0, NODE_GE, NULL, $1, $3, NULL);}
     | expr EQ expr     {  $$ = createNode(BOOL,0, NODE_EQ, NULL, $1, $3, NULL);}
     | expr NEQ expr    {  $$ = createNode(BOOL,0, NODE_NEQ, NULL, $1, $3, NULL);}
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | ID		{$$ = $1;}
     ;

%%

int yyerror(char const *s) 
{
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
