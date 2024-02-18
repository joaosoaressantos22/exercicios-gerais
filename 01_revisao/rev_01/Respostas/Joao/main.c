#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
    float r;
} cord; 

int acertouAlvo(float cX, float cY, float cR, float tX, float tY, float tR){
    if ((cR + tR) < sqrt(pow(cX - tX, 2) +pow(cY,tY))){
        return 0; 
    }
    else {
        return 1; 
    }
}


int main(){
    cord coC; //Coordenada do circulo original 
    cord coT; //Coordenada do tiro
    scanf("%f%f%f%f%f%f", &coC.x, &coC.y, &coC.r, &coT.x, &coT.y, &coT.r);
    if (acertouAlvo(coC.x, coC.y, coC.r, coT.x, coT.y, coT.r) != 1){
        printf("Acertou");
    } 
    else {
        printf("Errou"); 
    }
    return 0; 
}
