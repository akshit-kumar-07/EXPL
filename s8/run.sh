flex exprtree.l
bison -d exprtree.y
gcc lex.yy.c exprtree.tab.c -o compiler
