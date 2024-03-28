#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ImprimeInvertido(char* string){

    if (string != NULL){

        int tam = strlen(string); //Pego o tamanho da string
        //exit(1);

        //printf("%d", tam);

        char novoString[tam]; //Define um novo char, agora manipulavel, chamado novoString de mesmo tamanho do string dado pela funcao imprimeInvertido

        strcpy(novoString, string); //Iguala as duas strings com o strcpy

        if (tam > 0){ //Enquanto a string nao terminar

            printf("%c", novoString[tam - 1]); //Printa o valor do string de tras pra frente 

            novoString[tam-1] = '\0'; //Iguala o ultimo valor da string como 0
            
            ImprimeInvertido(novoString); //Chama a funcao com o novoString
        }
    }
}
int main(){

    char string[500];

    scanf("%[^\n]s", string);

    ImprimeInvertido(string);

    printf("\n");

    return 0;
}