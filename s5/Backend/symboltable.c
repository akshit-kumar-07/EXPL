struct Gsymbol* GLookup(char *name) {
    struct Gsymbol *temp = Ghead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Lsymbol* LLookup(char *name) {
    struct Lsymbol *temp = Lhead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Paramstruct* PLookup(char *name) {
    struct Paramstruct *temp = Phead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

//Function to install an entry in the Global Symbol Table

void GInstall(char *name, int type, int size, struct Paramstruct *paramlist)
{
    struct Gsymbol* temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char *)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->next = NULL;

    //Check if the entity to be installed is a function, if it is install the pointer to the parameter list

    if(paramlist != NULL)
        temp->paramlist = paramlist;

    //Install the binding for the variable or array
    if(size != -1)
    {
        temp->binding = totalCount;
        totalCount += temp->size;
    }

    //Otherwise it is a function
    else
    {
        temp->flabel = fLabelCount;
        fLabelCount++;
    }

    if (Ghead != NULL) {
        Gtail->next = temp;
        Gtail = temp;
    } else {
        Ghead = temp;
        Gtail = temp;
    }

    return;
}

//Function to install in the local symbol table

void LInstall(char *name, int type) {
    //These are the same as installing in the Global Sybmol Table

    struct Lsymbol *temp;
    temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;

    //Since we are not allowing declaration of arrays as local variables in a function, we are assuming that only identifiers are variables and thus according to the XSM Architecture can be stored in one word of memeory

    temp->binding = localBindingStart;
    localBindingStart++;

    if (Lhead != NULL) {
        Ltail->next = temp;
        Ltail = temp;
    } else {
        Lhead = temp;
        Ltail = temp;
    }

    return;
}

//for the installing the formal parameters in the argument list of the function declaration

void PInstall(char *name, int type)
{
    struct Paramstruct* temp;
    temp= (struct Paramstruct *)malloc(sizeof(struct Paramstruct));

    temp->name = (char *)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;

    if (Phead != NULL) {
        Ptail->next = temp;
        Ptail = temp;
    } else {
        Phead = temp;
        Ptail = temp;
    }

    return;
}


//This function allows us to install the formal parametrs in the local symbol table. While strictly not necessary, it can help in verification etc.

void InstallParamsInLocal()
{
    struct Paramstruct *temp = Phead;
    int count = 0; //stores the total count of the number of formal parameters defined

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    localBindingStart = -1*count - 2; // the negative indices are used to mainatin the consistency that the actual variables and identifiers that needs to be stored in the LST are actually stored from the index 1

    temp =Phead;
    while(temp != NULL)
    {
        LInstall(temp->name, temp->type);
        temp = temp->next;
    }

    //restore the localBindingStart to the default position to stick tothe conventions.
    // this function will be executed before we have actually got into the function as the paarmeter declartions are available already to us beforehand

    localBindingStart = 1;
    return;

}


//Testing functions for printing global and local symbol tables
void printGSymbolTable() {
    struct Gsymbol* temp = Ghead;
    printf("\nGlobal Variables:\n");
    while (temp != NULL) {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

void printLSymbolTable() {
    struct Lsymbol* temp = Lhead;
    printf("\nLocal Variables:\n");
    while (temp != NULL) {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}
