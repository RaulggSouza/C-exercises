#ifndef FUNCOES_H
#define FUNCOES_H

//Defining nodes
typedef struct t_no{
    struct t_no* next;
    struct t_no* prev;
    int start_index;
    int end_index;
} t_node;

//Defining stacks
typedef struct {
    t_node* start;
    t_node* top;
}t_stack;

//Create stack function
t_stack* create_stack();

//Create node function
t_node* create_node(int start, int end);

//Create array with elements typed by the user
int* create_array(int size);

//Insert a new node in the stack
void push(t_stack* stack, t_node* node);

//Remove the top node in the stack
void pop(t_stack* stack);

//Free all the allocated elements
void destroy_stack(t_stack* stack);

//Free the allocated array
void destroy_array(int* array);

//Swap the elements in the array with each other. The result is a array with all elements below the pivot on the left and all the elements above the pivot on the right
void swap(int* vet, int start, int end, int* pivot);

//Executes the quick sort using a stack
void quick(int* vet, int start, int size);

#endif