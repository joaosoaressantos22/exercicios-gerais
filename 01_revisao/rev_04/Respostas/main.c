#include <stdio.h>
#include <math.h>

int convertDecimalToOctal(int decimalNumber);

int main() {

    int decimalNumber;

    scanf("%d", &decimalNumber);

    printf("%d = %d em octal", decimalNumber, convertDecimalToOctal(decimalNumber));

    return 0;
}

int convertDecimalToOctal(int decimalNumber) {
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i; //Pega o resto da divisao e eleva multiplica por 10^i
        decimalNumber /= 8; //Divide o valor obtido por 8
        i *= 10; // Aumenta a potencia
    }

    return octalNumber;
}
