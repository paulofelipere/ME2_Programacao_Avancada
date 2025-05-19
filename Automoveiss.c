#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Automoveis.h"

//dividido
// Implementação das variáveis globais declaradas em estruturas.h
Automovel automoveis[MAX_AUTOMOVEIS];
int numAutomoveis = 0;

void menuAutomoveis() {
    int opcao;

    do {

        printf("\n\n\t ========== GESTÃO DE AUTOMÓVEIS ==========\n\n");
        printf("\t 1. Cadastrar Automóvel\n");
        printf("\t 2. Listar Automóveis\n");
        printf("\t 3. Buscar Automóvel\n");
        printf("\t 4. Remover Automóvel\n");
        printf("\t 0. Voltar ao Menu Principal\n");
        printf("\n\t Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAutomovel();
                break;
            case 2:
                listarAutomoveis();
                break;
            case 3:
                buscarAutomovel();
                break;
            case 4:
                removerAutomovel();
                break;
            case 0:
                break;
            default:
                printf("\n\t Opção inválida!\n");

        }
    } while(opcao != 0);
}

void cadastrarAutomovel() {

    printf("\n\n\t ========== CADASTRO DE AUTOMÓVEL ==========\n\n");

    if (numAutomoveis >= MAX_AUTOMOVEIS) {
        printf("\n\t Limite de automóveis atingido!\n");

        return;
    }

    Automovel novoAutomovel;

    printf("\t Placa: ");
    scanf(" %[^\n]", novoAutomovel.placa);

    printf("\t Modelo: ");
    scanf(" %[^\n]", novoAutomovel.modelo);

    printf("\t Marca: ");
    scanf(" %[^\n]", novoAutomovel.marca);

    printf("\t Ano: ");
    scanf("%d", &novoAutomovel.ano);

    printf("\t Número do Chassi: ");
    scanf(" %[^\n]", novoAutomovel.numeroChassi);

    printf("\t Tipo (Sedan, SUV, Hatch, etc.): ");
    scanf(" %[^\n]", novoAutomovel.tipo);

    novoAutomovel.disponivel = 1; // Automóvel disponível por padrão

    automoveis[numAutomoveis] = novoAutomovel;
    numAutomoveis++; // Incrementa o número de automóveis cadastrados

    printf("\n\t Automóvel cadastrado com sucesso!\n"); // Mensagem de sucesso no cadasro

}

void listarAutomoveis() {

    printf("\n\n\t ========== LISTA DE AUTOMÓVEIS ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n");
        ;
        return;
    }

    for (int i = 0; i < numAutomoveis; i++) {
        printf("\t Placa: %s\n", automoveis[i].placa);
        printf("\t Modelo: %s\n", automoveis[i].modelo);
        printf("\t Marca: %s\n", automoveis[i].marca);
        printf("\t Ano: %d\n", automoveis[i].ano);
        printf("\t Número do Chassi: %s\n", automoveis[i].numeroChassi);
        printf("\t Tipo: %s\n", automoveis[i].tipo);
        printf("\t Status: %s\n", automoveis[i].disponivel ? "Disponível" : "Indisponível");
        printf("\t ----------------------------------------\n");
    }


}
// Função para buscar automóveis no sistema
void buscarAutomovel() {

    printf("\n\n\t ========== BUSCAR AUTOMÓVEL ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n");
        return;
    }

    char placaBusca[10];
    printf("\t Digite a placa do automóvel: ");
    scanf(" %[^\n]", placaBusca);

    int encontrado = 0;
    // Informações sobre o automovel encontrado
    for (int i = 0; i < numAutomoveis; i++) {
        if (strcmp(automoveis[i].placa, placaBusca) == 0) {
            printf("\n\t Automóvel encontrado!\n");
            printf("\t Placa: %s\n", automoveis[i].placa);
            printf("\t Modelo: %s\n", automoveis[i].modelo);
            printf("\t Marca: %s\n", automoveis[i].marca);
            printf("\t Ano: %d\n", automoveis[i].ano);
            printf("\t Número do Chassi: %s\n", automoveis[i].numeroChassi);
            printf("\t Tipo: %s\n", automoveis[i].tipo);
            printf("\t Status: %s\n", automoveis[i].disponivel ? "Disponível" : "Indisponível");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Automóvel não encontrado!\n");// Mensagem de automóvel não encontrado
    }

}
// Função para remover automovel do sistema
void removerAutomovel() {

    printf("\n\n\t ========== REMOVER AUTOMÓVEL ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n");

        return;
    }

    char placaRemover[10];// Placa do automóvel a ser removido
    printf("\t Digite a placa do automóvel a ser removido: ");
    scanf(" %[^\n]", placaRemover);

    int indice = -1;
    // Busca o automóvel pelo número da placa
    for (int i = 0; i < numAutomoveis; i++) {
        if (strcmp(automoveis[i].placa, placaRemover) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n\t Automóvel não encontrado!\n");// Mensagem de automóvel não encontrado

        return;
    }

    // Verificar se o automóvel está em locação
    if (!automoveis[indice].disponivel) {
        printf("\n\t Este automóvel está em uso e não pode ser removido!\n");

        return;
    }

    // Remover automóvel (deslocando os elementos do array)
    for (int i = indice; i < numAutomoveis - 1; i++) {
        automoveis[i] = automoveis[i + 1];
    }

    numAutomoveis--; // Decrementa o número de automóveis cadastrados

    printf("\n\t Automóvel removido com sucesso!\n"); // Mensagem de automóvel removido com sucesso

}

