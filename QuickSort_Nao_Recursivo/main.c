/*
Por qual motivo deve-se usar uma pilha?
R: A pilha é usada nesse contexto para simular uma recursão, que por baixo dos panos, utilizam pilhas.

Considere o texto abaixo e discuta com o grupo. No início do arquivo principal, coloque como comentário se a estratégia faz sentido e se ela foi implementada
"A estratégia iterativa do algoritmo Quicksort oferece uma vantagem ao estabelecer limites para o tamanho da pilha. Em contraste com a abordagem recursiva, que insere duas partições na pilha de execução em ordem arbitrária, a versão iterativa verifica os tamanhos das partições antes de adicionar à pilha. Além disso, ao adotar uma política que prioriza a inserção dos índices da partição maior do vetor antes dos índices da partição menor, permite que o lado menor seja processado antes do lado maior. Como resultado, o tamanho da pilha é da ordem de O(log(n))."
R: A estratégia faz sentido e ela foi implementada, porém no código não é feita nenhuma verificação quanto ao tamanho, apenas se pega primeiro o lado esquerdo. Um ponto que
pode ser ressaltado é que usando uma linked-list duplamente encadeada para implementar a pilha, não temos problemas com o tamanho da pilha.

*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char const *argv[]){
    int size;
    scanf("%d", &size);
    int* array = create_array(size);
    quick(array, 0, size);
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    destroy_array(array);
    return 0;
}
