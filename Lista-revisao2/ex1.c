/*Elabore um programa que contenha uma função recebe 3 valores float (n1, n2, n3) e retornar o (x*x)+y+z. Os valores devem ser lidos no programa principal, o resultado também deve ser impresso no principal.
• Construa essa função de duas maneiras diferentes, respeitando os cabeçalhos abaixo:
a. float calculo(float x, float y, float z)
b. void calculo(float x, float y, float z, float *r)*/

#include <stdlib.h>
#include <stdio.h> 


float calculo(float x, float y, float z) {
    return (x*x) + y + z;
}

void calculo2(float x, float y, float z, float *r) {
    *r = (x*x)+y+z;
}

int main () {
    float a, b, c;
    float resultadoA, resultadoB;
    printf("a:");
    scanf("%f", &a);
    printf("b:");
    scanf("%f", &b);
    printf("c:");
    scanf("%f", &c);

    resultadoA = calculo(a, b, c);
    printf("resultado: %f\n", resultadoA);

    calculo2(a, b, c, &resultadoB);
    printf("resultado: %f", resultadoB);

    return 0;
}