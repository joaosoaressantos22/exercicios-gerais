#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos){

    int elemento[numElementos];
    int elementoPar[numElementos];
    int soma;
    int j = 0;

    if (numElementos > 0){
        for (int i = 0; i < numElementos; i++){
            scanf("%d", &elemento[i]);
            if (elemento[i] % 2 == 0){
                elemento[i] = elementoPar[j];
                j++;
            }
        }
    }
    SomaElementosPares(vet, numElementos);
}

int main(){
    int numElementos;
    int *vet;
    int qntVet;
    scanf("%d", &qntVet);
    vet = &qntVet;
    printf("%d", *vet);
    SomaElementosPares()
    return 0;
}