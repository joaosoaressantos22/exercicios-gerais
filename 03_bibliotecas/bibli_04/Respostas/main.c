#include "data.h"
#include <stdio.h>

int main(){

    int dia1, ano1, mes1, bissexto;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    
    if (verificaDataValida(dia1, mes1, ano1) == 1){        
        
        bissexto = verificaBissexto(ano1);
        
        if (bissexto == 1) printf("O ano informado eh bissextoa\n");
        
        else if (bissexto == 0) printf("O ano informado nao eh bissexto\n");
        
        printf("O mes informado tem %d dias\n", numeroDiasMes(mes1, ano1));
        
        imprimeProximaData(dia1, mes1, ano1);
    }
    else {
        printf("A data informada eh invalida");
    }
    return 0;
}