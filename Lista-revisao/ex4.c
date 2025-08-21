//Escreva um programa que calcule e imprima o valor de S: Dado que S = 1 - 2/4 + 3/9 - 4/16

#include <stdio.h>
#include <stdlib.h>

int main () {
    float soma = 0.0, subtrai = 0;
    for (float i = 1; i < 10; i += 2) {
        soma += 1/i;
    }
    for (float i = 2; i <= 10; i += 2) {
        subtrai += 1/i;
    }
    printf("O valor de S: %.2f", soma - subtrai);
    return 0;
}