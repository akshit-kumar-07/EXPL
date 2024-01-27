#include "exprtree.h"
struct tnode *createNode(int type, int val, int nodetype, char *name, struct tnode *left, struct tnode *right,struct tnode *mid)
{
    struct tnode *tmp=(struct tnode *)malloc(sizeof(struct tnode));
    tmp->type=type;
    tmp->val=val;
    tmp->nodetype=nodetype;
    if(name != NULL)
    {
        tmp->varname=(char *)malloc(sizeof(name));
        strcpy(tmp->varname,name);
    }
    tmp->Gentry=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    tmp->left=left;
    tmp->right=right;
    tmp->mid=mid;
    return tmp;
} 
