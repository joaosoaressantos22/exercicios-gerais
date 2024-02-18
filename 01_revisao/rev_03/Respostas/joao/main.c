#include <stdio.h>
#include <stdbool.h>

bool repetiu = false; //Declarada variavel booleana repetiu, caso nao haja elementos unicos

typedef struct { //Estrutura do livro declarada 
    int id; 
}livro; 

void sort(int array[], int tam){ //Organiza de maneira crescente um array, no caso o eleUni e printa o valor

    for (int i = 0; i < tam - 1; i++){

        for (int j = 0; j < tam - 1; j++){

            if (array[j]> array[j+1]){

                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; 

            }

        }

    }

    for (int k = 0; k < tam; k++){
        printf("%d \n", array[k]); 
    }

}

void leLivros(int n){ //Recebe a quantidade de livros
    int eleUni[n]; //Array que vai salvar os elementos unicos
    int z = 0; 
    livro livro[n]; //Estrutura de varios livros. 

    for (int i = 0; i < n; i++){
        scanf ("%d", &livro[i].id); //Salva os ids dos livros 
    } 

    for (int j = 0; j< n; j++){

        int cnt = 0;

        for (int k = 0; k < n; k++){

            if (livro[j].id == livro[k].id){
                cnt++;
            } 

        }

        if (cnt == 1){
            eleUni[z] = livro[j].id; //Salva os elementos unicos
            z++; 
            repetiu = true; //Se existe elementos unicos bota como true a variavel booleana repetiu 
        }
    } 
    sort(eleUni, z); //Organiza os elementos unicos de forma crescente
}

int main(){
    int n; 
    scanf("%d", &n);
    leLivros(n);
    if (repetiu == false){
        printf("NENHUM\n"); 
    }

    return 0; 
}
