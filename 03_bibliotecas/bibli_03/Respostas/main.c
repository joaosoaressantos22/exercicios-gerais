#include "data.h"
#include <stdio.h>

int main(){

    int dia1, dia2, mes1, mes2, ano1, ano2, antiga;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    
    imprimeDataExtenso(dia1, mes1, ano1);
    imprimeDataExtenso(dia2, mes2, ano2);
    
    antiga = comparaData(dia1, mes1, ano1,dia2,mes2, ano2);
    
    if (antiga == 1) printf("A primeira data eh mais antiga\n");
    
    else if (antiga == 0) printf("As datas são iguais\n");
    
    else if (antiga == -1) printf("A segunda data eh mais antiga\n");
    
    printf("A diferenca em dias entre as datas eh: %d dias", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
    
    return 0;
}