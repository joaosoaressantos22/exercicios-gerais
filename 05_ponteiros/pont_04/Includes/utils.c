#include "utils.h"
#include <stdio.h> 

void LeNumeros(int *array, int tamanho){ //Function read numbers, basicallu read an array of numbers and saves it in the direction which *array is pointing to 
    for (int i = 0; i < tamanho; i++){
        scanf("%d", array); //Saves the first number 
        printf("\n%d\n", *array);  
        *array++; //After saving in *array it should point to the next byte of code to save the next number
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){ //This is where i'm struggling
    *maior = *menor = array[0];
    for (int i = 0; i < tamanho; i++) {
        if (array[i] > *maior) {
            *maior = array[i];
        }

        if (array[i] < *menor) {
            *menor = array[i];
        }

        *media += array[i];
    }

    *media /= tamanho;
}

