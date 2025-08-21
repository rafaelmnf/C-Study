/* Elabore um programa que crie uma estrutura com as seguintes informações de um produto:
• Código do produto – inteiro de 3 dígitos
• Quantidade em estoque - inteiro
• Valor de compra - real
• Valor de Venda - real
   O programa deverá ler a informação de 10 produtos e determinar
• O código do produto com maior quantidade de estoque
• O quantidade de estoque do produto que proporciona o maior lucro
*/

#include <stdio.h>
#include <stdlib.h>
#define qnt 4

typedef struct infoProduto {
    int codigo;
    int estoque;
    float Vcompra;
    float Vvenda;
}info;


int main() {
    info produto[qnt];

    for(int i = 0; i < qnt; i++) {
        do {
            printf("Codigo Produto[%d] (0-999): ", i);
            scanf("%d", &produto[i].codigo);
            if (produto[i].codigo < 0 || produto[i].codigo > 999) {
                printf("Erro: codigo invalido!\n");
            }
        } while (produto[i].codigo < 0 || produto[i].codigo > 999);

        printf("Estoque Produto[%d]: ", i);
        scanf("%d", &produto[i].estoque);

        printf("Valor Compra Produto[%d]: ", i);
        scanf("%f", &produto[i].Vcompra);

        printf("Valor Venda Produto[%d]: ", i);
        scanf("%f", &produto[i].Vvenda);
    }

    int estoque = produto[0].estoque;
    float Mlucro = (produto[0].Vvenda - produto[0].Vcompra);
    int indexMQ = 0;
    int indexML = 0;

    //verifica cada produto
    for(int i = 0; i < qnt; i++) {
        if(produto[i].estoque > estoque){
            indexMQ = i;
        }
        if((produto[i].Vvenda - produto[i].Vcompra > Mlucro)) {
            indexML = i;
        }
    }

    printf("O código do produto com maior quantidade de estoque: %d\n", produto[indexMQ].codigo);
    printf("A quantidade de estoque do produto que proporciona o maior lucro: %d\n", produto[indexML].estoque);

    return 0;
}