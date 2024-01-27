%{
#include <stdio.h>
#include <stdlib.h>
#include "linker.c"
int pass=0; 
int base=2048;
int offset=0;
char *label_name;
FILE *target_file;
%}

id [a-zA-Z0-9]+

%%
\".*\" { if(pass) fprintf(target_file,"%s",yytext);}

{id}:    {
    //This is for labels like L0,L1,etc..
    if(pass)
        offset=1; //consume the extra newline character after L0:\n

    else
    {
        label_name=(char*)malloc(sizeof(yyleng-1)); 

        yyless(yyleng-1); //this ensures lex only reads the first yyleng-1 characters and the trailing colon gets left out

        strcpy(label_name,yytext); //only the yyleng-1 characters from id

        insert_begin(label_name,base);

        base-=2; //each instruction takes two words

        /* We need to remeber that in the label code we assign each label to a sepaarete line and therefore when that label is replaced that line must be compesated again */
    }}

"CALL 0"   { if(pass) fprintf(target_file,"%s",yytext);}


"CALL "{id} { if(pass) fprintf(target_file,"CALL %d",list_search(yytext+5));}


"JMP "{id} { if(pass) fprintf(target_file,"JMP %d",list_search(yytext+4));}


"JNZ R"[0-9]+[,]{id} { if(pass){
    //We look at two cases, when reg numbers are single digit or double digit

    if(yytext[6]==','){ //single digit reg
        fprintf(target_file,"JNZ R%c,%d",yytext[5],list_search(yytext+7));
}
    else{
        fprintf(target_file,"JNZ R%c%c,%d",yytext[5],yytext[6],list_search(yytext+8));
        }
}}


"JZ R"[0-9]+[,]{id} { if(pass){

    //We look at two cases, when reg numbers are single digit or double digit
    if(yytext[5]==','){ //single digit reg
        fprintf(target_file,"JZ R%c,%d",yytext[4],list_search(yytext+6));
}
    else{
        fprintf(target_file,"JZ R%c%c,%d",yytext[4],yytext[5],list_search(yytext+7));
       	}
}}

\n  {
        if(pass)
        {
            if(offset) //already a newline has been consumed by label defintions
                offset=0;
            else
                fprintf(target_file,"\n");
        }
        else
        {
            if(base<2056)
                base++;
            else
                base+=2;
        }
}

.       { if(pass) fprintf(target_file,"%s",yytext);}

%%


int yywrap()
{
    if(pass==0)
    {
        //open up the code with labels
        pass=1;
        yyin=fopen("label_code.xsm","r");
        target_file=fopen("target_file.xsm","w");
        return 0;
    }
    return 1;
}

int main()
{
    yyin=fopen("label_code.xsm","r");
    yylex();
    return 0;
}
