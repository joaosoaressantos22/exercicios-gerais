#include <stdio.h> 
#include "matrix_utils.h" 

int lin, cols, lin2, cols2;
int main (){
    scanf("%d%d", &lin, &cols);                        // Le a primeira matriz na funcção matrix_read e printa na matrix_print
    int matrix [lin][cols]; //Declara a primeira matriz
    matrix_read(lin, cols, matrix); 
    matrix_print(lin, cols, matrix); 
    scanf("%d%d", &lin2, &cols2);               // Le a segunda matriz na funcção matrix_read e printa na matrix_print
    int matrix2 [lin2][cols2];   //Declara a segunda matriz 
    matrix_read(lin2, cols2, matrix2); 
    matrix_print(lin2, cols2, matrix2); 
    int menu =0, scalar, resp, opc =0; // Declara o menu e o escalar
    int result [lin][cols]; 
    while (menu != 6){    //Cria o menu
        printf("1- Somar Matrizes\n2- Subtrair Matrizes\n3- Multiplicar Matrizes\n4- Multiplicação de Matriz por um escalar\n5-Transposta de uma matriz\n6-Encerrar programa.\n");
        scanf("%d", &menu); 
        if (menu ==1){
            if (possible_matrix_sum(lin, cols, lin2, cols2)== 1){ //Verifica se é possível somar as matrizes 
                    matrix_add(lin, cols, matrix ,lin2, cols2, matrix2, result); //retorna os valores da soma das matrizes 
            }
        }
        if (menu ==2){
            if (possible_matrix_sub(lin, cols, lin2, cols2) == 1){
                    matrix_sub(lin, cols, matrix ,lin2, cols2, matrix2, result); //retorna os valores da soma das matrizes 

            }

        }
        if (menu ==3){
            if(possible_matrix_multiply(cols2, lin)== 1){ //Verifica se é possível multiplicar as matrizes
                matrix_multiply(lin, cols, matrix, lin2, cols2, matrix2, result); 
            }
            else {

            }
        }
        if (menu ==4){
            while (opc != 10){ //Cria um menu para poder determinar as possíveis opções que o usuário tem
                printf("Digite o valor do escalar\n");
                scanf("%d", &scalar);
                printf("Qual matriz você deseja multiplicar pelo escalar? \n 1 ou 2\n"); 
                scanf("%d", &resp);
                if (resp == 1){ // Caso a resposta seja 1 realiza a conta com os valores da primeira matriz 
                    scalar_multiply(lin, cols, matrix, scalar);
                    opc = 10; 
                }
                if (resp ==2){
                    scalar_multiply(lin2, cols2, matrix2, scalar); // Caso a reposta seja 2 realiza a conta com os vlaores da segunda matriz
                    opc = 10; 
                }
                else {
                    printf("Digite uma opção valida\n"); // Caso não tenha nenhuma o loop volta para botar os valores novamente
                }
            }
            opc = 0; 
        }
        if (menu ==5){
            transpose_matrix(cols, lin, matrix, result); 
            transpose_matrix(cols2, lin2, matrix2, result); 

        }
    }
    return 0; 
}
