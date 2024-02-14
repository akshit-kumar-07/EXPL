%{
    #include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
    #include "symboltable.h"
	#include "ast.c"
    #include "symboltable.c"
    #include "initialize.c"
    #include "typecheck.h"
    #include "typecheck.c"
    #include "codegen.c"

	int yylex(void);
    extern FILE *yyin;
    extern int lineno;
    FILE *fp;
    FILE *intermediate;
    void print(int);
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0; // Definition and Declaration count of functions
    int testing = 0; // can use to test ASTree
%}

%union
{
    struct ASTNode *nptr;
}

%token START END READ WRITE PLUS MINUS MUL DIV MOD ASSGN NUM ID
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT GT AND OR
%token BREAK CONT DECL ENDDECL INT STR STRVAL MAIN RETURN

%nonassoc LT GT LE GE
%right EQ NEQ
%left PLUS MINUS
%left MUL DIV MOD
%right ASSGN

%type <nptr> NUM ID START END READ WRITE PLUS MINUS MUL DIV ASSGN AND OR
%type <nptr> IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT
%type <nptr> GT BREAK CONT DECL ENDDECL INT STR STRVAL MOD MAIN RETURN
%type <nptr> program Slist Stmt InputStmt OutputStmt AsgStmt expr id
%type <nptr> BrkStmt ContStmt IfStmt WhileStmt Type GDeclBlock FDefBlock
%type <nptr> MainBlock GDeclList GDecl GIdList GId ParamList FDef
%type <nptr> LDeclBlock Body Param LDecList LDecl IdList RetStmt
%type <nptr> ExprList func

%%

program : GDeclBlock FDefBlock MainBlock {fclose(intermediate);}
        | GDeclBlock MainBlock {fclose(intermediate);}
        | MainBlock {fclose(intermediate);}
        ;

GDeclBlock : DECL GDeclList ENDDECL {initialize();}
            | DECL ENDDECL {initialize();}
            ;

GDeclList : GDeclList GDecl
          | GDecl
          ;

GDecl : Type GIdList ';'
      ;

Type : INT { declarationType = TYPE_INT;}
     | STR { declarationType = TYPE_STR;}
     ;

FType : INT { FDeclarationType = TYPE_INT;}
      | STR { FDeclarationType = TYPE_STR;}
      ;

GIdList : GIdList ',' GId
        | GId
        ;

GId : ID '(' ParamList ')'
    {
        declCount++; //keeps track of the number of functions declared
        checkAvailability($1->name,1); //check if the name is valid in the global scope
        GInstall($1->name, declarationType, -1, Phead);
        Phead = NULL;
        Ptail = NULL;
    }
    | ID
    {
        checkAvailability($1->name,1); //check availability in glbl scope
        GInstall($1->name, declarationType, 1, NULL);
    }
    | ID '[' NUM ']'
    {
        checkAvailability($1->name, 1);
        if($3->value.intval < 1)
        {
            yyerror("Invalid array size\n", NULL);
            exit(1);
        }
        GInstall($1->name, declarationType, $3->value.intval, NULL);
    }
    ;

FDefBlock : FDefBlock FDef
          | FDef
          ;

FDef : Type ID '(' ParamList ')' '{' LDeclBlock Body '}'
     {
        defCount++; //count the number of functions defined
        Gtemp = GLookup($2->name);

        //Check if function is declared

        if(Gtemp == NULL)
        {
            yyerror("Function %s is not declared\n", $2->name);
            exit(1);
        }

        //type check the function

        if(Gtemp->type != declarationType)
        {
            yyerror("%s : Function type does not match declaration", $2->name);
            exit(1);
        }

        //Check for parameters and arguments
        argList1 = Phead; //defined parameters
        argList2 = Gtemp->paramlist; //declared parameters

        //check for type compatibility
        while(argList1 != NULL && argList2 != NULL)
        {
            if(argList1->type != argList2->type)
            {
                yyerror("%s : Conflict in argument type for the function", $2->name);
                exit(1);
            }


            if(strcmp(argList1->name,argList2->name)!=0)
            {
                yyerror("%s : Conflict in argument names\n", $2->name);
                exit(1);
            }

            argList1 = argList1->next;
            argList2 = argList2->next;
       }
        if((argList1 != NULL ) || (argList2 != NULL))
        {
            yyerror("%s : Insufficient arguments ", $2->name);
            exit(1);
        }

        if(testing)
        {
            printLSymbolTable();
        }

        else
        {
            fprintf(intermediate, "F%d:\n",Gtemp->flabel);
            fprintf(intermediate, "PUSH BP\n");
            fprintf(intermediate, "MOV BP,SP\n");

            Ltemp = Lhead;
            while(Ltemp != NULL)
            {
                if(Ltemp->binding > 0)
                    fprintf(intermediate,"PUSH R0\n");
                Ltemp = Ltemp->next;
            }
            codegen($8);
        }

        Phead = NULL;
        Ptail = NULL;
        Lhead = NULL;
        Ltail = NULL;
     }
     ;

ParamList : ParamList ',' Param
          | Param
          |
          ;

Param : FType ID
      {
            checkAvailability($2->name, 0);
            PInstall($2->name, FDeclarationType);
      }
      ;

MainBlock : Type MAIN '(' ')' '{' LDeclBlock Body '}'
          {
            if(defCount != declCount)
            {
                yyerror("all declared functions must be defined\n");
                exit(1);
            }

            if(declarationType != TYPE_INT)
            {
                yyerror("Main should return a type int value\n");
                exit(1);
            }

            if(testing)
            {
                printGSymbolTable();
                printLSymbolTable();
            }
            else
            {
                fprintf(intermediate, "MAIN:\n");
                fprintf(intermediate, "PUSH BP\n");
                fprintf(intermediate, "MOV BP,SP\n");

                Ltemp = Lhead;
                while(Ltemp != NULL)
                {
                    fprintf(intermediate,"PUSH R0\n");
                    Ltemp = Ltemp->next;
                }

                codegen($7);
            }

            Lhead = NULL;
            Ltail = NULL;
          }

