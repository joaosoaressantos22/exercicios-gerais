#include "livro.h"
#include <stdio.h>

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro(){
    tLivros livr;
    scanf("%s\n%s\n%d\n", livr.titulo, livr.autor, &livr.anoPublicacao);
    return livr;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro){
    printf("Titulo: %s\nAutor: %s"
    "\nAno de Publicacao: %d\n\n", livro.titulo, livro.autor, livro.anoPublicacao);
}
