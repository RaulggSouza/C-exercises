#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

t_stack* create_stack(){
    t_stack* stack = (t_stack*) malloc(sizeof(t_stack));
    stack->start = NULL;
    stack->top = NULL;
    return stack;
}

t_node* create_node(int start, int end){
    t_node* node = (t_node*) malloc(sizeof(t_node));
    node->start_index = start;
    node->end_index = end;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int* create_array(int size){
    int* array = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++){
        int item;
        scanf("%d", &item);
        array[i] = item;
    }
    return array;
}

int is_empty(t_stack* stack){
    return stack->start == NULL;
}

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

void destroy_array(int* array){
    free(array);
}

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