LDeclBlock: DECL LDecList ENDDECL   {InstallParamsInLocal();}
          | DECL ENDDECL            {InstallParamsInLocal();}
          |                         {InstallParamsInLocal();}
          ;

LDecList: LDecList LDecl
        | LDecl
        ;

LDecl: FType IdList ';'
     ;

IdList: IdList ',' IdList
      | ID      {
                    checkAvailability($1->name, 0);
                    LInstall($1->name, FDeclarationType);
                }
      ;

Body: START Slist RetStmt END   {$$ = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, $2, $3, NULL);}
    | START RetStmt END         {$$ = $2;}
    ;

RetStmt: RETURN expr ';'    {
                                if(declarationType == $2->type) {
                                    $$ = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, $2, NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
       ;

Slist: Slist Stmt       {$$ = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, $1, $2, NULL);}
    | Stmt              {$$ = $1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | IfStmt            {$$ = $1;}
    | WhileStmt         {$$ = $1;}
    | BrkStmt           {$$ = $1;}
    | ContStmt          {$$ = $1;}
    | func ';'          {$$ = $1;}
    ;

IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'     {
                                                                typecheck($3->type, TYPE_BOOL, 'e');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, $3, $8, $6);
                                                            }
      | IF '(' expr ')' THEN Slist ENDIF ';'                {
                                                                typecheck($3->type, TYPE_BOOL, 'i');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, $3, $6, NULL);
                                                            }
      ;

WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'         {
                                                                typecheck($3->type, TYPE_BOOL, 'w');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, $3, $6, NULL);
                                                            }
         ;
BrkStmt: BREAK ';'                  {$$ = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
       ;

ContStmt: CONT ';'                  {$$ = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
        ;

InputStmt: READ '(' id ')' ';'      {$$ = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, $3, NULL, NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';'  {$$ = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, $3, NULL, NULL);}
          ;

AsgStmt: id ASSGN expr ';'          {
                                        typecheck($1->type, $3->type, '=');
                                        $$ = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, $1, $3, NULL);
                                    }
       ;

ExprList: ExprList ',' expr {
                                $3->arglist = $1;
                                $$ = $3;
                            }
        | expr              {$$ = $1;}
        |                   {$$ = NULL;}
        ;

expr : expr PLUS expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MINUS expr  {
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MUL expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr DIV expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MOD expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr LT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr GT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr LE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr GE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr NEQ expr    {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr EQ expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, $1, $3, NULL);					}
     
     | expr AND expr     {
                            typecheck($1->type, $3->type, 'l');
                            $$ = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, $1, $3, NULL);					}
     
     | expr OR expr     {
                            typecheck($1->type, $3->type, 'l');
                            $$ = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | MINUS NUM        {
                            $2->value.intval = -1*($2->value.intval);
                            $$ = $2;
                        }
     | STRVAL           {$$ = $1;}
     | id		{$$ = $1;}
     | func             {$$ = $1;}
     ;

func: ID '(' ExprList ')'   {
                                if($3->type == TYPE_BOOL)
                                {
                                    yyerror("Type INT Expression expected in function argument in line %d\n",lineno);
                                    exit(1);

                                }
                                assignType($1, 1);
                                $1->nodetype = NODE_FUNC;
                                $1->ptr1 = reverseList($3);
                                $1->ptr3 = (GLookup($1->name))->paramlist;
                                struct ASTNode *args = $1->ptr1;
                                struct Paramstruct *params = $1->ptr3;
                                while(args != NULL && params != NULL)
                                {
                                    if(args->type != params->type)
                                    {
                                        yyerror("Type mismatch\n");
                                        exit(1);
                                    }
                                    args = args->arglist;
                                    params = params->next;
                                }
                                if(args != NULL || params != NULL)
                                {
                                    yyerror("Incorrect number of arguments on function invocation\n");
                                    exit(1);
                                }
                                $$ = $1;
                            }

id: ID                  {
                            assignType($1, 0);
                            $$ = $1;
                        }
  | ID '[' NUM ']'      {
                            assignType($1, 2);
                            $$ = TreeCreate($1->type, NODE_ARRAY, NULL, NULL, NULL, $1, $3, NULL);
                        }
  | ID '[' id ']'       {
                            assignType($1, 2);
                            $$ = TreeCreate($1->type, NODE_ARRAY, NULL, NULL, NULL, $1, $3, NULL);
                        }
  | ID '[' expr ']'
    {
        if($3->type!=TYPE_INT)
        {
        	fprintf(stderr,"Expected an arithmetic expression in the index for array %s\n",$1->name);
        	exit(1);
        }
        assignType($1, 2);
        $$ = TreeCreate($1->type, NODE_ARRAY, NULL, NULL, NULL, $1, $3, NULL);
       }
  ;

%%


void typecheck_runtime(struct ASTNode *t)
{
    struct ASTNode *head = t;
    int count =0;
    while(t!= NULL)
    {
                if(t->type != GLookup(t->name)->type)
                {
                    yyerror("Error in typechecking runtime of function %d\n",lineno);
                    exit(1);
                }
                t = t->arglist;
    }
}

yyerror(char const *s, char const *var) {
    printf("\033[0;31mERR:%d\033[0m : ", lineno);
    printf(s, var);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        yyerror("Please provide an input filename\n", NULL);
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            yyerror("Invalid input file specified\n", NULL);
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
