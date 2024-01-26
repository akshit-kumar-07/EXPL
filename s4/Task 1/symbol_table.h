int type_variable =0; //0: void, 1: int, 2: bool, 3: str
int variable_position=4096; //to store the position in stack where the variable is stored

typedef struct Gsymbol
{
	char *name;
	int type;
	int size;
	int binding;
	struct Gsymbol *next;
}Gsymbol;

void Install(char *name, int type, int size); //insert the token in the Symbol Table
struct Gsymbol *Lookup(char *name);  //return a pointer corresponding to the token
Gsymbol *head; //to keep track of the beginning of the symbol table
void print_symbol_table();
