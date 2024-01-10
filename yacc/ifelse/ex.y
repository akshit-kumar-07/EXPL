%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int nesting_level = 0;

%}

%token IF ELSE IDENTIFIER DIGIT

%left AND OR
%left '<' '>' EQ NE LE GE

%%
start : program '\n'  {printf("\nParsing complete\n"); exit(0);}
 ;

program: /* empty */
       | statement program
 ;

statement: if_statement
        | IDENTIFIER   { /* process identifier if needed */ }
        | DIGIT   { printf("Digit: %d ", $1); }
 ;

if_statement: IF '(' condition ')' '{' program '}' ELSE '{' program '}'
{
    nesting_level++;
    printf("Nested IF statement at level %d\n", nesting_level);
    nesting_level--;
}
 ;

condition: expression
        | condition AND condition { printf("AND "); }
        | condition OR condition  { printf("OR "); }
        | '(' condition ')' { /* handle parentheses */ }
        | expression EQ expression { printf("Equal "); }
        | expression NE expression { printf("Not Equal "); }
        | expression '<' expression { printf("Less Than "); }
        | expression '>' expression { printf("Greater Than "); }
        | expression LE expression { printf("Less Than or Equal "); }
        | expression GE expression { printf("Greater Than or Equal "); }
 ;

expression: IDENTIFIER { printf("Identifier: %c ", $1); }
        | DIGIT   { printf("Digit: %d ", $1); }
 ;

%%

void yyerror(char *s)
{
    fprintf(stderr, "Error: %s\n", s);
}

int yylex(void)
{
    int c;
    while ((c = getchar()) == ' ' || c == '\t')
        ; // skip whitespace

    if (c == '\n' || c == EOF)
        return 0; // End of input

    if (c == 'i' && (c = getchar()) == 'f') {
        return IF;
    }

    if (c == 'e' && (c = getchar()) == 'l' && (c = getchar()) == 's' && (c = getchar()) == 'e') {
        return ELSE;
    }

    if (isalpha(c)) {
        ungetc(c, stdin);
        yylval = c;
        return IDENTIFIER;
    }

    if (isdigit(c)) {
        ungetc(c, stdin);
        fscanf(stdin, "%d", &yylval);
        return DIGIT;
    }

    return c;
}

int main(void)
{
    yyparse();
    return 0;
}

