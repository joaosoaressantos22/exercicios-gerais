#include "aluno.h"
#include <stdio.h>

int main(){
    tAluno aluno[40];
    int qtd;
    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++){
        aluno[i] = LeAluno();
    }
    for (int i = 0; i < qtd; i++){//BubbleSort
            for (int j = 0; j < qtd - i - 1; j++){
                if (aluno[j].matricula > aluno[j + 1].matricula){
                    aluno[qtd + 1] = aluno[j];
                    aluno[j] = aluno[j + 1];
                    aluno[j+ 1] = aluno[qtd + 1];
                }
            }
    }

    for (int i = 0; i < qtd; i++){
        if (VerificaAprovacao(aluno[i]) == 1) ImprimeAluno(aluno[i]);
    }
    return 0;
}