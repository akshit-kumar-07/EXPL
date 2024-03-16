lex ltranslate.l

gcc lex.yy.c -o linker -lfl

./linker

cd ..

./xsm -l library.lib -e s7/machinecode.xsm
