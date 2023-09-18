#include <stdio.h>
#include "data.h"
int dia1, dia2, mes1, mes2, ano1, ano2; 

int main(){
    scanf("%d/%d/%d", &dia1, &mes2, &ano2);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    verificaDataValida(dia1, mes1, ano1); 
    verificaDataValida(dia2, mes2, ano2); 
    imprimeMesExtenso(mes1); 
    imprimeMesExtenso(mes2);
}