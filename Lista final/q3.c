//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Produto {
    int codigo;
    char nome[50];
    char dataPublicacao[20];
};

void adicionarProduto(struct Produto listaProdutos[], int *quantidadeProdutos);
void listarProdutos(struct Produto listaProdutos[], int quantidadeProdutos);
void buscarProdutoPorNome(struct Produto listaProdutos[], int quantidadeProdutos, const char *nome);

int main() {
    system("color f4");
	setlocale(LC_ALL, "Portuguese");
    struct Produto listaProdutos[50];
    int quantidadeProdutos = 0;
    int opcao;
    
    do {
        printf("\nMenu: \n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Todos os Produtos\n");
        printf("3. Buscar por Nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(listaProdutos, &quantidadeProdutos);
                break;
            case 2:
                listarProdutos(listaProdutos, quantidadeProdutos);
                break;
            case 3: {
                char nomeBusca[50];
                printf("Digite o nome do produto para buscar: ");
                scanf("%s", nomeBusca);
                buscarProdutoPorNome(listaProdutos, quantidadeProdutos, nomeBusca);
                break;
            }
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void adicionarProduto(struct Produto listaProdutos[], int *quantidadeProdutos) {
    if (*quantidadeProdutos < 50) {
        printf("Digite o código do produto: ");
        scanf("%d", &listaProdutos[*quantidadeProdutos].codigo);

        printf("Digite o nome do produto: ");
        scanf("%s", listaProdutos[*quantidadeProdutos].nome);

        printf("Digite a data de publicação do produto: ");
        scanf("%s", listaProdutos[*quantidadeProdutos].dataPublicacao);

        (*quantidadeProdutos)++;
        printf("Produto adicionado com sucesso!\n");
    } else {
        printf("Limite de produtos atingido. Não é possível adicionar mais.\n");
    }
}

void listarProdutos(struct Produto listaProdutos[], int quantidadeProdutos) {
    if (quantidadeProdutos > 0) {
        printf("\nLista de Produtos:\n");
        int i;
        for (i = 0; i < quantidadeProdutos; i++) {
            printf("Código: %d\nNome: %s\nData de Publicação: %s\n", listaProdutos[i].codigo, listaProdutos[i].nome, listaProdutos[i].dataPublicacao);
        }
    } else {
        printf("Nenhum produto cadastrado.\n");
    }
}

void buscarProdutoPorNome(struct Produto listaProdutos[], int quantidadeProdutos, const char *nome) {
    int encontrado = 0;
    int i;
    for (i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(listaProdutos[i].nome, nome) == 0) {
            printf("Produto:\n");
            printf("Código: %d\nNome: %s\nData de Publicação: %s\n", listaProdutos[i].codigo, listaProdutos[i].nome, listaProdutos[i].dataPublicacao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}

