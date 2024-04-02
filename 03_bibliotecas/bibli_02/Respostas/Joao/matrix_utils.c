#include "matrix_utils.h"
#include <math.h> 
#include <stdio.h> 

void matrix_read (int rows, int cols, int matrix[rows][cols]){
    for (int i = 0; i <rows; i++){  // "Nested" loop para receber as dimensões e vos valores da matriz  
        for (int j =0; j <cols; j++){ // Explicação do nested loop no "matrix_print"
            scanf("%d", &matrix[i][j]); 
        }
    } 
}
void matrix_print(int rows, int cols, int matrix[rows][cols]){
    printf("Sua matriz é:\n\n"); 
    for (int i=0; i <rows; i++){ // Cria um loop para poder ler todos os valores da primeira linha, i representa a linha 
        for (int j =0; j<cols; j++){ // cria um loop para preencher os vaalores das colunas da primeira linha
            printf("%d ", matrix[i][j]); //leitura dos elementos da matriz 
        } // Sai do loop das colunas e soma para a próxima linha, entrando novamente no loop das colunas e assim até acabar a matriz. 
        printf("\n"); //Nova linha
    }
}
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if (rows1 == rows2){ // Verifica se tem o mesmo número de linhas as duas matrizes
        if (cols1 == cols2){ // Tendo o mesmo número de linhas verifica se tem o mesmo número de colunas                          
            return 1; //Caso satisfaça as exigencias, retorna 1. Caso contrário retorna 0. 
        }
        else{
            return 0; 
        }
    }
    else {
        return 0;  
    }

}
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if (rows1 == rows2){ // Verifica se tem o mesmo número de linhas as duas matrizes
        if (cols1 == cols2){ // Tendo o mesmo número de linhas verifica se tem o mesmo número de colunas 
            return 1; //Caso satisfaça as exigencias, retorna 1. Caso contrário retorna 0. 
        }
        else {
            return 0; 
        }
    }
    else {
        return 0;  
    }

}
int possible_matrix_multiply(int cols1, int rows2){
    if (cols1 == rows2){ //Verifica se é possível multiplicar as matrizes, no caso se o número de colunas da primeira é igual o número de linhas da segunda e vice versa 
        return 1;
    }
    else{
        return 0; 
    }
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    printf("O resultado da matriz é:\n\n");
    for (int i =0; i< rows1; i++){ // Cria um nested loop (Explicado na "matrix_print"), e adiciona a soma dos resultados de matrix1 e matrix2 em "result". 
        for (int j = 0; j<cols1; j++){
            result [i][j] = matrix1 [i][j] +  matrix2 [i][j];
        }
    }
    matrix_print(rows1, cols1, result); 
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
        printf("O resultado da matriz é:\n\n"); //Analogo ao matrixadd. 
        for (int i =0; i< rows1; i++){
            for (int j = 0; j<cols1; j++){
                result [i][j] = matrix1 [i][j] - matrix2 [i][j];
            }
        }
        matrix_print(rows1, cols1, result);
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
        printf("O resultado da matriz é:\n\n");
        for (int i =0; i< rows1; i++){  // Ja ja explico 
            for (int j = 0; j<cols2; j++){
                result [i][j] = 0;
                for (int k =0; k <rows2; k++){
                    result[i][j]+= matrix1[i][k] * matrix2[k][j]; 
                }
            }
        }
        matrix_print(rows1, cols2, result); 
}
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
     printf("O resultado da transposta da matriz é:\n\n");
    for (int i =0; i< rows; i++){
        for (int j = 0; j<cols; j++){
            result [i][j] = matrix [j][i];  //Substitui os valores de linhas pelo de colunas para conseguir achar a transposta e salva no resultados. 
        }
    }
    matrix_print(rows, cols, result);
}
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    for (int i =0; i< rows; i++){
        for (int j = 0; j<cols; j++){
            matrix [i][j] = matrix[i][j] * scalar; // Pega os valores da matriz escolhida na main e multiplica pelo escalar desejado
            printf("%d ", matrix[i][j]);
            matrix [i][j] = (matrix [i][j]/scalar);
        }
        printf("\n"); 
    }
}

