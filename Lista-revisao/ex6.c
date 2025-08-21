/*Fazer um programa em C para ler um vetor de inteiros positivos de 15 posições, no máximo. Imprimir a quantidade de números pares e a quantidade de múltiplos de 5*/

#include <stdio.h>
#include <stdlib.h>
#define tam 14

int main () {
    int vet[tam];
    int pares = 0;
    int m5 = 0;

    printf("Digite os numeros do vetor:\n");
    for (int i=0; i < tam; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &vet[i]);
        if (vet[i] % 2 == 0) {
            pares++;
        }
        if (vet[i] % 5 == 0) {
            m5++;
        }
    }

    printf("Sao %d numeros pares e %d numeros multiplos de 5.", pares, m5);

    return 0;
}