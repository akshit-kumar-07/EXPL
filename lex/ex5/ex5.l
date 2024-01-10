%{
#include<stdio.h>
#include <stdlib.h>
char *file1;
%}

number [0-9]+

%%
{number} printf("the number found is %d\n",atoi(yytext));
%%

int yywrap()
{
    FILE *newfp; //define the new file pointer
    char *file2="input_file.l";
    if(yyin != NULL)
    	fclose(yyin);
    newfp=fopen("input_file.l","r"); //open the new file
    if(strcmp(file1,file2)!=0) //checks for the transition count and constraints it to 1
    {
        file1=file2; //transition over
        yyin=newfp; //open the new file for reading the input
        return 0; //signals to yylex() that there is further input left;
    }
    else //transition is already over
        return 1; //no further input 
}

int main()
{
    file1="/dev/tty";
    yyin=fopen("/dev/tty","r");
    yylex();
    return 0;
}
