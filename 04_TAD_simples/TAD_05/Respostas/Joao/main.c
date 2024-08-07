#include <stdio.h>
#include "conta.h"
#include "usuario.h"

int main(){
    int maxConta, opcao, numC, saque;
    int i = 0;
    char nome[50];
    char cpf[15];
    scanf("%d", &maxConta);
    tConta conta[maxConta];
    while (1){
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            return 0;
            break;
        case 1:
            scanf("%d %d", &numC, &saque);
            for (int j = 0; j <maxConta; j++){
                if (VerificaConta(conta[j], numC) == 1){
                    conta[j] = SaqueConta(conta[j], saque);
                } 
            }
            break;
        case 2:
            scanf("%d %d", &numC, &saque);
            for (int j = 0; j <maxConta; j++){
                if (VerificaConta(conta[j], numC) == 1){
                    conta[j] = DepositoConta(conta[j], saque);
                } 
            }
            break;
        case 3:
            scanf("%s %s %d", nome, cpf, &numC);
            conta[i] = CriaConta(numC, CriaUsuario(nome,cpf));
            i++;
            //printf("%d", i);
            break;
        case 4:
            printf("===| Imprimindo Relatorio |===\n");
            for (int j = 0; j < i;  j++){
                ImprimeConta(conta[j]);
            }
            break;
        default:
            break;
        }
    }
    return 0;
}