//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void bubbleSort(int matriz[][5], int linhas, int colunas);
void exibirMatriz(int matriz[][5], int linhas, int colunas);

int main() {
    int matriz[3][5] = {
        {8, 7, 2, 14, 3},
        {9, 13, 18, 6, 5},
        {4, 17, 5, 8, 27}
    };
    system ("color f4");
    setlocale(LC_ALL, "Portuguese");

    printf("matriz antes da ordenação:\n");
    exibirMatriz(matriz, 3, 5);

    bubbleSort(matriz, 3, 5);

    printf("\nmatriz após a ordenação:\n");
    exibirMatriz(matriz, 3, 5);

    return 0;
}

void bubbleSort(int matriz[][5], int linhas, int colunas) {
	int i;
	int j;
	int k;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas - 1; j++) {
            for (k = 0; k < colunas - j - 1; k++) {
                if (matriz[i][k] > matriz[i][k + 1]) {
                    
                    
                    int temp = matriz[i][k];
                    matriz[i][k] = matriz[i][k + 1];
                    matriz[i][k + 1] = temp;
                }
            }
        }
    }
}

void exibirMatriz(int matriz[][5], int linhas, int colunas) {
	int i;
	int j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

