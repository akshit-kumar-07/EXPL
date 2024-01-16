%{
#include <stdio.h>
#include <stdlib.h>
char *file1;
%}

number [0-9]+

%%
{number} printf("found the number %d\n",atoi(yytext));
%%

int yywrap()
{
    FILE *new_fp;
    char *file2="/dev/tty";
    new_fp=fopen("/dev/tty","r");
    if(strcmp(file1,file2) !=0)
    {
        file1=file2;
        yyin=new_fp;
        return 0;
    }
    else
        return 1;
}

int main()
{
    file1="input_file.l";
    yyin=fopen("input_file.l","r");
    yylex();
    return 1;
}
