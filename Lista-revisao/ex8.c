/*Faça um algoritmo que leia uma matriz quadrada de no máximo 3 posições e determine qual é o maior e o menor valor da linha 2 e qual é o maior e o menor valor da coluna 1.
*/

#include <stdio.h>
#include <stdlib.h>
#define l 3
#define c 3

int main () {
    float matriz[l][c];

    // Um for Loop para ler e outro para analisar a matriz
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    float maiorL2 = matriz[1][0];
    float menorL2 = matriz[1][0];
    float maiorC1 = matriz[0][0];
    float menorC1 = matriz[0][0];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            // linha 2
            if (matriz[1][j] > maiorL2) {
                maiorL2 = matriz[1][j];
            }
            if (matriz[1][j] < menorL2) {
                menorL2 = matriz[1][j];
            }
            // coluna 1
        }
        if (matriz[i][0] < menorC1) {
            menorC1 = matriz[i][0];
        }
        if (matriz[i][0] > maiorC1) {
            maiorC1 = matriz[i][0];
        }
    }
    printf("C1: menor=%.2f, maior=%.2f\nL2: menor=%.2f, maior=%.2f", menorC1, maiorC1, menorL2, maiorL2);

    return 0;
}