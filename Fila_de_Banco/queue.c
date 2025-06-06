#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue* create_queue(int max){
    t_queue* queue = (t_queue*) malloc(sizeof(t_queue));
    queue->vet = (char**) malloc(sizeof(char*) * max);
    queue->max = max;
    queue->size = 0;
    queue->start = 0;
    queue->end = 0;
    return queue;
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

void in(t_queue* queue, char* elem){
    if(is_full(queue)){
        return;
    }
    queue->vet[queue->end] = elem;
    queue->size++;
    queue->end = (queue->end+1) % queue->max;
}

void out(t_queue* queue, char** elem){
    if(is_empty(queue)){
        return;
    }
    strcpy((*elem), queue->vet[queue->start]);
    queue->start = (queue->start+1) % queue->max;
    queue->size--;
}

void destroy_queue(t_queue* queue){
    for (int i = queue->size; i < queue->size; i++){
        free(queue->vet[i]);
    }
    free(queue->vet);
    free(queue);
}