/*Elabore um programa que leia 3 números inteiros. Este programa deverá ter uma função que retorne o fatorial de um
número. Use essa função, para calcular o fatorial dos números lidos (imprima no programa principal).
*/

#include <stdlib.h>
#include <stdio.h> 

int fatorial(int N);

int main() {
    int a, b, c;

    printf("a:");
    scanf("%d", &a);
    printf("b:");
    scanf("%d", &b);
    printf("c:");
    scanf("%d", &c);

    printf("O fatorial de %d eh: %d\n",a, fatorial(a));
    printf("O fatorial de %d eh: %d\n",b, fatorial(b));
    printf("O fatorial de %d eh: %d",c, fatorial(c));
    
    return 0; 
}

int fatorial(int N) {
    if(N <= 1) {
        return 1;
    }
    return N * fatorial(N - 1);
}