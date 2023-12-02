//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Cliente {
    char nome[50];
    char telefone[15];
};


void adicionarCliente(struct Cliente clientes[], int *numClientes);
void listarClientes(struct Cliente clientes[], int numClientes);
void buscarClientePorNome(struct Cliente clientes[], int numClientes, const char *nome);

int main() {
    struct Cliente clientes[50];  
    setlocale(LC_ALL, "Portuguese");
    
    int numClientes = 0;           
    int opcao;
    
    system ("color f4");
    do {
        printf("\nMenu: \n");
        printf("1. adicionar cliente\n");
        printf("2. listar todos os clientes\n");
        printf("3. buscar por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(clientes, &numClientes);
                break;
            case 2:
                listarClientes(clientes, numClientes);
                break;
            case 3: {
                char nomeBusca[50];
                printf("Digite o nome do cliente para buscar: ");
                scanf("%s", nomeBusca);
                buscarClientePorNome(clientes, numClientes, nomeBusca);
                break;
            }
            case 4:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opção inválida. Digite uma opção valida:\n");
        }
    } while (opcao != 4);

    return 0;
}


void adicionarCliente(struct Cliente clientes[], int *numClientes) {
    if (*numClientes < 100) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[*numClientes].nome);

        printf("Digite o número de telefone do cliente: ");
        scanf("%s", clientes[*numClientes].telefone);

        (*numClientes)++;
        printf("Cliente adicionado com sucesso\n");
    } else {
        printf("Limite de clientes atingido.\n");
    }
}


void listarClientes(struct Cliente clientes[], int numClientes) {
	int i;
    if (numClientes > 0) {
        printf("\nLista de Clientes:\n");
        for (i = 0; i < numClientes; i++) {
            printf("Nome: %s, Telefone: %s\n", clientes[i].nome, clientes[i].telefone);
        }
    } else {
        printf("Nenhum cliente cadastrado.\n");
    }
}


void buscarClientePorNome(struct Cliente clientes[], int numClientes, const char *nome) {
    int encontrado = 0;
    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s, Telefone: %s\n", clientes[i].nome, clientes[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    }
}

