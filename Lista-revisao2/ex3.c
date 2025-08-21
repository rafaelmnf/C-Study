/*Escreva uma função recursiva, ImprimeSerie(i,j,k: inteiro), que imprime na tela a série de valores do intervalo [i,j],
com incremento k.*/

#include <stdlib.h>
#include <stdio.h> 

void imprimeSeries (int i, int j, int k);

int main() {
    int i, j, k;
    printf("Digito inferior: ");
    scanf("%d", &i);
    printf("Digito superior: ");
    scanf("%d", &j);
    printf("Incremento: ");
    scanf("%d", &k);

    imprimeSeries(i,j,k);
    return 0;
}

void imprimeSeries (int i, int j, int k) {
    if (i > j) {
        return;
    }
    printf("%d ", i);
    imprimeSeries(i + k, j, k);
}