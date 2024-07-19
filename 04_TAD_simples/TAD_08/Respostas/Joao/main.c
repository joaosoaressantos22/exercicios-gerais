#include <stdio.h>
#include "departamento.h"

int main(){
    int numCen, m1, m2, m3;
    float mediaGeral;
    char nome[STRING_MAX], diretor[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    scanf("%d", &numCen);
    tDepartamento dep[numCen];
    for (int i = 0; i < numCen; i++){
        scanf("%s\n%s\n%s\n%s\n%s\n%d %d %d", nome, diretor, c1, c2, c3, &m1, &m2, &m3);
        if (validaMediaDepartamento(m1) == 1 &&  validaMediaDepartamento(m2) == 1 && validaMediaDepartamento(m3) == 1){
            dep[i] = criaDepartamento(c1, c2, c3, nome,m1, m2, m3, diretor);
            mediaGeral = calculaMediaGeralDepartamento(dep[i]);
            dep[i].media_geral = mediaGeral;
            
        }
    }

    ordenaPorMediaDepartamentos(dep, numCen);

    for (int i = 0; i < numCen; i++) imprimeAtributosDepartamento(dep[i]);
    return 0;
}