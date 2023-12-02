//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void insertionSort(int linha[], int colunas);

void ordenarMatriz(int matriz[][5], int linhas, int colunas);

void exibirMatriz(int matriz[][5], int linhas, int colunas);

int main() {
    int matriz[4][5] = {
        {5, 2, 9, 11, 6},
        {8, 3, 7, 4, 5},
        {1, 6, 21, 10, 3},
        {18, 25, 12, 13, 15}
    };

	system("color f4");
    setlocale(LC_ALL, "Portuguese");
    
    printf("matriz antes da ordenação:\n");
    exibirMatriz(matriz, 4, 5);

    ordenarMatriz(matriz, 4, 5);

    printf("\nmatriz após a ordenação:\n");
    exibirMatriz(matriz, 4, 5);

    return 0;
}

void insertionSort(int linha[], int colunas) {
    int chave, j;
    int i;

    for (i = 1; i < colunas; i++) {
        chave = linha[i];
        j = i - 1;

        while (j >= 0 && linha[j] > chave) {
            linha[j + 1] = linha[j];
            j = j - 1;
        }
        linha[j + 1] = chave;
    }
}

void ordenarMatriz(int matriz[][5], int linhas, int colunas) {
    int i;

    for (i = 0; i < linhas; i++) {
        insertionSort(matriz[i], colunas);
    }
}

void exibirMatriz(int matriz[][5], int linhas, int colunas) {
    int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

