/*Faça um algoritmo que leia uma matriz de no máximo 4 linhas e 4 colunas. O programa deverá:
• Elaborar a matriz transposta
• Trocar os valores da coluna 0 com a coluna 3
• Determinar quantos números pares tem essa matriz
• A soma dos valores da diagonal principal
• O maior valor da diagonal secundária
• Determine a soma de cada linha desta matriz, coloque o resultado em um vetor
• Determine o maior valor de cada coluna dessa matriz, coloque o resultado em um vetor
• A cada item, a matriz resultante deverá ser impressa */

#include <stdio.h>
#include <stdlib.h>
#define l 4
#define c 4

int main () {
    int matriz[l][c], matrizT[l][c], aux;
    // Um for Loop para ler e outro para analisar a matriz
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    // imprime a matriz para melhor vizualização:
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ",  matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Matriz transposta
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matrizT[j][i] = matriz[i][j];
        }
    }
    // imprime a matriz para melhor vizualização:
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ",  matrizT[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Troca a coluna 0 com a 3
    for (int i = 0; i < l; i++) {
        aux = matrizT[i][0];
        matrizT[i][0] = matrizT[i][3];
        matrizT[i][3] = aux;
    }
    // imprime a matriz para melhor vizualização:
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ",  matrizT[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int pares = 0;
    // Quantidade de numeros pares
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matrizT[i][j] % 2 == 0){
                pares++;
            }
        }
    }
    printf("Numeros pares: %d\n", pares);

    int soma = 0;
    // A soma dos valores da diagonal principal
    for (int i = 0, j = 0; i < l; i++, j++) {
        soma += matrizT[i][j];
    }
    printf("Soma da diagonal principal: %d\n", soma);


    int maior = matrizT[0][3];
    // O maior valor da diagonal secundária
    for (int i = 0, j = 3; i < l; i++, j--) {
        if (maior < matrizT[i][j]) {
            maior = matrizT[i][j];
        }
    }
    printf("Maior valor da diagonal secundaria: %d\n", maior);

    int somaLinhas[l] = {0,0,0,0};
    // Determine a soma de cada linha desta matriz, coloque o resultado em um vetor
    for (int i = 0, s = 0; i < l; i++, s++) {
        for (int j = 0; j < c; j++) {
            somaLinhas[s] += matrizT[i][j];
        }
        printf("Soma da linha[%d]= %d\t",s, somaLinhas[s]);
    }
    printf("\n");

    int maiorColuna[c] = {matrizT[0][0], matrizT[0][1], matrizT[0][2], matrizT[0][3]};
    // Determine o maior valor de cada coluna dessa matriz, coloque o resultado em um vetor
    for (int i = 0, m = 0; i < c; i++, m++) {
        for (int j = 0; j < l; j++) {
            if (maiorColuna[m] < matrizT[j][i]) {
                maiorColuna[m] = matrizT[j][i];
            }
        }
        printf("Maior valor da coluna[%d]= %d\t",m, maiorColuna[m]);
    }

    return 0;
}