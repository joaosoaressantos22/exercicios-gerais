#include "departamento.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
/**
 * @brief Cria um departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 * @return tDepartamento Departamento criado a partir dos valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 */
tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento dep;
    strcpy(dep.c1, c1); strcpy(dep.c2, c2);strcpy(dep.c3, c3);strcpy(dep.nome, nome);strcpy(dep.diretor,diretor);
    dep.m1 = m1; dep.m2 = m2; dep.m3 = m3;
    return dep;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento (tDepartamento depto){
    printf("\nATRIBUTOS:\n"
    "departamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d"
    "\ncurso3 => %s, media3 => %d\nmedia geral => %.2f\ndesvio padrao => %.2f\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, calculaMediaGeralDepartamento(depto), calculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento (int media){
    if (0 <= media <= 10) return 1;
    else return 0;
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto){
    float dp = 0.0;
    dp = (pow(depto.m1 - calculaMediaGeralDepartamento(depto), 2)) + (pow(depto.m2 - calculaMediaGeralDepartamento(depto), 2)) + (pow(depto.m3 - calculaMediaGeralDepartamento(depto), 2));
    return sqrt(dp/3);

}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto){
    float m1 = depto.m1, m2 = depto.m2, m3 = depto.m3;
    depto.media_geral = (m1/3 + m2/3 + m3/3);
    return depto.media_geral;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param d Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if (d[j].media_geral <= d[j + 1].media_geral){
                tDepartamento temp = d[j];
                d[j] = d[j + 1];   
                d[j + 1] = temp;
            }
        }
    }
}