#include "matrix_utils.h"
#include <stdio.h> 

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matriz;
    matriz.cols = cols; matriz.rows = rows;
    return matriz;
}

tMatrix MatrixRead(tMatrix matrix){
    for (int i = 0; i <matrix.rows; i++){  // "Nested" loop para receber as dimensões e vos valores da matriz  
        for (int j =0; j <matrix.cols; j++){ // Explicação do nested loop no "matrix_print"
            scanf("%d", &matrix.data[i][j]); 
        }
    } 
    return matrix;
}
void MatrixPrint(tMatrix matrix){
    for (int i=0; i <matrix.rows; i++){ 
        printf("|");
        for (int j =0; j<matrix.cols; j++){ 
            if(j == matrix.cols - 1){
                printf("%d|", matrix.data[i][j]); 
            }
            else{
                printf("%d ", matrix.data[i][j]); 
            }
        }  
        printf("\n"); 
    }
    printf("\n");
}
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if (matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){              
        return 1;
    }
    else {
        return 0;  
    }

}
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    return PossibleMatrixSum(matrix1, matrix2);
}
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if (matrix1.cols == matrix2.rows){ //Verifica se é possível multiplicar as matrizes, no caso se o número de colunas da primeira é igual o número de linhas da segunda e vice versa 
        return 1;
    }
    else{
        return 0; 
    }
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){

    if (PossibleMatrixSum(matrix1, matrix2) == 1){
        for (int i =0; i< matrix1.rows; i++){ // Cria um nested loop (Explicado na "matrix_print"), e adiciona a soma dos resultados de matrix1 e matrix2 em "result". 
            for (int j = 0; j<matrix1.cols; j++){
                matrix1.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
            }
        }
        return matrix1;
    }
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    if (PossibleMatrixSub(matrix1, matrix2) == 1){
        for (int i =0; i< matrix1.rows; i++){
            for (int j = 0; j<matrix1.cols; j++){
                matrix1.data [i][j] = matrix1.data[i][j] - matrix2.data[i][j];
            }
        }
        return matrix1;
    }
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result.cols = matrix1.cols, result.rows = matrix2.cols;
    if (PossibleMatrixMultiply(matrix1, matrix2) == 1){
        for (int i =0; i< matrix1.rows; i++){  // Ja ja explico 
            for (int j = 0; j<matrix2.cols - 1; j++){
                result.data[i][j] = 0;
                for (int k =0; k <matrix2.rows; k++){
                    result.data[i][j]+= matrix1.data[i][k] * matrix2.data[k][j]; 
                }
            }
        }
        return result;
    }
}
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result;
    result = matrix;
    for (int i =0; i< matrix.rows; i++){
        for (int j = 0; j<matrix.cols; j++){
            result.data[j][i] = matrix.data[i][j];  //Substitui os valores de linhas pelo de colunas para conseguir achar a transposta e salva no resultados. 
        }
    }
    return result;
}
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    for (int i =0; i< matrix.rows; i++){
        for (int j = 0; j<matrix.cols; j++){
            matrix.data[i][j] = matrix.data[i][j] * scalar; // Pega os valores da matriz escolhida na main e multiplica pelo escalar desejado
        }
    }
    return matrix;
}

