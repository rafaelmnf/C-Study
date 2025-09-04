#include <stdlib.h> 
//biblioteca de funções do sistema operacional
#include <stdio.h> 
//biblioteca de funções de entrada e saida
#include <locale.h>
/*Outras bibliotecas:
math.h -> funções matemáticas
time.h -> manipulação de dados em Data e Hora
string.h -> manipulação de cadeia de char
conio.h -> manipulação do cursor na tela
*/

#define tam 5
//variavel constante global do código

/*Tipos em C:
char %c
int %d ou %i
float %f
string -> char[] 
double %s -> é um float mais preciso, ele usa mais casas decimais 
*/

/*Operações:
+,-,*,/,% (resto da divisão inteira), ++, --
*/
// Para exibir duas variaveis na mesma linha é só juntar printf("%d %f", j,x);

/*Formatação:
\n Nova linha
\t Tabulação
\" Escreve aspas
\\ Escreve a Barra
%% \\Escreve o simbolo da porcentagem
*/

//Operadores relacionais(==,!=,<,<=,>,>=)
//Operadores logicos(&&, ||, !())

// Se a função não retornar nada, ela pode ser declarada como "void"

// Tamanho do vetor é fixo, conhecido e definido no início do programa -> int vet[3] = {2,9,1}

int main () {
    // deixar em portugues
    setlocale(LC_ALL, "portuguese");
    int num = 0;
    printf("Digite um numero inteiro:\n");
    //Ler um valor, tipo do valor, e o endereço que será registrado esse valor(para mais de um valor, separe por virgulas em ordem)
    scanf("%d", &num);
    
    int constant;
    while(constant > 0 && constant) {

    }
    /*O do -> while é a mesma coisa que somente o while, contudo, ele faz o código, e depois verifica, só muda a ordem de rodar o código, então varia conforme sua utilização*/ 
    do {

    } while(constant);
    //true or false
    /*Quando o comando (Break;) é utilizado dentro de um comando "for" o laço é imediatamente interrompido e o programa continua a execução no comando seguinte ao comando for */

    /*A diferença é que o comando (continue) simplesmente interrompe a execução da iteração corrente passando para a próxima iteração do laço, se houver.*/

    /*return e exit(1) são usados para terminar a execução de um programa, mas de maneiras diferentes. return é usado para retornar de uma função, enquanto exit(1) encerra o programa inteiro*/
    for (int i=0; i < 4; i++){

    }

    switch (constant)
    {
    case 4:
        /* code */
        break;
    
    default:
    // algo padrao caso nenhum caso for achado
        break;
    }

    //Strings:
    /*Usando a biblioteca <ctype.h>
    Principais Funções:
        - islower "Decide se o argumento representa uma letra minúscula"
            USO: if (islower(variavel[0])) - retorna true or false
        - isupper "Decide se o argumento representa uma letra maiúscula"
            USO: if (isupper(variavel[0]))
        - toupper "Recebe uma letra e devolve a correspondente letra maiúscula"
            USO: LETRA = toupper (letra);
                 if (toupper(letra)).
        - tolower "Recebe uma letra e devolve a correspondente letra minúscula"
            USO: letra = tolower (LETRA);
                 if (toupper(LETRA))
        - isdigit "Decide se o argumento é um dígito Decimal (0 1 2 3 4 5 6 7 8 9)"
            USO: if (isdigit (c))

        STRINGS são cadeias de caracteres que termina com '\0' --> é representado por uma cadeia de caracteres delimitada por aspas duplas (como em “ABCD”);
            O tamanho declarado deve ser sempre 1 a mais que o número de caracteres efetivos a serem armazenados por causa do '\0'
            EX: char cidade[5] = "Lins";
    */

    /*<string.h> inclui funções de manipulação de strings: 
        - strlen - Contar o número de caracteres de uma string, sem contar o \0 final.
        - strcpy(dest, src) - Copia uma string para outra
        - strcat(dest, src) - Concatena strings (adiciona no final)
        - strcmp(s1, s2) - Compara strings(ordem alfabética) --> (0 se forem iguais), (<0 se s1 < s2) e (>0 se s1 > s2)
            USO: if(strcmp(um, dois) > 0){
             strcpy (aux, um);
             strcpy (um, dois);
             strcpy(dois, aux);
             }  */


    char cidade[20];
    scanf("%s", &cidade); // só funciona se n tiver espaços em branco
    fgets(cidade, sizeof(cidade), stdin); //são lidos todos até digitar enter
    // fgets já limita a quantidade necessária para pegar a variavel, evitando acumulo de lixo

    /*-  O \n só aparece se couber no tamanho máximo que você passou para o fgets().
      -  O \0 sempre está lá no final, é o terminador de string*/
    // Remove o \n final, se existir
    int len = strlen(cidade);
    if (len > 0 && cidade[len - 1] == '\n') {
        cidade[len - 1] = '\0';
    }

    return 0;
}