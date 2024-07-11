#include "biblioteca.h"
#include <stdio.h>
#include <stdbool.h>

void printaMenu(){
    printf("Lista de operacoes:"
            "\n1 - Cadastrar livros."
            "\n2 - Remover livros."
            "\n3 - Listar todos os livros cadastrados.\n\n");
}

int main(){
    int opcao, operacoes;
    tBiblioteca bibli;
    tLivros livro;
    char titulo[50];
    bibli = inicializarBiblioteca();
    scanf("%d", &operacoes);
    printaMenu();
    for (int i = 0; i < operacoes; i++){
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            livro = lerLivro();
            bibli = adicionarLivroNaBiblioteca(bibli, livro);
            break;
        case 2:
            scanf("%s", titulo);
            bibli = removerLivroDaBiblioteca(bibli, titulo);
            break;
        case 3:
            listarLivrosDaBiblioteca(bibli);
            break;
        default:
            printf("Operacao invalida!\n");
            i = operacoes;  
            break;
        }
    }
    return 0; 
}