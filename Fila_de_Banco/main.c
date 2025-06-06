#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void print_result(t_queue* q){
    while (q->size > 0){
        char* name = malloc(255);
        out(q, &name);
        printf("%s\n", name);
    }
}

void start_day(t_queue* g, t_queue* p, t_queue* r){
    int preferential_count = 0;
    char identifier = 'a'; 
    while(1){
        scanf(" %c", &identifier);
        if(identifier == 'f'){
            break;
        }else if(identifier == 'g' || identifier == 'p'){
            char* input = malloc(255);
            scanf("%s", input);
            t_queue* q = (identifier == 'g' ? g : p);
            in(q, input);
        }else if(identifier == 's'){
            char* name = malloc(255);
            if (p->size == 0 || preferential_count == 3){
                out(g, &name);
                preferential_count = 0;
            } else {
                out(p, &name);
                preferential_count++;
            }
            in(r, name);
        }
    }
}

int main(int argc, char const *argv[]){
    t_queue* preferential = create_queue(5);
    t_queue* geral = create_queue(5);
    t_queue* result = create_queue(10);
    start_day(geral, preferential, result);
    print_result(result);
    destroy_queue(preferential);
    destroy_queue(geral);
    destroy_queue(result);
    return 0;
}
