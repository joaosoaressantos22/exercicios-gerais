#include "string_utils.h"
#include "constantes.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int tamString = 0;
/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    tamString  = 0;
    while (true){
        if (str[tamString] != '\0'){
            tamString++;
        }
        else return tamString; 
    } 
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    tamString  = 0;
    while (true){
        if (src[tamString] != '\0'){
            dest[tamString] = src[tamString];
            //exit(1);
            tamString++;
        }
        else break; 
    } 
    dest[tamString] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    for (int i = 0; i < string_length(str); i++){
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i] - 32;
        }
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    for (int i = 0; i < string_length(str); i++){
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i] + 32;
        }
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    for (int i = 0, j = string_length(str) - 1; i <= j; i++, j--) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
