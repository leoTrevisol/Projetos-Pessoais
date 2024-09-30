/*
 * Programa: CampoMinadoc
 * Descrição: Tentar replicar o jogo campo minado em C.
 * Data de criação: 09.09.2024
 * Última modificação: 09.09.2024
 *
 * Observações:
 * Arquitetando o jogo:
 * 
 * pt1: pedir para o usuario1 econder uma 'bomba' em alguma posicao da matriz;
 *  
 */

#include <stdio.h>
#include <string.h>

#define SIZE1 10

int campoMinadoNivel1(int campo1[SIZE1][SIZE1]);
int main(){

   int campoMinado[SIZE1][SIZE1];

    
    

    
    
    return 0;
}

int campoMinadoNivel1(int campo1[SIZE1][SIZE1]){

        for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            campo1[i][j] = 0;
        } 
    }
    
    for (int i = 0; i < SIZE1; i++)
    {
        campo1[i][0] = i;
    }
    for (int i = 0; i < SIZE1; i++)
    {
        campo1[0][i] = i;
    }
    
    for ( int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            printf("%d ",campo1[i][j]);  
        }
        printf("\n");
    }
    
}
