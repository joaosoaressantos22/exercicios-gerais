#include "esfera_utils.h"
#include <stdio.h>
float R;  
int main(){
    scanf("%f", &R);
    printf("Area: %.2f\nVolume: %.2f\n", 
            calcula_area(R), calcula_volume(R));
    return 0; 
}
