#include "temperature_conversor.h"
#include <stdio.h>
/**
 * @brief Converte uma temperatura em Celsius para Kelvin.
 * @param temperature A temperatura em Celsius.
 * @return A temperatura em Kelvin.
 */
float convert_celsius_to_kelvin(float temperature){
    return temperature + 273.15;
}

/**
 * @brief Converte uma temperatura em Celsius para Fahrenheit.
 * @param temperature A temperatura em Celsius.
 * @return A temperatura em Fahrenheit.
 */
float convert_celsius_to_fahrenheit(float temperature){
    return ((temperature * 1.8) + 32);
}

/**
 * @brief Converte uma temperatura em Kelvin para Celsius.
 * @param temperature A temperatura em Kelvin.
 * @return A temperatura em Celsius.
 */
float convert_kelvin_to_celsius(float temperature){
    return temperature - 273.15;
}

/**
 * @brief Converte uma temperatura em Kelvin para Fahrenheit.
 * @param temperature A temperatura em Kelvin.
 * @return A temperatura em Fahrenheit.
 */
float convert_kelvin_to_fahrenheit(float temperature){
    return(convert_celsius_to_fahrenheit(convert_kelvin_to_celsius(temperature)));
}

/**
 * @brief Converte uma temperatura em Fahrenheit para Celsius.
 * @param temperature A temperatura em Fahrenheit.
 * @return A temperatura em Celsius.
 */
float convert_fahrenheit_to_celsius(float temperature){
    return ((temperature - 32) / 1.8);
}

/**
 * @brief Converte uma temperatura em Fahrenheit para Kelvin.
 * @param temperature A temperatura em Fahrenheit.
 * @return A temperatura em Kelvin.
 */
float convert_fahrenheit_to_kelvin(float temperature){
    return (convert_celsius_to_kelvin(convert_fahrenheit_to_celsius(temperature)));
}

/**
 * @brief Converte uma temperatura usando uma função de conversão dada.
 * @param temperature A temperatura a ser convertida.
 * @param convert_func A função de conversão a ser usada.
 * @return A temperatura convertida.
 */
float convert_temperature(float temperature, float convert_func(float temperature)){
    //printf("\nTemperatura: %.2f\n",convert_func(temperature));
    return convert_func(temperature);
}
