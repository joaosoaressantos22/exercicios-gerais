
#include <stdio.h>
#include "data.h"
/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Feveriro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        printf("INVALIDO");
        break;
    }
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ", dia); imprimeMesExtenso(mes); printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if (ano%4 == 0)return 1;
    else return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if (mes == 2){
        if(verificaBissexto(ano) == 1) return 29;
        else if (verificaBissexto(ano) == 0) return 28;
    }
    else if (0 < mes <= 7 && mes != 2){
        if (mes%2 != 0) return 31;
        else return 30;
    }
    else if (7 < mes <= 12){
        if (mes%2 != 0) return 31;
        else return 30;
    }
}
/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */

int verificaDataValida(int dia, int mes, int ano){
    if (numeroDiasMes(mes, ano) >= dia) return 1;
    else return 0;
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
    if (verificaDataValida(dia1, mes1, ano1) == 1 && verificaDataValida(dia2,mes2,ano2) == 1){

        if(ano1 < ano2) return 1;

        else if (ano1 == ano2){

            if(mes1 < mes2) return 1;

            else if (mes1 == mes2){

                if (dia1 < dia2)return 1;
                
                else if (dia1 == dia2) return 0;

                else if (dia1 > dia2) return -1;
            }

            else if(mes1 > mes2) return -1;

        }

        else if (ano1 > ano2) return -1;
    }
}

void imprimeData(int dia, int mes, int ano){
    printf("%d/%d/%d", dia, mes, ano);
}
/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int dias = 0;
    for (int i = 1; i < mes; i++) dias += numeroDiasMes(i,ano);  
    return dias;
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
    int difer = 0;
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        for (int i = ano2; i > ano1; i--){
            if (verificaBissexto(i) == 1) difer += 366;
            else if (verificaBissexto(i) == 0) difer += 365;
        }
        if (mes1 > mes2){
            difer += (calculaDiasAteMes(mes1, ano2)) - (calculaDiasAteMes(mes2, ano2));
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
        else if (mes2 == mes1){
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
        if (mes1 < mes2){
            difer += (calculaDiasAteMes(mes2, ano2)) - (calculaDiasAteMes(mes1, ano2));
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
    }
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        for (int i = ano1; i > ano2; i--){
            if (verificaBissexto(i) == 1) difer += 366;
            else if (verificaBissexto(i) == 0) difer += 365;
        }
        if (mes2 > mes1){
            difer += (calculaDiasAteMes(mes2, ano2)) - (calculaDiasAteMes(mes1, ano2));
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
        else if (mes2 == mes1){
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
        if (mes2 < mes1){
            difer += (calculaDiasAteMes(mes1, ano2)) - (calculaDiasAteMes(mes2, ano2));
            if (dia2 > dia1) difer += (dia1 - dia2);
            else if (dia2 < dia1) difer += (dia2 - dia1);
        }
    }
    return difer;
}
void imprimeProximaData(int dia, int mes, int ano){
    if (numeroDiasMes(mes, ano) == dia && mes == 12) printf("A data seguinte é: 01/01/%d", ano + 1);
    else if (numeroDiasMes(mes, ano) == dia && mes != 12) printf("A data seguinte é: 01/%d/%d",mes + 1, ano);
    else printf("A data seguinte é: %d/%d/%d\n",dia + 1, mes, ano);
}