// Elabore um programa em C que leia um número inteiro e determine quantos dígitos 7 possui esse número

#include <stdlib.h> 
#include <stdio.h>

int main () {
    int num, qnt = 0, divisor = 10;
    printf("Digite um numero inteiro:\n");
    scanf("%d", &num);

    while (num && num > 0) {
        if(num % divisor == 7) {
            qnt++;
        }
        num /= 10;
    }
    printf("Sao %d digitos 7", qnt);
}