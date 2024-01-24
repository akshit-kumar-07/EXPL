#!/bin/bash

# Exit immediately if any command exits with a non-zero status
set -e

# Exit if any command in a pipeline fails
set -o pipefail

# Navigate to the directory
cd ~/xsm_expl/s3/repeat_until



# Run flex on lexer.l
flex lexer.l 

# Run bison on parser.y
bison -d parser.y
# Note: You may want to rerun bison with the '-Wcounterexamples' option as suggested in the warning.

# Compile lex.yy.c and parser.tab.c with gcc
gcc lex.yy.c parser.tab.c -o ex


