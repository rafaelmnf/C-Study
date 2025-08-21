/*Elabore uma função recursiva que determina o elemento máximo de um vetor */

#include <stdio.h>
#include <stdlib.h>
#define tam 6

int elementoMax(int vet[tam], int i, int *maior){
    if(i < 0 ) {
        return *maior;
    }
    if (vet[i] > *maior) {
        *maior = vet[i];
    }
    return elementoMax(vet, i - 1, maior);
}

int main() {
    int vet[tam] = {1,4,6,12,0,2};
    int maior = vet[0];
    printf("O maior elemento eh: %d", elementoMax(vet, tam-1, &maior));
}