/*Preencher um vetor de 8 elementos inteiros. Mostrar o vetor e informar quantos números são maiores que 30.*/

#include <stdio.h>
#include <stdlib.h>
#define tam 7

int main () {
    int vet[tam];
    int m30 = 0;
    printf("Digite os numeros do vetor:\n");
    for (int i=0; i < tam; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &vet[i]);
        if (vet[i] > 30) {
            m30++;
        }
    }

    printf("Vetor lido:\n");
    for (int i = 0; i < tam; i++) {
        printf("Vetor[%d]: %d\t", i, vet[i]);
    }
    printf("\nNumeros maiores que 30: %d", m30);
    return 0;
}