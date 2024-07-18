#include "utils.h"

int TrocaInterios(int * n1, int * n2){
    if (*n1 > *n2){
        int numero;
        numero = *n1;
        *n1 = *n2;
        *n2 = numero;
        return 1; 
    }
    return 0;
}
