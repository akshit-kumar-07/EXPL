/* We do typechecking for the following statements
 *  if: case (i) : the arg must be boolean
 * if_else: case(e) : the arg must be boolean
 * while: case(w): the arg must be boolean
 * arithmetic: case(a): operands must be arithmetic
 * boolean: case(b): operands must be boolean
 * assignment: case(=): operands must be of compatible types
 */
extern int yyerror();
void typecheck(int found_type,int original_type,char c)
{
    switch(c)
    {
        case 'i':
            if(found_type!=original_type)
            {
                yyerror("Boolean type expected in IF statements\n");
                exit(1);
            }
            break;
        case 'e':
            if(found_type!=original_type)
            {
                yyerror("Boolean type expected in IF-ELSE statements\n");
                exit(1);
            }
            break;
        case 'w':
            if(found_type!=original_type)
            {
                yyerror("Boolean type expected in WHILE statements\n");
                exit(1);
            }
            break;
        case 'a':
            if(found_type!=INT || original_type !=INT)
            {
                yyerror("Integer type expected in arithmetic statements\n");
                exit(1);
            }
            break;
        case 'b':
            if(found_type!=INT || original_type != INT)
            {
                yyerror("Boolean type expected in Logical operations\n");
                exit(1);
            }
            break;

        case 'r':
            if(found_type!=original_type)
            {
                yyerror("Boolean type expected in Repeat statements\n");
                exit(1);
            }
            break;

        case '=':
            if(found_type!=original_type)
            {
                yyerror("Incompatible assignment operation\n");
                exit(1);
            }
            break;
    }
}
