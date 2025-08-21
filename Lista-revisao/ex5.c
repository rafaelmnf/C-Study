/* Dada a sequência matemática de números 1,1,2, 3, 5,8,13, 21.... Construa um programa que calcule a soma desta sequência para os N primeiros termo onde, N é fornecido pelo usuário.
• Exemplo: N=5 S= 2+3+5+8+13 =31 */

#include <stdio.h>
#include <stdlib.h>

int main () {
    int N;
    int atual = 1;
    int proximo = 1;
    int aux = 0;
    int soma = 0;
    printf("Digite um limite para calcular a soma da sequencia de Fibonacci: ");
    scanf("%d", &N);

    for (int i=0; i < N; i++) {
        aux = atual;
        soma += atual;
        atual = proximo;
        proximo += aux;
        }
    

    printf("A soma da sequencia de %d eh: %d", N, soma);
    return 0;
}