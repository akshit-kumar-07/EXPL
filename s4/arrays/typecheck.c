void typecheck(int t1, int t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror("Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror("Expected Boolean in IF ELSE check\n");
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror("Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case '+': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid operands for PLUS operation\n");
                      exit(1);
                  }
                  break;
        case '-': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid operands for MINUS operation\n");
                      exit(1);
                  }
                  break;
         case '*': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid operands for MUL operation\n");
                      exit(1);
                  }
                  break;
        case '/': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid operands for DIV operation\n");
                      exit(1);
                  }
                  break;
        case '%': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid operands for MOD operation\n");
                      exit(1);
                  }
                  break;         
        case 'b': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      yyerror("Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
    }
}
