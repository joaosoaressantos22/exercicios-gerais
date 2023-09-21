#include <stdio.h>
#include "esfera_utils.h"
#include <math.h>

int main () {

float r, volume, area;

scanf("%f", &r);

CalculaArea(r, &area);

CalculaVolume(r, &volume);

printf("Area: %.2f\n", area);

printf("Volume: %.2f\n", volume);

return 0;


}
