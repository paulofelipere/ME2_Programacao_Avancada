#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
// continuo
#define MAX_FUNCIOANARIOS 1000 // Quantidade de clientes que são suportados pelo sistema
#define TAM_NOME 1000 // Tamanho máximo do nome

typedef struct {
    int ano;
    short mes;
    short dia;
} Data;

typedef struct{
  int idFuncionario;
  char nomeFuncionario[100];
  char cpf[15];
  Data dataNascimento;
  char telefoFuncionario;
  float salario;
}Funcionario;

Funcionario funcionarios[MAX_FUNCIOANARIOS];
int numFuncionarios = 0;

void limparTela() {    // Função para limpar a tela
    system("cls || clear");
}

void menuFuncionarios();
void cadastrarFuncionario();
void listarFuncionarios();
void buscarFuncionario();
void removerFuncionario();


void menuFuncionarios() {
    int opcao;

    do {
        limparTela();
        printf("\n\n\t ========== GESTÃO DE FUNCIONÁRIOS ==========\n\n");
        printf("\t 1. Cadastrar Funcionario\n");
        printf("\t 2. Listar Funcionarios\n");
        printf("\t 3. Buscar Funcionario\n");
        printf("\t 4. Remover Funcionario\n");
        printf("\t 0. Voltar ao Menu Principal\n");
        printf("\n\t Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarFuncioanrio();
                break;
            case 2:
                listarFuncioanrios();
                break;
            case 3:
                buscarFuncioanrio();
                break;
            case 4:
                removerFuncioanrio();
                break;
            case 0:
                break;
            default:
                printf("\n\t Opção inválida!\n");

        }
    } while(opcao != 0);
}

void cadastrarFuncionarios() {
    limparTela();
    printf("\n\n\t ========== CADASTRO DE FUNCIONARIO ==========\n\n");

    if (numFuncionarios >= MAX_FUNCIOANARIOS) {
        printf("\n\t Limite de funcionarios atingido!\n");
        return;
    }
    //Cadastro e armazenamento de clientes
    Funcionario novoFuncionario;
    novoFuncionario.idFuncionario = numFuncionarios + 1;

    printf("\t Nome: ");
    scanf(" %[^\n]", novoFuncionario.nomeFuncionario);

    printf("\t CPF: ");
    scanf(" %[^\n]", novoFuncionario.cpf);

    printf("\t Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &novoFuncionario.dataNascimento.tm_mday, &novoFuncionario.dataNascimento.tm_mon, &novoFuncionario.dataNascimento.tm_year);
    novoFuncionario.dataNascimento.tm_mon -= 1;
    novoFuncionario.dataNascimento.tm_year -= 1900;

    printf("\t Telefone: ");
    scanf(" %[^\n]", novoFuncionario.telefone);

    funcionarios[numFuncionarios] = novoFuncionario;
    numFuncionarios++;

    printf("\n\t Funcionario cadastrado com sucesso!\n");

}

void listarFuncionarios() {
    limparTela(); // limpa a tela
    printf("\n\n\t ========== LISTA DE FUNCIONARIOS ==========\n\n");

    if (numFunciouncionario == 0) {
        printf("\t Nenhum funcionario cadastrado!\n");

        return;
    }
    // Listagem de todos os funcionarios
    for (int i = 0; i < numFuncionarios; i++) {
        printf("\t ID: %d\n", funcionarios[i].idFuncionario);
        printf("\t Nome: %s\n", funcionarios[i].nomeFuncionario);
        printf("\t CPF: %s\n", funcionarios[i].cpf);
        printf("\t Data de Nascimento: %02d/%02d/%04d\n", // modificar dps que fizer a classe "data"
               funcionarios[i].dataNascimento.tm_mday,
               funcionarios[i].dataNascimento.tm_mon + 1,
               funcionarios[i].dataNascimento.tm_year + 1900);
        printf("\t Telefone: %s\n", funcionarios[i].telefone);
        printf("\t ----------------------------------------\n");
    }


}

void buscarFuncionario() {
    limparTela();
    printf("\n\n\t ========== BUSCAR FUNCIONARIO ==========\n\n");

    if (numFuncionarios == 0) {
        printf("\t Nenhum funcionario cadastrado!\n"); // Mensagem de nenhum funcionario cadastrado
        return;
    }
    // busca de funcionarios por CPF
    char cpfBusca[15];
    printf("\t Digite o CPF do funcionario: ");
    scanf(" %[^\n]", cpfBusca);

    int encontrado = 0;
    // Informações do funcionario encontrado
    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].cpf, cpfBusca) == 0) {
            printf("\n\t Funcionario encontrado!\n");
            printf("\t ID: %d\n", funcionarios[i].idFuncionario);
            printf("\t Nome: %s\n", funcionarios[i].nomeFuncionario);
            printf("\t CPF: %s\n", funcionarios[i].cpf);
            printf("\t Data de Nascimento: %02d/%02d/%04d\n",
                   funcionarios[i].dataNascimento.tm_mday,
                   funcionarios[i].dataNascimento.tm_mon + 1,
                   funcionarios[i].dataNascimento.tm_year + 1900);
            printf("\t Telefone: %s\n", funcionarios[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Funcionario não encontrado!\n"); // Aviso de funcionario não encontrado
    }


}
//Função para remover funcionario
void removerFuncionario() {
    limparTela();
    printf("\n\n\t ========== REMOVER CLIENTE ==========\n\n");

    if (numFuncionarios == 0) {
        printf("\t Nenhum funcionario cadastrado!\n"); // Mensagem de nenhum funcionario cadastrado
        return;
    }

    int idRemover;
    printf("\t Digite o ID do funcionario a ser removido: ");
    scanf("%d", &idRemover);

    int indice = -1;

    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].idFuncionario == idRemover) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n\t Funcionario não encontrado!\n"); // Mensagem de funcionario não encontrado
        return;
    }
    // Verifica se o funcionario possui locações ativas(relacionamento com a strutura "Locação")
    for (int i = 0; i < numLocacoes; i++) {
        if (locacoes[i].idFuncionario == idRemover && locacoes[i].ativa) {
            printf("\n\t Este funcionario possui locações ativas e não pode ser removido!\n");

            return;
        }
    }

    // Remover funcionario (deslocando os elementos do array)
    for (int i = indice; i < numFuncionarios - 1; i++) {
        funcionarios[i] = funcionarios[i + 1];
    }

    numFuncionarios--; //Decrescimo da quantidade de funcionarios cadastrados

    printf("\n\t Funcionario removido com sucesso!\n");//Mensagem de funcionario removido com sucesso

}
