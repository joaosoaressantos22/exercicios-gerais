#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int dia1, dia2, mes1, mes2, ano1, ano2, antiga;
    tData data1; tData data2;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    data1 = CriaData(dia1, mes1, ano1);
    data2 = CriaData(dia2, mes2, ano2);
    if (VerificaDataValida(data1) == 1 && VerificaDataValida(data2) == 1){
        printf("\nA primeira data é: ");
        ImprimeDataExtenso(data1);
        printf("\nA segunda data é: ");
        ImprimeDataExtenso(data2);
    }
    else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }
    antiga = ComparaData(data1, data2);
    
    if (antiga == -1) printf("A primeira data eh mais antiga\n");
    
    else if (antiga == 0) printf("As datas são iguais\n");
    
    else if (antiga == 1) printf("A segunda data eh mais antiga\n");
    //exit(1);
    printf("A diferenca em dias entre as datas eh: %d dias\n\n", CalculaDiferencaDias(data1, data2));
 
    return 0;
}