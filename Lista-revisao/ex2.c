/* Construa um programa que leia vários números inteiros positivos. O programa será encerrado quando um número NÃO positivo for digitado e irá calcular:
• A quantidade de números lidos
• A soma dos números que são múltiplos de 3 maiores que 10
• A quantidade de múltiplos de 3
• O percentual de múltiplos de 7 */

#include <stdlib.h>
#include <stdio.h>


int main () {
    int num, qnt = 0, soma = 0, m7 = 0, m3 = 0;
    
    while (num >= 0){
        printf("Adicionar numero: ");
        scanf("%d", &num);
        if(num < 0){
            break;
        }
        qnt++;
        if (num % 3 == 0 ) {
            m3++;
            if(num > 10) {
                soma += num;
            }
        }
        if (num % 7 == 0) {
            m7++;
        }
    }

    printf("Numeros lidos: %d\n", qnt);
    printf("Soma de multiplos de 3 maiores que 10: %d\n", soma);
    printf("Multiplos de 3: %d\n", m3);
    printf("Percentual de multiplos de 7: %.2f%%\n", ((float) m7 / qnt) * 100);

    return 0;
}