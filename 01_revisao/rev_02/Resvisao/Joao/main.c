#include <stdio.h>

typedef struct{
    int cont;
    int numLin; 
    int pa; 
}info;

void leNum(){

    info info; 

    scanf ("%d", &info.numLin);

    info.cont = 1; //primeira iteração 

    info.pa = 2; 

    for (int i = 1; i <= info.numLin; i++){

        printf("%d\t", i);

        if (i == info.cont){
            info.cont = info.pa + info.cont; 
            info.pa++; 
            printf("\n");

        }

    }

}

int main(){
    leNum();
    printf("\n");
    return 0;
}