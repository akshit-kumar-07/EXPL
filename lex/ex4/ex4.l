%{
#include <stdio.h>
#include <stdlib.h>
char *file1;
%}

number [0-9]+

%%
{number} printf("Number found is %d\n",atoi(yytext));
%%

int yywrap()
{
    FILE *newfile_pointer;
    char *file2="input_file_2.l"; //open the new file
    newfile_pointer=fopen("input_file_2.l","r"); //pointer to the new file
    if(strcmp(file1,file2)!=0) //check to see whether the file transition hasn't been done yet
    {
        file1=file2; //if first transition, then change
        yyin=newfile_pointer;
        return 0;
    }
    else //file transition already performed once hence file1==file2
        return 1; //end the yylex() function i.e. input is over now
}

int main()
{
    file1="input_file.l";
    yyin=fopen("input_file.l","r");
    yylex();
    return 1;
}
