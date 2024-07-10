#include "biblioteca.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca(){
    tBiblioteca bibli;
    bibli.tamanho = 0;
    return bibli;
}
/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if (biblioteca.tamanho < MAX_LIVROS){
        biblioteca.livros[biblioteca.tamanho] = livro;
        printf("Livro adicionado com sucesso!\n");
        biblioteca.tamanho++;
    }
    else printf("\nA biblioteca está cheia. Não é possível adicionar mais livros.");
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    int posicao; 
    bool encontrou = false;
    for (int i = 0; i < biblioteca.tamanho; i++){
        if(verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo) == 0){
            encontrou = true;
            posicao = i; //Encontrei a posicao do elemento que tenho que deletar
            if (posicao != 0){
                for(int j = posicao-1; j<biblioteca.tamanho-1; j++) {
                    biblioteca.livros[j + 1] = biblioteca.livros[j];
                }
            }
            else {
                biblioteca.livros[posicao] = biblioteca.livros[posicao + 1];
            }
            /* Decrement array size by 1 */
            biblioteca.tamanho--;
            printf("Livro removido com sucesso!\n");
        }
    }
    if (encontrou == false) printf("\nLivro não encontrado na biblioteca.");
    return biblioteca;
}
/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return strcmp(livro.titulo, titulo);
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    if (biblioteca.tamanho > 0){
        printf("\nLista de Livros na Biblioteca:");
        for (int i = 0; i < biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
        }
    }
    else if (biblioteca.tamanho == 0) printf("A biblioteca esta vazia!\n");
}
