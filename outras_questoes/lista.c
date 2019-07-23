#include <stdio.h>
#include <limits.h>
#define LAST_INDEX 

typedef struct NODE {

    int data;
    struct NODE *next;

} node;


void insert_node(node *prev, int data);
void append(node *list, int data);

node make_list(int data);
node* search(int target_i, node *start_node);
node* last_node(node *start_node);

int main()
{

    return 0;
}

node make_list(int data)
{
    node first;
    first.data = data;
    first.next = NULL;
    return first;
}

void change_index(node *list, int index, int new_data)
{
    node *change;

    change = search(index, list);

    change->data = new_data;
}

void insert_index(node *list, int index, int data)
{ 
    node *prev;

    prev = search(index, list);
    
    insert(prev, data);
}

void insert_node(node *prev, int data)
{
    node new_node;

    new_node.data = data;
    new_node.next = prev->next;

    prev->next = &new_node;
}

void delete_node(node *node)
{
    
}
void append(node *list, int data)
{
    node *change;
    change = last_node(list);
    
    insert_node(change, data);
}

node* last_node(node *start_node)
{
    node *buffer;
    buffer = search(INT_MAX, start_node);

    return buffer;
}

node* search(int target_i, node *start_node)
{
	
    node *tracker;
    node *temp;

    tracker = start_node->next;	

    int i;
    for(i=0; i < target_i; i++){

	temp = tracker->next;

	if(temp == NULL){
	    break;
	}

	tracker = temp;
    }
    
    return tracker;
}
