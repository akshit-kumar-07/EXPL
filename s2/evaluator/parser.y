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
    int evaluate();
    int vars[26];
    int result=0;
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
            evaluate($2);
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

int evaluate(struct tnode *t)
{
    int ind=0;int x=0;
    if(t==NULL) return 0;
    else if(t->nodetype==NODE_CONN)
    {
        evaluate(t->left);
        evaluate(t->right);
    }
    switch(t->nodetype)
    {
        case NODE_PLUS:
            return evaluate(t->left)+evaluate(t->right);
        case NODE_MINUS:
            return evaluate(t->left)-evaluate(t->right);
        case NODE_MUL:
            return evaluate(t->left)*evaluate(t->right);
        case NODE_DIV:
            return evaluate(t->left)/evaluate(t->right);
        case NODE_NUM:
            return t->val;
        case NODE_ID:
            return vars[t->varname[0]-'a'];
        case NODE_READ:
            ind=t->left->varname[0]-'a';
            scanf("%d",&x);
            vars[ind]=x;
            break;
        case NODE_WRITE:
            x=evaluate(t->left);
            printf("%d\n",x);
            break;
        case NODE_ASSIGN:
            ind=t->left->varname[0]-'a';
            x=evaluate(t->right);
            vars[ind]=x;
            return 0;
        default:
            break;
    }
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
