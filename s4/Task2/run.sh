flex lexer.l
bison -d parser.y
gcc -g lex.yy.c parser.tab.c -o task2

