#define NODE_CONN 0
#define NODE_PLUS 1
#define NODE_MINUS 2
#define NODE_MUL 3
#define NODE_DIV 4
#define NODE_ID 5
#define NODE_NUM 6
#define NODE_ASSIGN 7
#define NODE_READ 8
#define NODE_WRITE 9

struct tnode
{
    int val; //stores the value in case of constants
    int type; //at this stage 0 indicates constant and 1 indicates variable as the variables
              //can only store integers at this stage
    char *varname; //can be set as NULL for constants
    int nodetype; //can use the specified MACROS
    struct tnode *left;
    struct tnode *right;
};

struct tnode* createTree(int val,int type,char *varname,int nodetype,struct tnode *left,struct tnode *right);

int codegen(struct tnode *t);

