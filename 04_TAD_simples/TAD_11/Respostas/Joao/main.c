#include "loja.h"
#include <stdio.h>
#include <stdbool.h>

void printaMenu(){
    printf("0 - Sair\n1 – Abrir loja\n"
     "2 – Contratar vendedor\n3 – Registrarvenda\n"
     "4 – Relatório geral\n");
}

int main(){
    int qntLojas, id;
    int i = 0;
    float aluguel, valor_vendido,  salario, prct_comissao;
    char opcao;
    bool condicao = false;
    char nome [50]; 
    tVendedor vendedor;
    scanf("%d", &qntLojas);
    tLoja lojas[qntLojas];
    //printaMenu();
    while (true){
        condicao = false;
        scanf("%c", &opcao);
        switch (opcao)
        {
        case '0':
            return 0;
            break;
        case '1':
            if (i < qntLojas){
                scanf("%d %f", &id, &aluguel); 
                if (i != 0){
                    for (int j = 0; j < qntLojas; j++){
                        if(VerificaIdLoja(lojas[j], id) == 1) condicao = true;
                    }
                }
                if (i == 0 ||condicao == false){
                    lojas[i] = AbreLoja(id, aluguel);
                    i++;
                }
            }
            else{
                printf("nao é possivel cadastrar mais lojas\n");
            }
            break;
        case '2':
            scanf("%s %f %f\n", nome, &salario, &prct_comissao);
            vendedor = RegistraVendedor(nome, salario, prct_comissao);
            scanf("%d", &id);
            for (int j = 0; j < qntLojas; j++){
                if (VerificaIdLoja(lojas[j], id) == 1){
                    lojas[j] = ContrataVendedor(lojas[j], vendedor);
                }
            }
            break;
        case '3':
            scanf("%d %s %f", &id, nome, &valor_vendido);
            for (int j = 0; j < i; j++){
                if (VerificaIdLoja(lojas[j], id) == 1){
                    lojas[j] = RegistraVenda(lojas[j], nome, valor_vendido);
                }
            }
            break;
        case '4':
            for (int j = 0; j < i; j++){
                ImprimeRelatorioLoja(lojas[j]);
            }
            break;
        default:
            break;
        }
    }
}