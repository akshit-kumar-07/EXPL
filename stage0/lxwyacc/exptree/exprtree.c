struct tnode* makeLeafNode(int n)
{
    struct tnode *tmp;
    tmp= (struct tnode *)malloc(sizeof(struct tnode));
    tmp->op=NULL;
    tmp->val=n;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct tnode* makeOperatorNode(char op,struct tnode *left, struct tnode *right)
{
    struct tnode *tmp;
    tmp=(struct tnode *)malloc(sizeof(struct tnode));
    tmp->op=malloc(sizeof(char));
    *(tmp->op)=op;
    tmp->left=left;
    tmp->right=right;
    return tmp;
}

int evaluate(struct tnode *t)
{
    if(t->op==NULL)
        return t->val;
    else
    {
        switch(*(t->op))
        {
            case '+': return evaluate(t->left)+evaluate(t->right);
                      break;
            case '-': return evaluate(t->left)-evaluate(t->right);
                      break;
            case '*': return evaluate(t->left)*evaluate(t->right);
                      break;
            case '/': return evaluate(t->left)/evaluate(t->right);
                      break;
        }
    }
}
