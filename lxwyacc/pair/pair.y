%{
#include <stdio.h>
#include <stdlib.h>
int yyerror();
%}

%token DIGIT

%%
start : pair '\n' 
      {printf("\nCompleted\n");}
      ;

pair : num ',' num
     {printf("pair(%d %d)",$1,$3);}
     ;

num : DIGIT 
    {$$ =$1;}
    ;
%%

int yyerror()
{
    printf("synatx error\n");
    return 1;
}

int main()
{
    yyparse();
    return 0;
}
