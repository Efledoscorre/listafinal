//nome do aluno: Lucas sabino assis
//matricula: UC22103214

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    float altura;
};

int main() {
	system("color f4");
    struct Aluno Dados;

    printf("Digite o nome do aluno: ");
    scanf("%s", Dados.nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &Dados.idade);

    printf("Digite a altura do aluno: ");
    scanf("%f", &Dados.altura);

    
    printf("\nDados do Aluno:\n");
    printf("Nome: %s\n", Dados.nome);
    printf("Idade: %d\n", Dados.idade);
    printf("Altura: %.2f\n", Dados.altura);

    return 0;
}

