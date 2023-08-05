/*=============================================================
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho . . . . : Imagem ASCII
* Discplina: . . . : Processamento de Imagens
* Professor: . . . : Luiz Eduardo da Silva
* Aluno . . . . .  : Ryan Rodrigues - 2021.1.08.032
* Data . . . . . . : 27/04/2023
*==============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "imagelib.h"


void ascii(image In, image Out, int nl, int nc, int mn, int divisao, char caracteres[], int numeroChar){
    int count;
    for (int i = 0; i < nl * nc; i++){ //percorre toda a matriz
        count = round((In[i] / divisao)); //pra saber qual o index na cadeia de caracteres da escala de cinza
        if (count >= numeroChar) 
            Out[i] = caracteres[numeroChar - 1]; //seleção feita pois, se o count for maior ou igual que o numero de caracteres, 16 por exemplo, ele vai retornar sempre
        Out[i] = caracteres[count];     //o ultimo caractere, o mais pixel mais branco da imagem no caso
    }
} 

void msg(char *s)
{
    printf("\nArte Ascii - Feito por Ryan Rodrigues");
    printf("\n---------------------------------------");
    printf("\nUso: %s <nome-imagem[.pgm]> <pixelColuna> <pixelLinha> <caracteres>\n\n", s);
    printf("    <nome-imagem[.pgm]> é o nome do arquivo da imagem \n");
    printf("    <pixelColuna> é o número de colunas que você quer redimensionar a arte \n");
    printf("    <pixelLinha> é o número de linha que você quer redimensionar a arte \n");
    printf("    <caracteres> devem ser selecionados entre aspas duplas\n \n \n");
    exit(1);
}

/*-------------------------------------------------------------------------
 * main function
 *-------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    if (argc != 5) { //tratamento de erro de argumentos
        msg(argv[0]);
        return 1;
    }
    int nc, nr, ml;
    int pixelCol, pixelLin;
    pixelCol = atoi(argv[2]); //captura o argumento quantidadedecolunas
    pixelLin = atoi(argv[3]); //captura o argumento quantidadedelinhas
    char *p, nameIn[100], nameOut[100], cmd[110];
    char caracteres[20];
    image In, Out;
    strcpy(caracteres, argv[4]); //guarda os caracteres passados como parametro
    img_name(argv[1], nameIn, nameOut, GRAY);
    //-- read image
    int numeroChar = strlen(caracteres); //guarda a quantidade de caracteres
    In = img_get(nameIn, &nr, &nc, &ml, GRAY, pixelCol, pixelLin, caracteres, numeroChar);
    Out = img_alloc(nr, nc);
    int divisao = (ml+1) / numeroChar; //divisao de 256/qntd numero de caracteres

    //-- transformation
    //intensidade(In, Out, nr, nc, ml);
    ascii(In, Out, nr, nc, ml, divisao, caracteres, numeroChar);
   
    FILE *result;
    result = fopen("result.txt", "w");

    for (int i = 0; i < pixelLin; i++) {
        for (int j = 0; j < pixelCol; j++) {
            int linha = nr / pixelLin; //porcentagem da nova area, numero total de linhas da matriz dividido pela quantidade nova de linhas
            int coluna = nc / pixelCol; //porcentagem da nova area, numero total de colunas da matriz dividido pela quantidade nova de colunas
            fprintf(result, "%c", Out[(i * linha) * nc + (j * coluna)]); //pega o indice i e multiplica pela porcentagem, até a achar 
                                                                             //o indice correspondente da nova area
        }
        fprintf(result, "\n");  
    }
    fclose(result);

    //-- save image
    img_put(Out, nameOut, nr, nc, ml, GRAY);
    sprintf(cmd, "%s %s &", VIEW, nameOut);
    system(cmd);
    img_free(In);
    img_free(Out);
    return 0;
}