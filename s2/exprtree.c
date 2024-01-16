struct tnode* createTree(int val,int type,int nodetype,char *name,struct tnode *left,struct tnode *right)
{
    struct tnode *tmp;
    tmp=(struct tnode*)malloc(sizeof(struct tnode));
    tmp->val=val;
    tmp->type=type;
    tmp->nodetype=nodetype;
    if(name!=NULL)
    {
        tmp->varname=(char *)malloc(sizeof(name));
        strcpy(tmp->varname,name);
    }
    tmp->left=left;
    tmp->right=right;
    return tmp;
}
