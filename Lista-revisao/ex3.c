/* O quadrado de um número natural N é dado pela soma dos N primeiros números ímpares consecutivos. Por exemplo:
3^2 = 1+3+5=9
4^2 = 1+3+5+7=16
Elabore um programa que leia um número natural N e calcule o seu quadrado usando o cálculo acima */

#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, quadrado = 0, impar = 1;
    printf("Digite um numero: ");
    scanf("%d", &num);
    for (int i=0; i < num; i++) {
        quadrado += impar;
        impar += 2;
    }
    printf("O quadrado de %d eh: %d", num, quadrado);
    return 0;
}