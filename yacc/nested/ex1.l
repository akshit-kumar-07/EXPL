%{
#include <stdio.h>
#include <stdlib.h>
#include "ex1.tab.h"
%}

IF "if"
THEN "then"
ELSE "else"
ENDIF "endif"

%%
{IF} return IF;
{THEN} return THEN;
{ELSE} return ELSE;
{ENDIF} return ENDIF;
";" return ';';
"(" return '(';
")" return ')';
%%


