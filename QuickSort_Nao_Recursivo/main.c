#include <stdio.h>
#include <stdlib.h>

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
t_stack* create_stack(){
    t_stack* stack = (t_stack*) malloc(sizeof(t_stack));
    stack->start = NULL;
    stack->top = NULL;
    return stack;
}

//Create node function
t_node* create_node(int start, int end){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->start_index = start;
    node->end_index = end;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

//Create array with elements typed by the user
int* create_array(int size){
    int* array = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++){
        int item;
        scanf("%d", &item);
        array[i] = item;
    }
    return array;
}

//Verify if the function is empty
int is_empty(t_stack* stack){
    return stack->start == NULL;
}

//Insert a new node in the stack
void push(t_stack* stack, t_node* node){
    if(stack->start == NULL){
        stack->start = node;
        stack->top = node;
    } else {
        t_node* previous = stack->start;
        while(previous != stack->top){
            previous = previous->next;
        }
        previous->next = node;
        node->prev = previous;
        stack->top = node;
    }
}

//Remove the top node in the stack
void pop(t_stack* stack){
    if (is_empty(stack)){
        return;
    } else if (stack->start != stack->top){
        t_node* prev = stack->top->prev;
        free(stack->top);
        prev->next = NULL;
        stack->top = prev;
    }else{
        free(stack->start);
        stack->start = NULL;
        stack->top = NULL;
    }
}

//Free all the allocated elements
void destroy_stack(t_stack* stack){
    t_node* node = stack->top;
    while (node != NULL){
        t_node* previous = node->prev;
        stack->top = previous;
        free(node);
        node = previous;
    }
    free(stack);
}

//Swap the elements in the array with each other. The result is a array with all elements below the pivot on the left and all the elements above the pivot on the right
void swap(int* vet, int start, int end, int* pivot){
    int i = start, j = end, aux;
    while (j >= i){
        if (vet[i] > vet[*pivot]){
            if (vet[j] <= vet[*pivot]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                if (vet[j] == vet[*pivot]) {
                    *pivot = i;
                } 
            }
            j--;
        } else {
            i++;
        }
    }
}

//Executes the quick sort using a stack
void quick(int* vet, int start, int size){
    t_stack* stack = create_stack();
    push(stack, create_node(start, size));
    while(!is_empty(stack)){
        int start = stack->top->start_index, end = stack->top->end_index;
        pop(stack);
        if (start != end){
            int pivot = (start+end)/2;
            swap(vet, start, end-1, &pivot);
            push(stack, create_node(pivot+1, end));
            push(stack, create_node(start, pivot));
        }
    }
    destroy_stack(stack);
}

int main(int argc, char const *argv[]){
    int size;
    scanf("%d", &size);
    int* array = create_array(size);
    quick(array, 0, size);
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
