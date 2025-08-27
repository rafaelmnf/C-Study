#include "PILHA.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    Pilha *p = CriaPilha();
    int opcao, valor;

    do {
        printf("\n====================================\n");
        printf(" Programa de manipulacao de pilha\n");
        printf("======================================\n");
        printf("1. Inserir elemento\n");
        printf("2. Retirar elemento (pop)\n");
        printf("3. Impressao da pilha\n");
        printf("4. Esvaziar a pilha\n");
        printf("5. Verifica pilha vazia (1 se sim, 0 se nao)\n");
        printf("6. Quantidade de elementos da pilha\n");
        printf("7. Inverter a pilha\n");
        printf("8. Ler numero e guardar digitos na pilha\n");
        printf("9. Imprimir numero guardado na pilha\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Inserir
                printf("Digite um valor: ");
                scanf("%d", &valor);
                push(p, valor);
                break;

            case 2: // Retirar
                if (!vaziaPilha(p)) {
                    valor = pop(p);
                    printf("Elemento removido: %d\n", valor);
                } else {
                    printf("Pilha vazia!\n");
                }
                break;

            case 3: // Imprimir pilha
            imprime(p);
                break;

            case 4: // Esvaziar
                liberaPilha(p);
                printf("Pilha esvaziada.\n");
                break;

            case 5: // Verificar se vazia
                if(vaziaPilha(p)){
                    printf("Pilha Vazia");
                } else {
                    printf("Existe elementos");
                }
                break;

            case 6: // Contar elementos
                printf("Quantidade de elementos: %d\n", contarElementos(p));
                break;

            case 7: // Inverter
                p = invertePilha(p);
                printf("Pilha invertida!\n");
                imprime(p);
                break;

            case 8: // Ler número e guardar dígitos
                printf("Digite um numero inteiro: ");
                scanf("%d", &valor);
                p = Digitos(valor);
                printf("Numero armazenado na pilha.\n");
                break;

            case 9: // Imprimir número da pilha
                printf("Numero na pilha: ");
                imprimeNumero(p);
                printf("\n");
                break;

            case 0: // Sair
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);

    liberaPilha(p);
    free(p); // libera struct Pilha

    return 0;
}
