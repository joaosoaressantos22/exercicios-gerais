#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <string.h>

int main(){
    char string[100];
    tLocadora locadora = criarLocadora();   
    while (1){
        scanf("%s", string);
        switch (string[0])
        {
        case 'C':
            locadora = lerCadastroLocadora(locadora);
            break;
        case 'A':
            locadora = lerAluguelLocadora(locadora);
            break;
        case 'D':
            locadora = lerDevolucaoLocadora(locadora);
            break;
        case 'E':
            consultarEstoqueLocadora(locadora);
            break;
        case 'S':
            return 0;
        default:
            break;
        }
    }
    return 0;

}
