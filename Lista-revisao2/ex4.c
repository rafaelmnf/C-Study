/*Determine um algoritmo iterativo e recursivo que calcule a some de N números ímpares*/

#include <stdio.h>
#include <stdlib.h>

int somaImparesIterativa(int n) {
    int soma = 0;
    int impar = 1;

    for (int i = 0; i < n; i++) {
        soma += impar;
        impar += 2; // próximo número ímpar
    }
    return soma;
}

int somaImparRecursiva(int n, int impar) {
    if (n <= 0) {
        return 0;
    }
    return impar + somaImparRecursiva(n-1, impar + 2);
}

int main() {
    int n;
    int impar = 1;
    printf("Digite a quantidade de numeros impares: ");
    scanf("%d", &n);

    printf("Soma (iterativa) = %d\n", somaImparesIterativa(n));
    printf("Soma recursiva = %d \n", somaImparRecursiva(n, impar));
    return 0;
}
