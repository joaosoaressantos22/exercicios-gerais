#include "string_utils.h"
#include <stdio.h>
#include <string.h> //Para testar somente
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"

int main(){
    char stringPri[100]; 
    char stringDest[100];
    int menuOp; 
    scanf("%[^\n]s", stringPri); 
    string_copy(stringPri, stringDest);
    while (true){
        printf("\n1 - Tamanho da string"
                "\n2 - Copiar string"
                "\n3 - Converter string para letras maiusculas"
                "\n4 - Converter string para letras minusculas"
                "\n5 - Imprimir string ao contrario\n6 - Encerrar o programa");
        scanf("%d", &menuOp);
        switch (menuOp)
            {
            case 1:
                printf("Opcao escolhida: Tamanho da string\nTamanho da String: %d\n", string_length(stringPri));
                break;
            case 2:
                printf("Opcao escolhida: Copiar string\nString copiada:%s\n", stringDest);
                break;
            case 3:
                string_upper(stringDest);
                printf("Opcao escolhida: Converter string para letras maiusculas\nString convertida para maiusculas:%s\n", stringDest);
                break;
            case 4:
                string_lower(stringDest);
                printf("Opcao escolhida: Converter string para letras minusculas\nString convertida para minusculas:%s\n", stringDest);
                break;
            case 5:
                string_reverse(stringDest);
                printf("Opcao escolhida: Imprimir string ao contrario\nString invertida:%s\n", stringDest);
                break;
            case 6:
                printf("Opcao escolhida: Encerrar o programa\n");
                return 0;
                break;
            default:
                break;
            }
    }
}