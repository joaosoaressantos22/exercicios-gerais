#include "esfera_utils.h"
#include <stdio.h>
float R;  
int main(){
    scanf("%f", &R);
    printf("A area é: %f\n",calcula_area(R));  
    printf("O volume da esfera é: %f\n", calcula_volume(R)); 
    return 0; 
}
