#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int size;
    int vet[20];
    int start;
    int end;
} t_queue;

t_queue* create_queue(int max){
    t_queue* queue = (t_queue*) malloc(sizeof(t_queue));
    queue->max = max;
    queue->size = 0;
    queue->start = 0;
    queue->end = 0;
}

int is_empty(t_queue* queue){
    return queue->size == 0;
}

int is_full(t_queue* queue){
    return queue->size == queue->max; 
}

int len(t_queue* queue){
    return queue->size;
}

void in(t_queue* queue, int elem){
    if(is_full(queue)){
        return;
    }
    queue->vet[queue->end] = elem;
    queue->size++;
    queue->end = (queue->end+1) % queue->max;
}

void out(t_queue* queue, int* elem){
    if(is_empty(queue)){
        return;
    }
    queue->start = (queue->start+1) % queue->max;
    queue->size--;
}

int main(int argc, char const *argv[]){
    
    return 0;
}
