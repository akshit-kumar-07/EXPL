
typedef struct list_node
{
    char *name; //name of the label
    int line_num; //number corresponding to the label
    struct list_node *next;
}list_node;

list_node *head=NULL;

//we use insert at the first node as it takes only O(1) time
void insert_begin(char *node_name, int line_num)
{
    list_node *tmp=(list_node *)malloc(sizeof(list_node));
    tmp->name=(char *)malloc(sizeof(node_name));
    strcpy(tmp->name,node_name);
    tmp->line_num=line_num;
    tmp->next=head;
    head=tmp;
}

int list_search(char *node_name)
{
    list_node *tmp=head;
    while(tmp!=NULL)
    {
        if(strcmp(tmp->name,node_name)==0)
            return tmp->line_num;
        tmp=tmp->next;
    }
    return -1; //node not found in the list
}
