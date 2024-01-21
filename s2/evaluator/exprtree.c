#include "exprtree.h"
struct tnode *createNode(int type, int val, int nodetype, char *name, struct tnode *left, struct tnode *right)
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
    tmp->left=left;
    tmp->right=right;
} 
