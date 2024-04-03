#include "temperature_conversor.h"
#include <stdio.h>

int main(){
    float temp;
    char t1, t2;
    scanf("%f %c %c", &temp, &t1, &t2);
    printf("\n");
    switch (t1)
    {
    case 'c':
        if (t2 == 'f') printf("Temperature: %.2fF°\n", convert_temperature(temp,convert_celsius_to_fahrenheit));
        else if (t2 == 'k')printf("Temperature: %.2fK\n", convert_temperature(temp,convert_celsius_to_kelvin));
        break;
    case 'f':
        if (t2 == 'k') printf("Temperature: %.2fK\n", convert_temperature(temp,convert_fahrenheit_to_kelvin));
        else if (t2 == 'c') printf("Temperature: %.2fC°\n", convert_temperature(temp,convert_fahrenheit_to_celsius));
        break;
    case 'k':
        if (t2 == 'f') printf("Temperature: %.2fF°\n",convert_temperature(temp,convert_kelvin_to_fahrenheit));
        else if (t2 == 'c') printf("Temperature: %.2f°\n",convert_temperature(temp,convert_kelvin_to_celsius));
        break;
    default:
        break;
    }
    return 0;
}