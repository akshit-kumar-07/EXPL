struct tnode
{
    int val;
    char *op;
    struct tnode *left,*right;
};

struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char op,struct tnode *left,struct tnode *right);
int evaluate(struct tnode *t);
void prefix(struct tnode *t);
void postfix(struct tnode *t);
