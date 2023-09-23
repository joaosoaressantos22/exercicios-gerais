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
        if (mes == 02){ //Para os meses bissextos 
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
            if (dia >= 01 && dia <=31){
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
    char meses[12][10] = {"Janeiro", // Cria uma lista de meses para os meses. 
                       "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro" , "Novembro", "Dezembro"};
    printf("%s", meses[mes - 1]); //Printa o mes 
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ", dia); imprimeMesExtenso(mes); printf( " de %d\n", ano); //Printa a data por extenso 
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
    if (mes == 04 || mes == 06 || mes == 9 || mes == 11){
        return 30; //Retorna 30 caso seja alguns desses meses acima
    }
    if (mes == 2){
        if (verificaBissexto(ano) == 1){
            return 29; // Se o ano for bissexto retorna 29, numero de dias de fevereiro, vulgo mês 02. 
        }
        else {
            return 28; //Caso não retorna 28 
        }
    }
    else {
        return 31; //De resto todos os meses tem 31 dias. 
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
    if (ano1 > ano2){
        return 1;
    }
    
    if (ano1 == ano2){
        if (mes1> mes2){
            return 1;
        }
        if (mes1 == mes2){
            if (dia1>dia2){
                return 1;
            }
            if (dia2 == dia1){
                return 0;
            }
            if (dia1 < dia2){
                return -1; 
            }
        } 
        if (mes2 <mes1){
            return -1; 
        }
    }
    if (ano1 < ano2){
        return -1; 
    }
}
/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int cont = 0;
    for (int i = 1; i < mes; i ++){ 
        numeroDiasMes(i, ano); 
        cont += numeroDiasMes(i, ano);  
    }
    return cont; 
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
//Desistindo por dentro 
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    int dif = 0;

    if (ano1 > ano2){
        for (ano2; ano2 < ano1; ano2++){
            if(verificaBissexto(ano2)== 1){
                dif += 366;
            }
            else {
                dif += 365; 
            }
        } 
        if (mes1 > mes2){
            for (mes2; mes2 < mes1; mes2 ++){ // Cria umn loop de meses até chegar no mês desejado
                numeroDiasMes(mes2, ano2); //Chama a função para calcular o número de meses na iteração do mês seguinte. 
                dif += (numeroDiasMes(mes2, ano2) - dia2); // Armazena o valor de número de dias por mês na váriavel diff
            }
            dif += dia1; 
            return dif; 
        }
        if (mes1 == mes2){ //Caso os meses são iguais temos que somente calcular a diferença de dias
            if (dia1 > dia2){
                dif += (dia1 - dia2);
                return dif;  
            }
            if (dia1 == dia2){
                return dif; 
            }
            if (dia1 < dia2){
                dif += (dia2 - dia1);
                return dif; 
            }
        }
        if (mes1 < mes2){
            for (mes1; mes1 < mes2; mes1 ++){
                numeroDiasMes(mes1, ano1);
                dif += (numeroDiasMes(mes1, ano1)- dia1); 
            }
            dif += dia1; 
            return dif; 
        }
    }
    
    if (ano1 == ano2){ // Verifica se o ano é o mesmo das opções anteriores. 
        if (mes1 > mes2){
            for (mes2; mes2 < mes1; mes2 ++){ // Cria umn loop de meses até chegar no mês desejado
                numeroDiasMes(mes2, ano1); //Chama a função para calcular o número de meses na iteração do mês seguinte. 
                dif += (numeroDiasMes(mes2, ano1)- dia2); // Armazena o valor de número de dias por mês na váriavel diff
            }
            dif += dia1;
            return dif; 
        }
        if (mes1 == mes2){ //Caso os meses são iguais temos que somente calcular a diferença de dias
            if (dia1 > dia2){
                dif += (dia1 - dia2);
                return dif;  
            }
            if (dia1 == dia2){
                return dif; 
            }
            if (dia1 < dia2){
                dif += (dia2 - dia1);
                return dif; 
            }
        }
        if (mes1 < mes2){
            for (mes1; mes1 < mes2; mes1 ++){
                numeroDiasMes(mes1, ano1);
                dif +=  (numeroDiasMes(mes1, ano1) - dia1); 
            }
            dif += dia2; 
        }
    }
    
    if (ano2 > ano1){
        for (ano1; ano1 < ano2; ano1++){
            if(verificaBissexto(ano1)== 1){
                dif += 366;
            }
            else {
                dif += 365; 
            }
        } 
        if (mes1 > mes2){
            for (mes2; mes2 < mes1; mes2 ++){ // Cria umn loop de meses até chegar no mês desejado
                numeroDiasMes(mes2, ano1);
                //Chama a função para calcular o número de meses na iteração do mês seguinte. 
                dif += (numeroDiasMes(mes2, ano1) - dia2); // Armazena o valor de número de dias por mês na váriavel diff
            }
            dif += dia1; 
        }
        if (mes1 == mes2){ //Caso os meses são iguais temos que somente calcular a diferença de dias
            if (dia1 > dia2){
                dif += (dia1 - dia2);
                return dif;  
            }
            if (dia1 == dia2){
                return dif; 
            }
            if (dia1 < dia2){
                dif += (dia2 - dia1);
                return dif; 
            }
        }
        if (mes1 < mes2){
            for (mes1; mes1 < mes2; mes1 ++){
                numeroDiasMes(mes1, ano1);
                dif += (numeroDiasMes(mes1, ano1) - dia1); 
            }
            dif += dia2; 
            return dif; 
        }
    }
}
