#define NODE_CONN 0
#define NODE_NUM 1
#define NODE_ID 2
#define NODE_PLUS 3
#define NODE_MINUS 4
#define NODE_MUL 5
#define NODE_DIV 6
#define NODE_ASSIGN 7
#define NODE_READ 8
#define NODE_WRITE 9

typedef struct tnode 
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left;
	struct tnode *right;
}tnode; 

struct tnode *createNode(int type, int val, int nodetype, char *name, struct tnode *left, struct tnode *right);

