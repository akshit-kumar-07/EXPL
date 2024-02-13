

# Run flex on linker.l
flex ltranslate.l

# Compile lex.yy.c with gcc and link against libfl
gcc lex.yy.c -o linker -lfl

# Run the compiled linker
./linker

# Move back to the parent directory
cd ..

# Run xsm with the specified arguments
./xsm -l library.lib -e st5/machinecode.xsm

