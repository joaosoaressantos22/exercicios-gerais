#include "esfera_utils.h"
#include <math.h>

float calcula_volume(float R){
    return ((4*pow(R,3)*PI)/3);
}

float calcula_area(float R){
    return (4*pow(R, 2)*PI);
}