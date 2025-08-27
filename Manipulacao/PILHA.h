#ifndef PILHA
#define PILHA

#include <stdio.h>
#include <stdlib.h>

/* FUNCOES DE MANIPULACAO DE PILHA

Pilha* CriaPilha ()     CRIA A PILHA

No* inserir_inicio (No* t, int a)  AUXILIAR DA INSERCAO

void push (Pilha* p, int v) INSERCAO

No* retirar_inicio (No* l)         AUXILIAR DA REMOCAO

int pop (Pilha* p)          REMOVE RETORNANDO O VALOR QUE FOI REMOVIDO

Pilha* liberaPilha (Pilha* p)      LIBERA A PILHA

void imprime (Pilha* p)     IMPRIMA A PILHA

int vaziaPilha(Pilha *p)	    VERIFICA SE A PILHA ESTA VAZIA, RETORNA 1

*/

// Nó contendo o elemento + o endedereço do proximo
typedef struct no
{
    int info;
    struct no *prox;
}No;


// Pilha guarda o o endereço do topo da pilha, endereço do 1° elemento, o qual vai tirar e por.
typedef struct pilha
{
   No *Topo;
   // O topo não guarda nenhuma info, ele só guarda o endereço do primeiro elemento 
}Pilha;


Pilha* CriaPilha (void)
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->Topo = NULL;
   return p;
}

int vaziaPilha(Pilha *p) {
    if(p->Topo == NULL) {
        return 1;
    }
    return 0;
}

int verificarElemento(Pilha *p, int v) {
    while (p->Topo != NULL) {
        if(p->Topo->info == v){
            return 1;
        }
        p->Topo = p->Topo->prox;
    }
    return 0;
}

No* inserir_inicio (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t; // o próximo apontado pelo atual agora, era o atual antigo
    return aux;
}

void push (Pilha* p, int v)
{
    p->Topo = inserir_inicio(p->Topo,v); // O endereço do no espaço criado é apontado por topo
}

No* retirar_inicio (No* aux)
{
    No* p = aux->prox;
    free(aux);
    return p;
}

int pop (Pilha *p)
{
    int v;
    if (vaziaPilha(p))
    {
        printf("\n\n\t==> Pilha VAZIA, IMPOSSIVEL CONTINUAR.\n\n");
        exit(1); /* aborta programa */
    }
    v = p->Topo->info;
    p->Topo = retirar_inicio(p->Topo);
    return v;
}

Pilha* liberaPilha (Pilha* p) {
    if (p->Topo == NULL) {
        return p;
    }
    while(p->Topo != NULL) {
        p->Topo = retirar_inicio(p->Topo);
    }
    return p; // retorna o novo começo da pilha
}

void imprime (Pilha* p) {
    if (!vaziaPilha(p)) {
        printf("Conteudo da pilha: ");
        No *aux = p->Topo;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    } else {
        printf("Pilha vazia!\n");
    }
}

// Função de contar os Elementos da Pilha

int contarElementos(Pilha *p) {
    int qnt = 0;
    while (p->Topo != NULL) {
        qnt++;
        p->Topo = p->Topo->prox;
    }
    return qnt;
}

Pilha* invertePilha (Pilha* p) {
    /* primeiro elemento da pilha é retirado e guardado em outra pilha, depois, só passsa o endereço de Topo para 
    a outra pilha */
    Pilha* invertida = CriaPilha();
    while (p->Topo != NULL) {
        // dentro da própria função pop, já atualiza o topo da pilha p, 
        int valor = pop(p);
        push(invertida, valor);
    }
    return invertida;
}  

// Remova um determinado elemento da pilha, se existir
Pilha* removerElemento (Pilha* p, int v) {
    if (p->Topo == NULL) return p; // pilha vazia
    // Como estamos manipulando pilha, é necessário verificar se tem o elemento primeiro
    // Se tiver, muda toda a pilha até o elemento para uma pilha aux, retira o elemento, e volta a pilha dnv 
    No *aux;
    Pilha *pilhaAux = CriaPilha();
    if (verificarElemento(p, v) == 1) {
        while(p->Topo->info != v) {
            push(pilhaAux, pop(p)); //dps de empilhar na outra pilha
        }
        aux = p->Topo; // esse é o elemento que queremos apagar
        p->Topo = p->Topo->prox; // aponta para o próximo;
        free(aux); // apaga o endereço daquele elemento encontrado;
        while(pilhaAux->Topo != NULL) {
            push(p, pop(pilhaAux)); // desempilha na original;
        }
    }
    return p;
}

/* Dado duas pilhas, passadas por parâmetro, retorne qual tem mais elementos. Os valores de retorno serão:
• 0 se as duas pilhas tiverem a mesma quantidade de elementos
• 1 se a pilha 1 tiver mais elementos
• 2 se a pilha 2 tiver mais elementos */

int comapara(Pilha *p1, Pilha *p2) {
    int qnt1 = contarElementos(p1);
    int qnt2 = contarElementos(p2);

    if(qnt1 == qnt2){
        return 0;
    } else if( qnt1 > qnt2){
        return 1;
    } else {
        return 2;
    }
}

// Ler um número inteiro e guardar os dígitos numa pilha.
// Retorna o endereço dessa pilha criada
Pilha *Digitos(int num) {
    Pilha *nova =  CriaPilha();
    while (num > 0) {
        push(nova, num % 10);  // pega o último dígito
        num = num / 10;        // remove o último dígito
    }

    return nova;
}

/*Dado um número inteiro, cujo os seus dígitos estão armazenados numa pilha, imprima o número inteiro*/

void imprimeNumero(Pilha *p) {
    Pilha *aux = CriaPilha();

    // Passa os dígitos para a pilha auxiliar (inverte a ordem)
    while (p->Topo != NULL) {
        push(aux, pop(p));
    }

    // Agora imprime na ordem certa
    while (aux->Topo != NULL) {
        printf("%d", pop(aux));
    }
}

#endif // PILHA_H_INCLUDED