#define NODE_CONNECTOR 0
#define NODE_PLUS 1
#define NODE_MINUS 2
#define NODE_MUL 3
#define NODE_DIV 4
#define NODE_MOD 23
#define NODE_ID 5
#define NODE_NUM 6
#define NODE_ASSGN 7
#define NODE_READ 8
#define NODE_WRITE 9
#define NODE_IF 10
#define NODE_IF_ELSE 11
#define NODE_WHILE 12
#define NODE_LT 13
#define NODE_GT 14
#define NODE_LE 15
#define NODE_GE 16
#define NODE_EQ 17
#define NODE_NEQ 18
#define NODE_BREAK 19
#define NODE_CONT 20
#define NODE_STRVAL 21
#define NODE_ARRAY 22
#define NODE_RET 24
#define NODE_FUNC 25

#define TYPE_VOID 0
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_STR 3

//define the union type for constant value in the node
//since an identifier may be either string or integer we can use union

union Constant
{
    int intval; //if the variable is type int
    char *strval; //if the variable is string type
};

//Define the tree node
struct ASTNode
{
    int type; //pointer to the type table entry
    int nodetype; //what kind of node/construct we are dealing with here
    char *name; //name of the variable or function
    union Constant value; //stores the constant values as defined above
    struct ASTNode *arglist; //for storing the pointer to the expression list given as the argument to the function
    struct ASTNode *ptr1,*ptr2,*ptr3;
    struct Gsymbol *Gentry; //pointer to the global sybol table for the global variables and functions
    struct Lsymbol *Lentry; //pointer to the local symbol table of a function
};

//Prototype for the create node function
struct ASTNode* TreeCreate(
    int type;
    int nodetype;
    char *name;
    union Constant *value;
    struct ASTNode *arglist;
    struct ASTNode *ptr1;
    struct ASTNode *ptr2;
    struct ASTNode *ptr3;
);

int codegen(struct ASTNode *t);
void initialize();
struct ASTNode* reverseList(struct ASTNode *t);
