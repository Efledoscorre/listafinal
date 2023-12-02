#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void buscar(int matriz[][7], int linhas, int colunas, int valor, int *linhaEncontrada, int *colunaEncontrada);
void exibirMatriz(int matriz[][7], int linhas, int colunas);

int main() {
    int linha;
    int coluna;
    int valorProcurado;
    int matriz[3][7] = {
        {5, 2, 9, 11, 6, 15, 25},
        {8, 3, 7, 4, 5, 18, 28},
        {1, 27, 21, 10, 13, 23, 29}
    };

    system("color f4");
    setlocale(LC_ALL, "Portuguese");

    exibirMatriz(matriz, 3, 7);

    printf("\nDigite o valor a ser procurado na matriz: ");
    scanf("%d", &valorProcurado);

    buscar(matriz, 3, 7, valorProcurado, &linha, &coluna);

    if (linha != -1 && coluna != -1) {
        printf("A última ocorrência de %d está na linha %d, coluna %d.\n", valorProcurado, linha + 1, coluna + 1);
    } else {
        printf("%d não foi encontrado na matriz.\n", valorProcurado);
    }

    return 0;
}

void buscar(int matriz[][7], int linhas, int colunas, int valor, int *linhaEncontrada, int *colunaEncontrada) {
    *linhaEncontrada = -1;
    *colunaEncontrada = -1;

    int i;
    int j;

    for (i = linhas - 1; i >= 0; i--) {
        for (j = colunas - 1; j >= 0; j--) {
            if (matriz[i][j] == valor) {
                *linhaEncontrada = i;
                *colunaEncontrada = j;
                return;
            }
        }
    }
}

void exibirMatriz(int matriz[][7], int linhas, int colunas) {
    int j;
    int i;

    printf("Matriz:\n\n");

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

