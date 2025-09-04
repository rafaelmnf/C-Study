#include "FILA.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    Fila* f = CriaFila();
    int opcao, valor;

    do {
        printf("\n====================================\n");
        printf(" Programa de manipulacao de fila\n");
        printf("======================================\n");
        printf("1. Inserir elemento (fim)\n");
        printf("2. Retirar elemento (inicio)\n");
        printf("3. Impressao da Fila\n");
        printf("4. Esvaziar a Fila\n");
        printf("5. Verifica fila vazia (1 se sim, 0 se nao)\n");
        printf("6. Quantidade de pares da Fila\n");
        printf("7. Inverter a Fila\n");
        printf("8. Apaga um numero da fila\n");
        printf("9. Imprimir Fila par e Fila impar\n");
        printf("10. Dividir fila em maiores de 20 e menores de 20\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Inserir
                printf("Digite um valor: ");
                scanf("%d", &valor);
                InsereFila(f, valor);
                break;

            case 2: // Retirar
                if (!VaziaFila(f)) {
                    valor = RetiraFila(f);
                    printf("Elemento removido: %d\n", valor);
                } else {
                    printf("Fila vazia!\n");
                }
                break;

            case 3: // Imprimir Fila
            imprimeFila(f);
                break;

            case 4: // Esvaziar
                liberaFila(f);
                printf("Fila esvaziada.\n");
                break;

            case 5: // Verificar se esta vazia
                if(VaziaFila(f)){
                    printf("Fila Vazia");
                } else {
                    printf("Existe elementos");
                }
                break;

            case 6: // Contar elementos pares 
                printf("Quantidade de pares: %d\n", nPares(f));
                break;

            case 7: // Inverter
                Fila* invertida =  CriaFila();
                inverteFila(f, invertida);
                printf("Fila invertida:\n");
                imprimeFila(invertida);
                break;

            case 8: // Apagar algum numero da fila
                printf("Digite um numero inteiro: ");
                scanf("%d", &valor);
                apagaNum(f, valor);
                printf("Numero %d removido da Fila.\n", valor);
                break;

            case 9: // Gerar 2 filas: 1 com numeros pares e outra com os numeros impares
                Fila* par = CriaFila();
                Fila* impar = CriaFila();
                parImpar(f, impar, par);
                printf("Fila com numeros pares: \n");
                imprimeFila(par);
                printf("Fila com numeros impares: \n");
                imprimeFila(impar);
                break;

            case 10: // Receber uma Fila e dividir em 2 pilhas: uma com maiores de 20 e outras com menores de 20
            Pilha* maior = CriaPilha();
            Pilha* menor = CriaPilha();
                divide20(f, maior, menor);
                break;

            case 0: // Sair
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    liberaFila(f);

    return 0;
}
