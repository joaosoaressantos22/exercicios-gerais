#include "tabuleiro.h"
#include <stdio.h>
#include <string.h>

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiroNovo;

    tabuleiroNovo.peca1 = 'X';
    tabuleiroNovo.peca1 = '0';
    tabuleiroNovo.pecaVazio	= '-';
    
    for (int i = 0; i <= TAM_TABULEIRO; i++){

        for (int j =0; j<= TAM_TABULEIRO; j++){

            tabuleiroNovo [i][j] = tabuleiroNovo.pecaVazio; 
        }
    }

    return tabuleiroNovo; 
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if (peca == PECA_1){
        tabuleiro.posicoes [y][x] = tabuleiro.peca1;
    }
    if (peca == PECA_2){
        tabuleiro.posicoes [y][x] = tabuleiro.peca2;
    }
    return tabuleiro; 
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    for (int i = 0; i <=TAM_TABULEIRO; i++){
        for (int j = 0; j<= TAM_TABULEIR; j++){
            if tabuleiro.posicoes [i][j] == tabuleiro.pecaVazio{
                return 1; 
                break;
            }
            else {
                return 0; 
                break;
            }
        }
    }
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if (tabuleiro.posicoes [y][x] != '-'){
        return 0;
    }
    else {
        return 1;
    }
}

/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if (tabuleiro.posicoes [y][x] == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y){
    if ((x > 2 || x < 0) || (y > 2 || y < 0)){
        return 1;
    }
    else {
        return 0; 
    }
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro){
    for (int i = 0; i <= TAM_TABULEIRO; i++){
        for (int j = 0; j<= TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
    }
}
