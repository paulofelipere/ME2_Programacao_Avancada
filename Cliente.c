#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


void menuClientes() {
    int opcao;

    do {

        printf("\n\n\t ========== GESTÃO DE CLIENTES ==========\n\n");
        printf("\t 1. Cadastrar Cliente\n");
        printf("\t 2. Listar Clientes\n");
        printf("\t 3. Buscar Cliente\n");
        printf("\t 4. Remover Cliente\n");
        printf("\t 0. Voltar ao Menu Principal\n");
        printf("\n\t Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                buscarCliente();
                break;
            case 4:
                removerCliente();
                break;
            case 0:
                break;
            default:
                printf("\n\t Opção inválida!\n");

        }
    } while(opcao != 0);
}

void cadastrarCliente() {

    printf("\n\n\t ========== CADASTRO DE CLIENTE ==========\n\n");

    if (numClientes >= MAX_CLIENTES) {
        printf("\n\t Limite de clientes atingido!\n");

        return;
    }
    //Cadastro e armazenamento de clientes
    Cliente novoCliente;
    novoCliente.idCliente = numClientes + 1;

    printf("\t Nome: ");
    scanf(" %[^\n]", novoCliente.nomeCliente);

    printf("\t CPF: ");
    scanf(" %[^\n]", novoCliente.cpf);

    printf("\t Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &novoCliente.dataNascimento.dia, &novoCliente.dataNascimento.mes, &novoCliente.dataNascimento.ano);

    printf("\t CNH: ");
    scanf(" %[^\n]", novoCliente.cnh);

    printf("\t Telefone: ");
    scanf(" %[^\n]", novoCliente.telefone);

    printf("\n\t --- Endereço ---\n");
    // cadastro do endereço do cliente
    printf("\t Tipo de Via: ");
    scanf(" %[^\n]", novoCliente.endereco.tipoVia);

    printf("\t Nome da Via: ");
    scanf(" %[^\n]", novoCliente.endereco.nomeVia);

    printf("\t Número: ");
    scanf("%d", &novoCliente.endereco.numero);

    printf("\t CEP: ");
    scanf(" %[^\n]", novoCliente.endereco.cep);

    printf("\t Bairro: ");
    scanf(" %[^\n]", novoCliente.endereco.bairro);

    printf("\t Cidade: ");
    scanf(" %[^\n]", novoCliente.endereco.cidade);

    printf("\t Estado: ");
    scanf(" %[^\n]", novoCliente.endereco.estado);

    clientes[numClientes] = novoCliente;
    numClientes++;

    printf("\n\t Cliente cadastrado com sucesso!\n");

}

void listarClientes() {

    printf("\n\n\t ========== LISTA DE CLIENTES ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n");
        return;
    }
    // Listagem de todos os clientes
    for (int i = 0; i < numClientes; i++) {
        printf("\t ID: %d\n", clientes[i].idCliente);
        printf("\t Nome: %s\n", clientes[i].nomeCliente);
        printf("\t CPF: %s\n", clientes[i].cpf);
        printf("\t Data de Nascimento: %02d/%02d/%04d\n", // modificar dps que fizer a classe "data"
               clientes[i].dataNascimento.dia,
               clientes[i].dataNascimento.mes,
               clientes[i].dataNascimento.ano);
        printf("\t CNH: %s\n", clientes[i].cnh);
        printf("\t Telefone: %s\n", clientes[i].telefone);
        printf("\t Endereço: %s %s, %d, %s, %s - %s\n",
               clientes[i].endereco.tipoVia,
               clientes[i].endereco.nomeVia,
               clientes[i].endereco.numero,
               clientes[i].endereco.bairro,
               clientes[i].endereco.cidade,
               clientes[i].endereco.estado);
        printf("\t ----------------------------------------\n");
    }


}

void buscarCliente() {

    printf("\n\n\t ========== BUSCAR CLIENTE ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n");// Mensagem de nenhum cliente cadastrado

        return;
    }

    char cpfBusca[15];
    printf("\t Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpfBusca);

    int encontrado = 0;
    // Informações do cliente encontrado
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpfBusca) == 0) {
            printf("\n\t Cliente encontrado!\n");
            printf("\t ID: %d\n", clientes[i].idCliente);
            printf("\t Nome: %s\n", clientes[i].nomeCliente);
            printf("\t CPF: %s\n", clientes[i].cpf);
            printf("\t Data de Nascimento: %02d/%02d/%04d\n",
                   clientes[i].dataNascimento.dia,
                   clientes[i].dataNascimento.mes,
                   clientes[i].dataNascimento.ano);
            printf("\t CNH: %s\n", clientes[i].cnh);
            printf("\t Telefone: %s\n", clientes[i].telefone);
            printf("\t Endereço: %s %s, %d, %s, %s - %s\n",
                   clientes[i].endereco.tipoVia,
                   clientes[i].endereco.nomeVia,
                   clientes[i].endereco.numero,
                   clientes[i].endereco.bairro,
                   clientes[i].endereco.cidade,
                   clientes[i].endereco.estado);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Cliente não encontrado!\n");// Aviso de cliente não encontrado
    }


}
//Função para remover cliente
void removerCliente() {
    ;
    printf("\n\n\t ========== REMOVER CLIENTE ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n");

        return;
    }

    int idRemover;
    printf("\t Digite o ID do cliente a ser removido: "); // Mensagem de nenhum cliente cadastrado
    scanf("%d", &idRemover);

    int indice = -1;

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].idCliente == idRemover) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n\t Cliente não encontrado!\n");// Mensagem de cliente não encontrado

        return;
    }

    // Verifica se o cliente possui locações ativas(relacionamento com a classe "Locação")
    extern Locacao locacoes[];
    extern int numLocacoes;

    for (int i = 0; i < numLocacoes; i++) {
        if (locacoes[i].idCliente == idRemover && locacoes[i].ativa) {
            printf("\n\t Este cliente possui locações ativas e não pode ser removido!\n");

            return;
        }
    }

    // Remover cliente (deslocando os elementos do array)
    for (int i = indice; i < numClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    numClientes--;

    printf("\n\t Cliente removido com sucesso!\n");

}
