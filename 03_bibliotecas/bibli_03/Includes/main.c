#include <stdio.h>
#include "data.h"
int dia1, dia2, mes1, mes2, ano1, ano2; 

int main(){
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2,&ano2);
    verificaDataValida(dia1, mes1, ano1); 
    verificaDataValida(dia2, mes2, ano2); 
    imprimeDataExtenso(dia1, mes1, ano1); 
    imprimeDataExtenso(dia2, mes2, ano2); 
    printf("\n%d\n", calculaDiasAteMes(mes1, ano1)); 
    printf("\n%d\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2)); 
}