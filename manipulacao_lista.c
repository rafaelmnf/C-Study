/* Construa, em C, um programa que contenha as seguintes funções de Lista Encadeada- Básica
• Inserção de um Elemento da Lista (inserir no início)
• Remoção de um Elemento da Lista (retirar do início)
• Impressão da Lista
• Busca de um elemento na Lista, retorna 1 se ele existe e 0 caso contrário
• Uma função que verifica se a lista está vazia, retorna 1 se ela estiver vazia e 0 caso contrário
• Uma função que retorne a quantidade de elementos de uma lista. A lista é passada por parâmetro .
• Uma função que some os elementos de uma lista que é passada por parâmetro
• Inserção de um Elemento da Lista (inserir no fim da lista)
• Remoção de um Elemento da Lista (retirar do fim da lista)
• Uma função que retorna a quantidade de números ímpares da lista
• Uma função que receba duas listas e retorne uma terceira lista que é a união dessas duas listas (Não é permitido elementos
repetidos na Lista União) */

#include <stdlib.h>
#include <stdio.h> 

typedef struct no {
    int info;
    struct no* prox; //autoreferencia -> é um ponteiro para uma próxima estrutura do mesmo tipo
} lista;

// lista* significa: "um ponteiro que guarda o endereço de memória de um objeto do tipo lista"

// Função retorna um ponteiro do tipo lista, ou seja, armazena um endereço que contém outro "no"
lista* inicializar() {
    return NULL;
}

lista* inserirComeco(lista* recebida, int valor) {
    lista* novo;
    novo = (lista*) malloc(sizeof(lista));
    if(novo != NULL) {
        novo->info = valor;
        novo->prox = recebida; //Link
        return novo; // o inicio agora é o novo
    }
    return recebida;
}

lista* retirarComeco(lista* inicio) {
    if(inicio != NULL) {
        lista* aux;
        aux = inicio;
        inicio = inicio->prox;
        printf("%d retirado com sucesso\n", aux->info);
        free(aux); //libera o espaço de meoria guardado pelo inicio anterior
    }
    return inicio;
}

void impressaoLista(lista* inicio) {
    if(inicio == NULL) {
        printf("Lista Vazia");
    } else {
        printf("Lista: ");
        while(inicio != NULL) {
            printf("%d ", inicio->info);
            inicio = inicio->prox;
        }
    }
}

int buscaElemento(lista* inicio, int num) {
    while(inicio != NULL) {
        if(inicio->info == num) {
            return 1;
        }
        inicio = inicio->prox;
    }
    return 0;
}

int verificaVazia(lista* inicio) {
    if (inicio == NULL) {
        return 1;
    } return 0;
}


int qntElementos(lista* inicio) {
    int qnt = 0;
    while(inicio != NULL) {
        qnt++;
        inicio = inicio->prox;
    }
    return qnt;
}

lista* inserirFim(lista* inicio, int num) {
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->info = num;
    novo->prox = NULL;

    if (inicio == NULL) {
        return novo;
    }

    lista* aux = inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    return inicio;
}

void retirarFim(lista* inicio) {
    if (inicio == NULL) {
        // lista vazia, nada a remover
        return;
    }
    if (inicio->prox == NULL) {
        // se só tiver 1
        free(inicio);
        return;
    }

    lista* aux = inicio;
    while (aux->prox->prox != NULL) {
        aux = aux->prox;  // para no penúltimo
    }
    free(aux->prox);   // libera o último
    aux->prox = NULL;  // penúltimo vira último
}

int qntImpar(lista* inicio) {
    int qnt = 0;
    while (inicio != NULL) {
        if(inicio->info % 2 != 0) {
            qnt++;
        }
        inicio = inicio->prox;
    }
    return qnt;
}

void somaElementos(lista* inicio) {
    int soma = 0;
    while(inicio != NULL) {
        soma += inicio->info;
        inicio = inicio->prox;
    }
    printf("Soma dos elementos: %d\n", soma);
}
    
lista* uniaoLista(lista* inicio1, lista* inicio2, lista* inicio3) {
    // percorre a primeira lista
    while (inicio1 != NULL) {
        // se não for repetido
        if (!buscaElemento(inicio3, inicio1->info)) {
            inicio3 = inserirFim(inicio3, inicio1->info);
        }
        inicio1 = inicio1->prox;
    }

    // percorre a segunda lista
    while (inicio2 != NULL) {
        if (!buscaElemento(inicio3, inicio2->info)) {
            inicio3 = inserirFim(inicio3, inicio2->info);
        }
        inicio2 = inicio2->prox;
    }

    return inicio3;
}

int main() {
    printf("Programa de manipulacao de lista com alocação dinamica\n");
    printf("1. Inserir elemento no inicio\n");
    printf("2. Retirar elemento no inicio\n");
    printf("3. Impressao da lista\n");
    printf("4. Busca de um elemento na Lista (1 se existe, 0 se nao)\n");
    printf("5. Verifica lista vazia (1 se sim, 0 se nao) \n");
    printf("6. Quantidade de elementos de uma lista\n");
    printf("7. Inserir no fim da lista\n");
    printf("8. Retirar no fim da lista\n");
    printf("9. Quantidade de numeros impares\n");
    printf("10. Unir listas\n");
    printf("11. Somar elemento de uma lista\n");
    printf("12. Sair do Programa\n\n");

    lista* inicio;
    inicio = inicializar();

    int comando;
    while(comando) 
    {
        printf("Digite o comando: ");
        scanf("%d", &comando);
        switch (comando)
        {
        case 1:
            int numComeco;
            printf("Digite o numero a ser inserido: ");
            scanf("%d", &numComeco);
            inicio = inserirComeco(inicio, numComeco);
            break;

        case 2:
            inicio = retirarComeco(inicio);
            break;

        case 3:
            impressaoLista(inicio);
            printf("\n");
            break;

        case 4:
            int elemento;
            printf("Elemento a ser procurado na lista: ");
            scanf("%d", &elemento);
            int verifica = buscaElemento(inicio, elemento);
            if (verifica == 1) {
                printf("O numero %d existe na lista\n", elemento);
            } else {
                printf("Numero nao encontrado\n");
            }
            break;
        
        case 5:
            int vazia = verificaVazia(inicio);
            if(vazia == 1) {
                printf("Lista Vazia\n");
            } else {
                printf("Lista com elementos\n");
            }
            break;
        case 6:
            int qnt = qntElementos(inicio);
            printf("Sao %d elementos\n", qnt);
            break;
        case 7:
            int numFim;
            printf("Numero a ser inserido no final: ");
            scanf("%d", &numFim);
            inicio = inserirFim(inicio, numFim);
            break;
        case 8:
            retirarFim(inicio);
            break;
        case 9:
            int impar = qntImpar(inicio);
            printf("Sao %d numeros impares\n", impar);
            break;
        case 10:
            lista *inicio2, *inicio3;
            inicio2 = inicializar();
            inicio3 = inicializar();
            inicio2 = inserirComeco(inicio2, 1);
            inicio2 = inserirComeco(inicio2, 4);
            inicio2 = inserirComeco(inicio2, 12);
            inicio2 = inserirComeco(inicio2, 3);
            inicio3 = uniaoLista(inicio, inicio2, inicio3);
            impressaoLista(inicio3);
            printf("\n");
            break;
        case 11:
            somaElementos(inicio);
            break;
        case 12:
            exit(0);
        default:
            printf("\nDigite corretamente\n");
            break;
        }
    }

    return 0;
}