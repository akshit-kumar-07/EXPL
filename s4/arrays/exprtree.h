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
#define NODE_IF 10
#define NODE_IF_ELSE 11
#define NODE_WHILE 12
#define NODE_BREAK 13
#define NODE_CONTINUE 14
#define NODE_LT 15
#define NODE_GT 16
#define NODE_EQ 17
#define NODE_NEQ 18
#define NODE_GE 19
#define NODE_LE 20
#define NODE_REPEAT 21
#define NODE_DOWHILE 22
#define NODE_STRVAL 23
#define NODE_ARRAY 24
#define NODE_MOD 25
#define TYPE_VOID 0
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_STR 3

typedef struct tnode 
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct Gsymbol *Gentry;
	struct tnode *left;
	struct tnode *right;
	struct tnode *mid;
}tnode; 

struct tnode *createNode(int type, int val, int nodetype, char *name, struct tnode *left, struct tnode *right, struct tnode *mid);

