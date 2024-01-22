extern int vars[26];

int evaluate(struct tnode *t)
{
    int ind=0;int x=0,y=0,z=0;
    if(t==NULL) return 0;
    else if(t->nodetype==NODE_CONN)
    {
        evaluate(t->left);
        evaluate(t->right);
    }
    switch(t->nodetype)
    {
        case NODE_PLUS:
            return evaluate(t->left)+evaluate(t->right);
        case NODE_MINUS:
            return evaluate(t->left)-evaluate(t->right);
        case NODE_MUL:
            return evaluate(t->left)*evaluate(t->right);
        case NODE_DIV:
            return evaluate(t->left)/evaluate(t->right);
        case NODE_NUM:
            return t->val;
        case NODE_ID:
            return vars[t->varname[0]-'a'];
        case NODE_READ:
            ind=t->left->varname[0]-'a';
            scanf("%d",&x);
            vars[ind]=x;
            break;
        case NODE_WRITE:
            x=evaluate(t->left);
            printf("%d\n",x);
            break;
        case NODE_ASSIGN:
            ind=t->left->varname[0]-'a';
            x=evaluate(t->right);
            vars[ind]=x;
            return 0;
        case NODE_GT:
            return evaluate(t->left)>evaluate(t->right);
        case NODE_LT:
            return evaluate(t->left)<evaluate(t->right);
        case NODE_GE:
            return evaluate(t->left)>=evaluate(t->right);
        case NODE_LE:
            return evaluate(t->left)<=evaluate(t->right);
        case NODE_EQ:
            return evaluate(t->left)==evaluate(t->right);
        case NODE_NEQ:
            return evaluate(t->left)!=evaluate(t->right);
        case NODE_IF:
            x=evaluate(t->left);
            if(x==0) break;
            else return evaluate(t->right);
        case NODE_IF_ELSE:
            x=evaluate(t->left);
            switch(x)
            {
                case 0:
                    return evaluate(t->right);
                case 1:
                    return evaluate(t->mid);
            }
        case NODE_WHILE:
            while(evaluate(t->left))
                evaluate(t->right);
            return 0;
        default:
            break;
    }
}
