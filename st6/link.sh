lex ltranslate.l

gcc lex.yy.c -o linker -lfl

./linker

cd ..

./xsm -l library.lib -e st6/machinecode.xsm
