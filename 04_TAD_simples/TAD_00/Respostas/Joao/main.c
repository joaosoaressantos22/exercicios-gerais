#include "ponto.h"
#include <stdio.h>
int main(){
    Ponto ponto1; Ponto ponto2;
    scanf("%f %f %f %f", &ponto1.x, &ponto1.y, &ponto2.x, &ponto2.y);
    printf("%g\n", pto_distancia(ponto1, ponto2));
    return 0;
}