lex exprtree.l

yacc -d exprtree.y

gcc lex.yy.c y.tab.c -o compiler
 
