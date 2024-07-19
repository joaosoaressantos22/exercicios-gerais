#include <stdio.h>
#include "matrix_utils.h"

int main(){
    int opcao, linha1, coluna1, linha2, coluna2, escalar, opcao2;
    tMatrix matrix1; tMatrix matrix2;
    scanf("%d%d", &linha1, &coluna1);
    matrix1 = MatrixRead(MatrixCreate(linha1, coluna1));
    scanf("%d%d", &linha2, &coluna2);
    matrix2 = MatrixRead(MatrixCreate(linha2, coluna2));
    while(1){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes");
        printf("\n4 - Multiplicação por um escalar\n5 - Transposta de uma matriz\n6 - Encerrar programa\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            MatrixPrint(MatrixAdd(matrix1, matrix2));
            break;
        case 2:
            MatrixPrint(MatrixSub(matrix1, matrix2));
            break;
        case 3:
            MatrixPrint(MatrixMultiply(matrix1, matrix2));
            break;
        case 4:
            scanf("%d %d", &escalar, &opcao2);
            if (opcao2 == 1){
                matrix1 = MatrixMultiplyByScalar(matrix1,escalar);
                MatrixPrint(matrix1);
            }
            else if (opcao2 == 2){ 
                matrix2 = MatrixMultiplyByScalar(matrix2,escalar);
                MatrixPrint(matrix2);
            }
            break;
        case 5:
            MatrixPrint(TransposeMatrix(matrix1));
            printf("\n");
            MatrixPrint(TransposeMatrix(matrix2));
            break;
        case 6:
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}