lex ltranslate.l

gcc lex.yy.c -o linker -lfl

./linker

cd ..

./xsm -l library.lib -e Stage7/machinecode.xsm
