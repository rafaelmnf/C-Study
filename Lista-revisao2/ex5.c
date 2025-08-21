/*Faça uma função recursiva que permita somar os elementos de um vetor de inteiros*/

#include <stdio.h>
#include <stdlib.h>
#define tam 6

int somaVetor(int vet[tam], int i) {
    i--;
    if (i < 0) {
        return 0;
    }
    return vet[i] + somaVetor(vet, i);
}

int main() {
    int vet[tam] = {1,4,6,12,0,2};
    int i = tam;
    printf("Soma do vetor = %d", somaVetor(vet, i));
    return 0;
}