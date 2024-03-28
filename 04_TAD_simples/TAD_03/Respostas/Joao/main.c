#include "locadora.h"
#include "filme.h"
#include <stdio.h>

int main(){
    int idade;
    tLocadora locadora = criarLocadora();
    locadora = lerCadastroLocadora(locadora);
    locadora = lerAluguelLocadora(locadora);
    return 0;
}