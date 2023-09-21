#include "esfera_utils.h"
#include <math.h>

void CalculaVolume(float R , float *volume){
    *volume = ((4*pow(R,3)*PI)/3);
}

void CalculaArea(float R, float *area){
    *area = (4*pow(R, 2)*PI);
}
