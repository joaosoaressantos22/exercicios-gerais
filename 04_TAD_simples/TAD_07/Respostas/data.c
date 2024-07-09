
#include <stdio.h>
#include "data.h"
/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia; data.mes = mes; data.ano = ano;
    return data;
}

void ImprimeMesExtenso(tData data){
    switch (data.mes)
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
void ImprimeDataExtenso(tData data){
    printf("%d de ", data.dia); ImprimeMesExtenso(data); printf(" de %d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int VerificaBissexto(tData data){
    if (data.ano%4 == 0)return 1;
    else return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int NumeroDiasMes(tData data){
    if (data.mes == 2){
        if(VerificaBissexto(data) == 1) return 29;
        else if (VerificaBissexto(data) == 0) return 28;
    }
    else if (7 >= data.mes > 0){
        if (data.mes%2 != 0){
            return 31;
        }
        else return 30;
    }
    else if (7 < data.mes <= 12){
        if (data.mes%2 == 0){
            return 31;
        }
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

int VerificaDataValida(tData data){
    if (NumeroDiasMes(data) >= data.dia) return 1;
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
int ComparaData(tData data1, tData data2){
    if (VerificaDataValida(data1) == 1 && VerificaDataValida(data2) == 1){

        if(data1.ano > data2.ano) return 1;

        else if (data1.ano == data2.ano){

            if(data1.mes > data2.mes){
                return 1;
            }
            else if (data1.mes == data2.mes){

                if (data1.dia > data2.dia)return 1;
                
                else if (data1.dia == data2.dia){

                    return 0;
                }
                else if (data1.dia < data2.dia) return -1;
            }

            else if(data1.mes < data2.mes) return -1;

        }

        else if (data1.ano < data2.ano) return -1;
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int CalculaDiasAteMes(tData data){
    int dias = 0;
    for (int i = 1; i < data.mes; i++) dias += NumeroDiasMes(data);  
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
int CalculaDiferencaDias(tData data1, tData data2){
    int diferTotal = 0;
    tData conta;
    if (ComparaData(data1, data2) == 1){
        //printf("%d", conta.ano);
        conta = data1;
        for (conta.ano; conta.ano >= data2.ano; conta.ano--){
            if (VerificaBissexto(conta) == 1) diferTotal += 366;
            else if (VerificaBissexto(conta) == 0) diferTotal += 365;
        }        
        if (conta.mes > data2.mes){
            diferTotal += (CalculaDiasAteMes(data2) - CalculaDiasAteMes(conta));
            diferTotal += (data2.dia - conta.dia);
        }
    }
    else if (ComparaData(data1, data2) == -1){
        conta = data2;
        for (conta.ano; conta.ano >= data1.ano; conta.ano--){
            if (VerificaBissexto(conta) == 1) diferTotal += 366;
            else if (VerificaBissexto(conta) == 0) diferTotal += 365;
        }        
        if (conta.mes > data1.mes) diferTotal += (-CalculaDiasAteMes(data1) + CalculaDiasAteMes(conta));
        else if (conta.mes < data1.mes) diferTotal += (-CalculaDiasAteMes(conta) + CalculaDiasAteMes(data1));
        if (conta.dia > data1.dia) diferTotal += (-conta.dia + data1.dia);
        else if (conta.dia < data1.dia) diferTotal += (-data1.dia + conta.dia);
    }
    
    return diferTotal;
}
