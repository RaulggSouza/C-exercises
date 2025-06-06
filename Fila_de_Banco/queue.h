#ifndef QUEUE_H
#define QUEUE_H

//Struct for queue
typedef struct {
    int max;
    int size;
    char** vet;
    int start;
    int end;
} t_queue;

//Create queue function
t_queue* create_queue(int max);
//Return if the queue is empty function
int is_empty(t_queue* queue);
//Return if the queue is full function
int is_full(t_queue* queue);
//Return the lenght of the queue
int len(t_queue* queue);
//Insert one element in the queue
void in(t_queue* queue, char* elem);
//Removes one element of the queue
void out(t_queue* queue, char** elem);
//Free alocated memory
void destroy_queue(t_queue* queue);
#endif