int declarationType; //to pass the type of the variable
int FDeclarationType; //to pass the type of return of function
int totalCount = 4096; //binding and address of the next variable
int localBindingStart=1;
int fLabelCount=0; //to create a symbolic label as F0,F1,etc.. for the functions in the global symbol table entry

//for holding the parameters to the function
struct Paramstruct
{
    char *name;
    int type;
    struct Paramstruct *next;
};

//Global Symbol Table Entry
struct Gsymbol
{
    char *name; //name of the identifier
    int type; //type of the identifier(integer or string)
    int size; //size of the identifier/array
    int binding; //where on the stack is the global variable stored
    struct Paramstruct *paramlist; //pointer to the head of the parameter list for a function
    int flabel; //a label for storing the starting address of a functiion's code
    struct Gsymbol *next;
};

//same definitions as above
struct Lsymbol
{
    char *name;
    int type;
    int binding;
    struct Lsymbol *next;
};

//define the functions prototypes

//Global
struct Gsymbol *GLookup(char *name); //to search and return the entry from the global symbol table
void GInstall(char *name, int type,int size, struct Paramstruct *paramlist);// creates a symbol table entry if it does not exists already
struct Gsymbol *Ghead, *Gtail;

//Local
struct Lsymbol *LLookup(char *name);//to search and return the entry from the local symbol table
void LInstall(char *name, int type); //creates an STE if does not exists
struct Lsymbol *Lhead, *Ltail;

//Parameters
struct Paramstruct *PLookup(char *name);
void PInstall(char *name, int type);
struct Paramstruct *Phead, *Ptail;

void printLSymbolTable();
void printGSymbolTable();

//optional function to install formal parameters in the local symbol table
void InstallParamsInLocal();
