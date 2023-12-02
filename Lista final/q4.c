//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Roupa {
    char tipo[50];
    float precoCompra;
    float precoVenda;
};

void calcularPrecoVenda(struct Roupa *roupa);

int main() {
	
	system ("color f4");
	setlocale(LC_ALL, "Portuguese");
    struct Roupa roupas[50]; 
    int numRoupas = 0;
    int opcao;
	int i;
    do {
        printf("\nMenu: \n");
        printf("1. Adicionar Roupa\n");
        printf("2. Listar Roupas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (numRoupas < 100) {
                    printf("\nInforme o tipo da roupa: ");
                    scanf("%s", roupas[numRoupas].tipo);

                    printf("\nInforme o preço de compra da roupa: ");
                    scanf("%f", &roupas[numRoupas].precoCompra);

                    PrecoVenda(&roupas[numRoupas]);

                    printf("\nRoupa adicionada com sucesso!\n");
                    numRoupas++;
                } else {
                    printf("Limite de roupas atingido.\n");
                }
                break;
            }
            case 2:
                if (numRoupas > 0) {
                    printf("\nLista de Roupas:\n");
                    for (i = 0; i < numRoupas; i++) {
                        printf("Tipo: %s \npreço de compra: R$ %.2f\npreço de venda (com o lucro de 35 porcento aplicados): R$ %.2f\n",
                               roupas[i].tipo, roupas[i].precoCompra, roupas[i].precoVenda);
                    }
                } else {
                    printf("Nenhuma roupa cadastrada.\n");
                }
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Digite uma opção valida.\n");
        }
    } while (opcao != 3);

    return 0;
}

void PrecoVenda(struct Roupa *roupa) {
    roupa->precoVenda = roupa->precoCompra * 1.35;
}

