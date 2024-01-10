%{
#include <stdio.h>
#include <stdlib.h>
char *file1;
%}

number [0-9]+

%%
{number} printf("The number found is %d\n",atoi(yytext));
%%

int yywrap()
{
    FILE *newfile_pointer;
    char *file2="input_file_2.l";
    newfile_pointer=fopen("input_file_2.l","r");
    if(strcmp(file1,file2)!=0) //check whether the file transition has been done or not
    {
        file1=file2; //make sure that transition is done only once;
        yyin=newfile_pointer;
        return 0; //signals that further input is there
    }
    else //transition is already over
        return 1; //signals that the input is over
}

int main()
{
    file1="input_file.l";
    yyin=fopen("input_file.l","r");
    yylex();
    return 0;
}
