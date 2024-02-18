#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    return s; 
}

void movimentaJogador(matriz m, preferencia p, salvaCaminho s){

    s.linhaAtual = s.entradaLinha;
    
    s.colunaAtual = s.entradaColuna;

    while(s.linhaAtual != s.saidaLinha || s.colunaAtual != s.saidaColuna){

        printf("(%d,%d) ", s.linhaAtual + 1, s.colunaAtual + 1);

        switch (p.pref1)

        {
        case 'B':
            if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                s.visitado[s.linhaAtual][s.colunaAtual] = true; //Atualiza a posicao
                
                s.linhaAtual++;
            }
            else{
                switch (p.pref2)
                {
                case 'D':
                    if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                       
                        s.colunaAtual++;
                    }
                    else{
                        switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                               
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                        }
                    }
                    break;
                case 'E':
                    if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        
                        s.colunaAtual--;
                    }
                    else{
                        switch(p.pref3){

                            case 'D':
                            if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'D':
                                        if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    }
                    break;
                case 'C':
                    if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                        
                        s.linhaAtual--;
                    }
                    else{
                            switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'D':
                                        if(m.elemento[s.linhaAtual][s.colunaAtual +1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'D':
                            if (m.elemento[s.linhaAtual][s.colunaAtual+ 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual+ 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.colunaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    break;
                default:
                    break;
                }
            }
            break;
        case 'D':
            if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                
                s.colunaAtual++;
            }
            else{
                switch (p.pref2)
                {
                case 'B':
                    if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        
                        s.linhaAtual++;
                    }
                    else{
                        switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                        }
                    }
                    break;
                case 'E':
                    if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        
                        s.colunaAtual--;
                    }
                    else{
                        switch(p.pref3){

                            case 'B':
                            if(m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.linhaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'B':
                                        if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    }
                    break;
                case 'C':
                    if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                        
                        s.linhaAtual--;
                    }
                    else{
                            switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'B':
                                        if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'B':
                            if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    break;
                default:
                    break;
                }
            }
            }
            break;
        case 'E':
            if (s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                
                s.colunaAtual--;
            }
            else{
                switch (p.pref2)
                {
                case 'D':
                    if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        
                        s.colunaAtual++;
                    }
                    else{
                        switch(p.pref3){

                            case 'B':
                            if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.linhaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'B':
                                        if(m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual][s.colunaAtual] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                        }
                    }
                    break;
                case 'B':
                    if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        
                        s.linhaAtual++;
                    }
                    else{
                        switch(p.pref3){

                            case 'D':
                            if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.colunaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.linhaAtual--;
                            }
                            else{
                                switch (p.pref4){
                                    case 'D':
                                        if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    }
                    break;
                case 'C':
                    if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                        
                        s.linhaAtual--;
                    }
                    else{
                            switch(p.pref3){

                            case 'B':
                            if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                
                                s.linhaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'D':
                                        if(m.elemento[s.linhaAtual][s.colunaAtual +1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'D':
                            if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                
                                s.colunaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'B':
                                        if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            
                                            s.linhaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    break;
                default:
                    break;
                }
            }
            }
            break;
        case 'C': //CASO C SEJA A PRIMEIRA 
            if (s.linhaAtual - 1 >= 0 && m.elemento[s.linhaAtual - 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual - 1][s.colunaAtual] == false){
                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                s.linhaAtual--;
            }
            else{
                switch (p.pref2)
                {
                case 'D':
                    if (s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                        s.colunaAtual++;
                    }
                    else{
                        switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'B':
                                        if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.linhaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.linhaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                        }
                    }
                    break;
                case 'E':
                    if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true;
                        //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                        s.colunaAtual--;
                    }
                    else{
                        switch(p.pref3){

                            case 'D':
                            if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.colunaAtual++;
                            }
                            else{
                                switch(p.pref4){
                                    case 'C':
                                        if(s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.linhaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'C':
                            if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.linhaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'D':
                                        if(s.colunaAtual + 1 < m.colunas && m.elemento[s.linhaAtual][s.colunaAtual + 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    }
                    break;
                case 'B':
                    if (s.linhaAtual + 1 < m.linhas && m.elemento[s.linhaAtual + 1][s.colunaAtual] == 0 && s.visitado[s.linhaAtual + 1][s.colunaAtual] == false){
                        s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                        //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                        s.linhaAtual++;
                    }
                    else{
                            switch(p.pref3){

                            case 'E':
                            if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.colunaAtual--;
                            }
                            else{
                                switch(p.pref4){
                                    case 'D':
                                        if(m.elemento[s.linhaAtual][s.colunaAtual +1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual + 1] == false){
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.colunaAtual++;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;

                            case 'D':
                            if (m.elemento[s.linhaAtual][s.colunaAtual+ 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual+ 1] == false){
                                
                                s.visitado[s.linhaAtual][s.colunaAtual] = true; 
                                //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                s.colunaAtual++;
                            }
                            else{
                                switch (p.pref4){
                                    case 'E':
                                        if(s.colunaAtual - 1 >= 0 && m.elemento[s.linhaAtual][s.colunaAtual - 1] == 0 && s.visitado[s.linhaAtual][s.colunaAtual - 1] == false){
                                
                                            s.visitado[s.linhaAtual][s.colunaAtual] = true;
                                            //printf("(%d,%d)", s.linhaAtual, s.colunaAtual);
                                            s.colunaAtual--;
                                        }
                                        else{
                                            exit(1);
                                        }
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            break;
                            default:
                                break;
                    }
                    break;
                default:
                    break;
                }
            }
            }
            break; //FIM DO CASO C COMO PRIMEIRA 
        default:
            break;
                }
            }
        }
        //printf("saiu do negocio!");
        printf("(%d,%d)\n", s.linhaAtual + 1, s.colunaAtual + 1);
    }

int main(){

    matriz m;

    preferencia p;

    salvaCaminho s;

    m = leMatriz();

    s = defineEntrada();

    p = definePreferencia();

    movimentaJogador(m, p, s);

    return 0;
}