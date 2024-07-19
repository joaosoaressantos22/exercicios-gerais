#include "empresa.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int qntEmpresas; 
    scanf("%d\n", &qntEmpresas);
    tEmpresa empresa[qntEmpresas];
    tFuncionario funcionario;
    for (int j = 0; j < qntEmpresas; j++){
        empresa[j] = leEmpresa();
        //printf("Empresa: %d Func: %d\n",empresa[j].id ,empresa[j].qtdFuncionarios);
        for (int i = 0; i < empresa[j].qtdFuncionarios; i++){
            funcionario = leFuncionario();
            empresa[j] = contrataFuncionarioEmpresa(empresa[j], funcionario);
        }
    }
    for (int k = 0; k < qntEmpresas; k++){
        imprimeEmpresa(empresa[k]);
    }
    return 0;
}