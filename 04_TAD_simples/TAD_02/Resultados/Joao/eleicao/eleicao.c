#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    eleicao.totalEleitores = 0, eleicao.totalEleitores = 0, eleicao.totalGovernadores = 0, eleicao.totalPresidentes = 0;
    eleicao.votosBrancosGovernador = 0, eleicao.votosBrancosPresidente = 0, eleicao.votosNulosGovernador = 0, eleicao.votosNulosPresidente = 0;
    return eleicao;
}

tEleicao decideGanhador(tEleicao eleicao){
    bool empateP = false;
    bool empateG = false;
    //printf("%s tem mais votos\n", eleicao.presidentes[1].nome);
    for (int j = 1; j < eleicao.totalPresidentes; j++){
        if (eleicao.presidentes[0].votos < eleicao.presidentes[j].votos){
            printf("%s", eleicao.presidentes[j].nome);
            eleicao.presidentes[0] = eleicao.presidentes[j];
            //printf("trocou");
            empateP = false;
        }
        else if (eleicao.presidentes[0].votos == eleicao.presidentes[j].votos){  
            empateP = true;
        }
    }
    for (int i = 1; i < eleicao.totalGovernadores; i++){
        if (eleicao.governadores[0].votos < eleicao.governadores[i].votos){
            eleicao.governadores[0] = eleicao.governadores[i];
            empateG = false;
            //printf("%s tem mais votos\n", eleicao.governadores[0].nome);
        }
        else if (eleicao.governadores[0].votos == eleicao.governadores[i].votos){
            empateG = true;
        }
    }
    if (empateG == true){
        eleicao.totalGovernadores = 0;
    }
    if (empateP == true){
        eleicao.totalPresidentes = 0;
    }
    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */

tEleicao CadastraCandidatos(tEleicao eleicao, int totalCand){
    tCandidato cand;
    int k = 0; int j = 0;
    for (int i = 0; i < totalCand; i++){
        cand = LeCandidato();
        if (ObtemCargo(cand) == 'P' && eleicao.totalPresidentes < MAX_CANDIDATOS_POR_CARGO){
            eleicao.presidentes[j] = cand;
            j++;
            eleicao.totalPresidentes++;
        }
        else if (ObtemCargo(cand) == 'G' && eleicao.totalGovernadores < MAX_CANDIDATOS_POR_CARGO){
            eleicao.governadores[k] = cand;
            k++;
            eleicao.totalGovernadores++;
        }
    }
    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int totalCandidatos;
    bool achouNulo = true;
    eleicao.totalPresidentes = 0, eleicao.totalGovernadores = 0;
    scanf("%d", &totalCandidatos);
    eleicao = CadastraCandidatos(eleicao, totalCandidatos);
    scanf("%d", &eleicao.totalEleitores);
    for (int i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
        achouNulo = true;
        if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[i + 1])){
            return eleicao;
        }
        for (int j = 0; j < eleicao.totalPresidentes; j++){
            if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0){
                eleicao.votosBrancosPresidente++;
            }
            else if (ObtemVotoPresidente(eleicao.eleitores[i]) == eleicao.presidentes[j].id){
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                achouNulo = false;
            }
        }
        if (achouNulo == true){
            eleicao.votosNulosPresidente++;
        }
        achouNulo = true;

        for (int k = 0; k < eleicao.totalGovernadores; k++){
            if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0){
                eleicao.votosBrancosGovernador++;
            }
            else if (ObtemVotoGovernador(eleicao.eleitores[i]) == eleicao.governadores[k].id){
                eleicao.governadores[k] = IncrementaVotoCandidato(eleicao.governadores[k]);
                achouNulo = false;
            }
        }
        if (achouNulo == true){
            eleicao.votosNulosGovernador++;
        }
    }
    for (int l = 0; l < eleicao.totalEleitores; l++){
        if (EhMesmoEleitor(eleicao.eleitores[l], eleicao.eleitores[l + 1]) == 1){
            eleicao.totalEleitores = 0;
            return eleicao;
        }
    }
    //Sort presidente ganhador e vencedor
    eleicao = decideGanhador(eleicao);
    return eleicao;
}


/**lk
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){
    if (eleicao.totalEleitores != 0){
        printf("- PRESIDENTE ELEITO: ");
        if(eleicao.totalPresidentes != 0){
        ImprimeCandidato(eleicao.presidentes[0], CalculaPercentualVotos(eleicao.presidentes[0], eleicao.totalEleitores));
        }
        else if (eleicao.presidentes[0].votos < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
            printf("SEM DECISAO \n");
        }
        else if (eleicao.totalPresidentes == 0){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        printf("- GOVERNADOR ELEITO: ");
        if (eleicao.totalGovernadores != 0){
            ImprimeCandidato(eleicao.governadores[0], CalculaPercentualVotos(eleicao.governadores[0], eleicao.totalEleitores));
        }
        else if (eleicao.governadores[0].votos < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
            printf("SEM DECISAO\n");
        }
        else if (eleicao.governadores == 0){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
        printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador + eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
    }
    else{
        printf("ELEICAO ANULADA");
    }
}