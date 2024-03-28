#include "locadora.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */

void limparBufferEntrada() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF);
}


tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.lucro = 0, locadora.numFilmes = 0;
    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for (int i = 0; i <locadora.numFilmes; i++){
        if (locadora.filme[i].codigo == codigo) return 1;
    }
    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    for (int i = 0; i <locadora.numFilmes; i++){
        if (locadora.filme[i].codigo == obterCodigoFilme(filme)) return locadora;
    }
    locadora.filme[locadora.numFilmes].codigo = filme.codigo, strcpy(locadora.filme[locadora.numFilmes].nome, filme.nome);
    locadora.filme[locadora.numFilmes].valor = filme.valor, locadora.filme[locadora.numFilmes].qtdEstoque = filme.qtdEstoque;
    locadora.filme[locadora.numFilmes].qtdAlugada = filme.qtdAlugada;
    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora){
    int x = 1; 
    int cod, val, est;
    char nom[20];
    while(1){
        x = scanf("%d,%20[^,],%d,%d", &cod, nom, &val, &est);
        if (x != 0){
            locadora.filme[locadora.numFilmes] = criarFilme(nom, cod, val, est);
            locadora.numFilmes++;
        }
        else{
            //printf("%d", x);
            break;
        }
    }
    limparBufferEntrada();
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    
    for (int i = 0; i < quantidadeCodigos; i++){
        for (int j = 0; j < locadora.numFilmes; j++){
            if (codigos[i] == obterCodigoFilme(locadora.filme[j])){    
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
                printf("Filme %d alugado\n", codigos[j]);
                //return locadora;
            }   
        }
    }
    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int x = 1;
    int qtd = 0;
    while(1){
        x = scanf("%d", &codigos[qtd]);
        qtd++;
        if (x == 0){
            limparBufferEntrada(); // Limpando o buffer antes de chamar a função alugarFilmesLocadora
            locadora = alugarFilmesLocadora(locadora,codigos,qtd);
            break; // Sair do loop após a chamada da função
        }
    }
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int inicial = quantidadeCodigos;
    for (int i; i < quantidadeCodigos; i++){
        if (codigos[quantidadeCodigos] == locadora.filme[i].codigo){
            quantidadeCodigos--;
            devolverFilme(locadora.filme[i]);
        }
    }

    if (inicial == quantidadeCodigos){
        printf("Impossível devolver filme %d", codigos[quantidadeCodigos]);
        quantidadeCodigos--;
        devolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
    }
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigos[MAX_FILMES];
    int x, qtd;
    while(1){
        x = scanf("%d", &codigos[qtd]);
        qtd++;
        if (x == 0){
            devolverFilmesLocadora(locadora,codigos,qtd);
        }
    }
    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora){

}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora){

}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora){
    
}