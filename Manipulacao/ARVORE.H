#ifndef ARVORE
#define ARVORE

// Trabalhando com Arvores Binarias

#include <stdio.h>
#include <stdlib.h>

// A arvore tem um no tipo arv que aponta para a raiz
typedef struct Arvore {
    noArv *raiz;
} Arv;


// no arv tem a informação, e os nós da direita e esquerda depois dele
typedef struct noArvore {
    int info;
    struct noArvore *esq;
    struct noArvore *dir;
} noArv;


// inicialização de Arvore
Arv* criaArv () {
    Arv *A;
    A = (Arv*)malloc(sizeof(Arv));
    A->raiz = NULL;
    return A;
}


// verificar se a arvore esta vazia (1 vazia, 0 tem elementos)
int arvVazia (Arv* A) {
    if (A->raiz == NULL) {
        return 1;
    }
    return 0;
}


// Imprimir arvore:
// Pre-Order -> imprime antes e depois vai p direita e depois esquerda
void imprimePreOrder (noArv *Pai) {
    printf("%d -", Pai->info);
    if(Pai->dir != NULL) {
        imprimePreOrder(Pai->dir);
    }
    if(Pai->esq != NULL) {
        imprimePreOrder(Pai->esq);
    }
}

// In-Order -> vai p direita, imprime e depois vai para a esquerda
void imprimeInOrder (noArv *Pai) {
    if(Pai->dir != NULL) {
        imprimeInOrder(Pai->dir);
    }
    printf("%d -", Pai->info);
    if(Pai->esq != NULL) {
        imprimeInOrder(Pai->esq);
    }
}

// Pos-Order -> vai p direita, depois para a esquerda e depois imprime

void imprimePosOrder (noArv *Pai) {
    if(Pai->dir != NULL) {
        imprimePosOrder(Pai->dir);
    }
    if(Pai->esq != NULL) {
        imprimePosOrder(Pai->esq);
    }
    printf("%d -", Pai->info);
}

// Buscar um elemento na arvore por valor (1 achou, 0 não achou)
int Busca (Arv *A, int num) {
    noArv *Pai = A->raiz;
    // looping infinito até dar return
    while (1) {
        // Achou
        if (Pai->info == num) { return 1;}
        if (num < Pai->info) {
            // Se tem para a esquerda
            if (Pai->esq != NULL) {
                Pai = Pai->esq;
            } else { return 0;} // Se n tiver, acabou e o num não está na Arvore
        } else {
            if (num > Pai->info) {
                if (Pai->dir != NULL) {
                    Pai = Pai->dir;
                } else { return 0; }
            }
        }
    }
}


// Inserir um elemento na Arvore

void insere (Arv *Arvore, int num) {
    Arvore->raiz = insere_aux(Arvore->raiz, num);
}


noArv* insere_aux (noArv *A, int num) {
    noArv *novo = (noArv*)malloc(sizeof(Arv)); // alocou espaço para o elemento
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if (A == NULL) { // se a raiz está vazia, insere ali mesmo
        return novo;
    } else {
        noArv *Pai = A; // cria um novo ponteiro para guardar endereço da raiz para não perder depois
        int flag = 0;
        while (flag == 0) {
            if (novo->info > Pai->info) {
                if (Pai->dir != NULL) {
                    Pai = Pai->dir;
                } else {
                    Pai->dir = novo;
                    flag = 1;
                }
            } else {
                if (Pai->esq != NULL) {
                    Pai = Pai->esq;
                } else {
                    Pai->esq = novo;
                    flag = 1;
                }
            }
        }
    }
    return A;
}

// Remover um elemento da Árvore

Arv* remover(Arv *Raiz, int num) {
    noArv *aux = Raiz->raiz;
    // Arvore só tem a raiz
    if (aux->info == num && aux->dir == NULL && aux->esq == NULL) {
        free(aux);
        free(Raiz);
        return NULL; //raiz da arvore é NULL, e apaga a memoria alocada
    }
    Raiz->raiz = remover_aux(Raiz->raiz, num);
    return Raiz;
}

noArv* remover_aux (noArv * pai, int num) {
    if (pai == NULL) {
        printf ("\n\n não encontrado na árvore");
    } else {
        if (num > pai->info ) {
            // vai p direita e retorna o filho (pai->dir)
            pai->dir = remover_aux (pai->dir, num);
        } else {
            if (num < pai ->info) {
                // vai p esquerda e retorna o filho (pai->esq)
                pai->esq = remover_aux(pai->esq, num);
            } else { // achou o nó a ser removido se n foi p direita nem esquerda
                if (pai->dir == NULL && pai->esq == NULL) { // sem filhos
                    free(pai); pai = NULL;
                } else {
                    if (pai->esq == NULL) { // só tem filho da direita
                        // pai é o elemento a ser tirado, aux contém esse elemento, pai vira o próximo, ou seja, o nó anterior agora aponta para esse
                        noArv *aux = pai; pai = pai->dir; free(aux);
                    } else {
                        if (pai->esq == NULL) { // só tem filho da esquerda
                            noArv *aux = pai; pai = pai->esq; free(aux);
                        } else { // tem os dois filhos
                            noArv * aux;
                            aux = pai->esq;
                            while (aux->dir != NULL) {
                                aux = aux-> dir; // aux vai fica com o maior valor da sub-arvore da esquerda
                            }
                            pai->info = aux->info; // maior valor da sub vira o valor do pai
                            aux->info = num; // vira num para continuar a recursão
                            pai->esq = remover_aux (pai->esq, num); // chama a função recursivamente para que troque novamente ou ele vire folha e será excluido
                        }
                    }
                }
            }
        }
    }
    return pai;
}


#endif