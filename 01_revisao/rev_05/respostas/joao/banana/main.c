#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int linhas;

    int colunas;

    int elemento[100][100];

} matriz;

typedef struct {

    int entradaLinha;
    int entradaColuna;
    int saidaLinha;
    int saidaColuna;

    bool visitado[100][100];

    int linhaAtual;
    int colunaAtual;

    int entrada;
    int func;

} salvaCaminho;

typedef struct {

    char pref1;
    char pref2;
    char pref3;
    char pref4;

} preferencia;

matriz leMatriz(){

    matriz matriz;

    scanf("%d%d", &matriz.linhas, &matriz.colunas);

    for (int i = 0; i < matriz.linhas; i++){

        for (int j=0; j<matriz.colunas; j++){

            scanf("%d", &matriz.elemento[i][j]);
        }
    }

    return matriz;
}

void imprimeMatriz(matriz m, preferencia p, salvaCaminho s){

    printf("A matriz tem dimensões:%dx%d\n", m.linhas, m.colunas);

    for (int i = 0; i < m.linhas; i++){

        for (int j=0; j<m.colunas; j++){

            printf("%d ", m.elemento[i][j]);
        }
        printf("\n");
    }

    printf("\nDe inicio em:[%d][%d]\n", s.entradaLinha, s.entradaColuna);
    printf("Saida em: [%d][%d]\n", s.saidaLinha, s.saidaColuna);

    printf("De preferencia em:%c%c%c%c\n", p.pref1, p.pref2, p.pref3, p.pref4);
}

preferencia definePreferencia(){

    preferencia p;

    scanf(" %c%c%c%c", &p.pref1, &p.pref2, &p.pref3, &p.pref4);

    return p;
}

salvaCaminho defineEntrada(){
    salvaCaminho s;

    scanf("%d%d", &s.entradaLinha, &s.entradaColuna);
    scanf("%d%d", &s.saidaLinha, &s.saidaColuna);
    s.entradaLinha = s.entradaLinha - 1;
    s.entradaColuna = s.entradaColuna - 1;
    s.saidaLinha = s.saidaLinha - 1;
    s.saidaColuna = s.saidaColuna - 1;
    
    s.entrada = 1;

    s.linhaAtual = s.entradaLinha;
    
    s.colunaAtual = s.entradaColuna;

    return s; 
}



salvaCaminho movimentaJogador(const char pref, matriz m,  salvaCaminho s){
    
    if(s.entrada == 1){
        printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
    }

    s.entrada = 2;

    switch (pref)

    {
    case 'B':

        if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
            s.visitado[s.linhaAtual][s.colunaAtual] = true; //Atualiza a posicao
            s.linhaAtual++;
            printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
            s.func = 1;
            return s;
        }

        else {
            //printf("saiu aqui");
            s.func = 2;
            return s;
        }
        break;
    case 'D':
        if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
            s.visitado[s.linhaAtual][s.colunaAtual] = true;
            
            s.colunaAtual++;
            printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
            s.func = 1;
            return s;
        }
        else {
            //printf("saiu aqui, ");
            s.func = 2;
            return s;
        }
        break;
    case 'E':
        if (s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
            s.visitado[s.linhaAtual][s.colunaAtual] = true;
            
            s.colunaAtual--;
            printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
            return s;
        }
        else {
            //printf("saiu aqui");
            s.func = 2;
            return s;
        }
        break;
    case 'C': //CASO C SEJA A PRIMEIRA 
        if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
            s.visitado[s.linhaAtual][s.colunaAtual] = true; 
            
            
            s.linhaAtual--;
            printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);
            return s;

        }
        else {
            s.func = 2;
            return s;
        }
        break; //FIM DO CASO C COMO PRIMEIRA 
    default:
        break;
    }

    //printf("(%d,%d)\n", s.linhaAtual + 1, s.colunaAtual + 1);

}

void organizaJogo(matriz m, preferencia p, salvaCaminho s){

    s.func = 1;

    if(s.linhaAtual != s.saidaLinha || s.colunaAtual != s.saidaColuna){

        if (s.func == 1){

            s = movimentaJogador(p.pref1, m,  s);
            //exit(1);
            if (s.func != 1){

                s = movimentaJogador(p.pref2, m, s);

                if (s.func != 1){

                    s = movimentaJogador(p.pref3, m, s);

                    if (s.func != 1){

                        s = movimentaJogador(p.pref4, m, s);

                    }
                }
            }

        }

        organizaJogo(m, p, s);

    }


}
int main(){

    matriz m;

    preferencia p;

    salvaCaminho s;

    m = leMatriz();

    s = defineEntrada();

    p = definePreferencia();

    organizaJogo(m, p, s);  

    printf("\n");

    return 0;
}