#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano){
    if (mes >=01 && mes <=12){ // Cada ano tem 12 meses, ou seja para validar essa condição primeiro tem de ser estabelicida. 
        if (mes == 04 || mes == 06 || mes == 9 || mes == 11){ //Verifica os meses com 30 dias 
            if (dia >= 01 &&  dia <= 30){ //Valida caso a condição seja satisfeita 
                return 1;
            }
            else {
                return 0; //Nao valida caso essa condição nao seja satisfeita 
            }
        }
        if (mes == 02){ //Para os meses bissestos 
            if (verificaBissexto(ano) == 1){ // Para fevereiro primeiro tem que checar se o ano é bissexto 
                if (dia >= 01 && dia <=29){ //Caso tenha 29 dias valida 
                    return 1;
                }
                else {
                    return 0; //Nao valida caso nao tenha 29 dias
                }
            }
            if (verificaBissexto(ano) == 0){ //Caso o ano nao seja bissexto verifica de mesma forma 
                if (dia >= 01 && dia <= 28){ 
                    return 1; 
                }
                else {
                    return 0; 
                }
            }
        }
        else{ // Para os outros meses todos tem 31 dias
            if (dia <= 31){
                return 1; // Ou seja retorna 1 caso tenha os 31 dias
            }
            else {
                return 0;
            }
        }
    }
    else{
        return 0; // Caso nao tenha 12 meses não é bissexto 
    }

}
void imprimeMesExtenso(int mes){
    struct Meses { //Declara a struct localmente que tem o máximo de 20 caractéres
        char nome [20]; //Define um char de 20 caracteres  
    };
    struct Meses meses[12] = { //Cria uma struct com um array de 12 meses, o valor do mes digitado corresponde ao mes por extenso na struct
        {"Janeiro"}, {"Fevereiro"}, {"Março"}, {"Abril"}, {"Maio"}, {"Junho"},
        {"Julho"}, {"Agosto"}, {"Setembro"}, {"Outubro"}, {"Novembro"}, {"Dezembro"}
    };  

    printf("%s\n", meses[mes].nome); //Printa o mes 
}

void imprimeDataExtenso(int dia, int mes, int ano){
    struct Dias {
        char numero[20]; //Define um char de 20 caracteres 
    }; 
    if (dia >= 1 && dia <= 9){
        struct Dias dias [10] = {
        "Um", "Dois", "Três", "Quatro", "Cinco", "Seis",
        "Sete", "Oito", "Nove"
        };

    } 
    if (dia >= 10 && dia <= 19){
        struct Dias dias [10]= {
            "Dez", "Onze", "Doze", "Treze", "Quatorze", "Quinze",
            "Dezesseis", "Dezessete", "Dezeoito", "Dezenove"
        };
    }
    imprimeMesExtenso(mes);
    printf("%d", ano); 
}


int verificaBissexto(int ano){
    if (ano %4 == 0){ // Caso o resto da divisão seja 0 o ano é bissexto
        return 1; 
    }
    else{
        return 0; //Caso o contrário o ano não é bissexto 
    }
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if (verificaBissexto(ano) == 1){
    }
    else{

    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){

}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

}
