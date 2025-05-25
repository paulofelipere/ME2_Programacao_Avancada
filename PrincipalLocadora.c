#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Protótipos de funções
void pausar();
void limparTela();
void menuPrincipal();
void menuClientes();
void menuAutomoveis();
void cadastrarUnidade();
void listarUnidades();
void cadastrarFuncionario();
void listarFuncionarios();
void cadastrarOficina();
void listarOficinas();
void cadastrarManutencao();
void listarManutencoes();
void realizarLocacao();
void listarLocacoes();
void gerarRelatorios();

// Estrutura para Data
typedef struct {
    int tm_mday;  // dia do mês
    int tm_mon;   // mês (0-11)
    int tm_year;  // ano - 1900
} Data;

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}
void limparTela() {
    system("cls || clear");
}

void menuPrincipal() {
    int opcao;

    do {
        limparTela();
        printf("\n\n\t ========== SISTEMA DE GERENCIAMENTO DE LOCADORA DE AUTOMÓVEIS ==========\n\n");
        printf("\t 1. Gestão de Clientes\n");
        printf("\t 2. Gestão de Automóveis\n");
        printf("\t 3. Cadastrar Unidade\n");
        printf("\t 4. Listar Unidades\n");
        printf("\t 5. Cadastrar Funcionário\n");
        printf("\t 6. Listar Funcionários\n");
        printf("\t 7. Gestão de Manutenções\n");
        printf("\t 8. Realizar Locação\n");
        printf("\t 9. Listar Locações\n");
        printf("\t 10. Gerar Relatórios\n");
        printf("\t 0. Sair\n");
        printf("\n\t Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuAutomoveis();
                break;
            case 3:
                cadastrarUnidade();
                break;
            case 4:
                listarUnidades();
                break;
            case 5:
                cadastrarFuncionario();
                break;
            case 6:
                listarFuncionarios();
                break;
            case 7:
                // Submenu de Manutenções
                int opcaoManutencao;
                do {
                    limparTela();
                    printf("\n\n\t ========== GESTÃO DE MANUTENÇÕES ==========\n\n");
                    printf("\t 1. Cadastrar Oficina\n");
                    printf("\t 2. Listar Oficinas\n");
                    printf("\t 3. Cadastrar Manutenção\n");
                    printf("\t 4. Listar Manutenções\n");
                    printf("\t 0. Voltar ao Menu Principal\n");
                    printf("\n\t Escolha uma opção: ");
                    scanf("%d", &opcaoManutencao);

                    switch(opcaoManutencao) {
                        case 1:
                            cadastrarOficina();
                            break;
                        case 2:
                            listarOficinas();
                            break;
                        case 3:
                            cadastrarManutencao();
                            break;
                        case 4:
                            listarManutencoes();
                            break;
                        case 0:
                            break;
                        default:
                            printf("\n\t Opção inválida!\n");
                            pausar();
                    }
                } while(opcaoManutencao != 0);
                break;
            case 8:
                realizarLocacao();
                break;
            case 9:
                listarLocacoes();
                break;
            case 10:
                gerarRelatorios();
                break;
            case 0:
                printf("\n\t Saindo do sistema...\n");
                break;
            default:
                printf("\n\t Opção inválida!\n");
                pausar();
        }
    } while(opcao != 0);
}
/////////////////////////////   CADASTRO DE CLIENTES  ///////////////////////////////////////

// Definições das constantes
#define MAX_CLIENTES 1000 // Quantidade de clientes que são suportados pelo sistema
#define TAM_NOME 1000 // Tamanho máximo do nome
#define TAM_ENDERECO 2000 // Tamanho máximo do endereco

// Nesse caso, as informações de endereço e de informações do cliente ficam armazenadas na mesma classe
typedef struct {     // Estrutura para armazenar o endereço do cliente
    char tipoVia[20];
    char nomeVia[100];
    int numero;
    char cep[10];
    char cidade[50];
    char estado[30];
    char bairro[50];
} Endereco;

typedef struct {  // Estrutura para armazenar os dados do cliente
    int idCliente;
    char nomeCliente[100];
    char cpf[15];
    Endereco endereco;
    char telefone[20];
    char cnh[20];
    Data dataNascimento;
} Cliente;


Cliente clientes[MAX_CLIENTES];
int numClientes = 0;


// Funções que serão utilizadas

void cadastrarCliente();
void listarClientes();
void buscarCliente();
void removerCliente();

void menuClientes() {
    int opcao;

    do {
        limparTela();
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
                pausar();
        }
    } while(opcao != 0);
}

void cadastrarCliente() {
    limparTela();
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
    scanf("%d %d %d", &novoCliente.dataNascimento.tm_mday, &novoCliente.dataNascimento.tm_mon, &novoCliente.dataNascimento.tm_year);
    novoCliente.dataNascimento.tm_mon -= 1;
    novoCliente.dataNascimento.tm_year -= 1900;

    printf("\t CNH: ");
    scanf(" %[^\n]", novoCliente.cnh);

    printf("\t Telefone: ");
    scanf(" %[^\n]", novoCliente.telefone);

    // cadastro do endereço do cliente

    printf("\n\t --- Endereço ---\n");
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
    pausar();
}

void listarClientes() {
    limparTela(); // limpa a tela
    printf("\n\n\t ========== LISTA DE CLIENTES ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n");
        pausar();  // Adicionando pausar()
        return;
    }
    // Listagem de todos os clientes
    for (int i = 0; i < numClientes; i++) {
        printf("\t ID: %d\n", clientes[i].idCliente);
        printf("\t Nome: %s\n", clientes[i].nomeCliente);
        printf("\t CPF: %s\n", clientes[i].cpf);
        printf("\t Data de Nascimento: %02d/%02d/%04d\n", // modificar dps que fizer a classe "data"
               clientes[i].dataNascimento.tm_mday,
               clientes[i].dataNascimento.tm_mon + 1,
               clientes[i].dataNascimento.tm_year + 1900);
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
    pausar();  // Adicionando pausar() após listar todos os clientes
}

void buscarCliente() {
    limparTela();
    printf("\n\n\t ========== BUSCAR CLIENTE ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n"); // Mensagem de nenhum cliente cadastrado
        pausar();  // Adicionando pausar()
        return;
    }
    // busca de clientes por CPF
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
                   clientes[i].dataNascimento.tm_mday,
                   clientes[i].dataNascimento.tm_mon + 1,
                   clientes[i].dataNascimento.tm_year + 1900);
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
        printf("\n\t Cliente não encontrado!\n"); // Aviso de cliente não encontrado
    }
    pausar();  // Adicionando pausar() após busca
}
//Função para remover cliente
void removerCliente() {
    limparTela();
    printf("\n\n\t ========== REMOVER CLIENTE ==========\n\n");

    if (numClientes == 0) {
        printf("\t Nenhum cliente cadastrado!\n"); // Mensagem de nenhum cliente cadastrado
        pausar();  // Adicionando pausar()
        return;
    }

    int idRemover;
    printf("\t Digite o ID do cliente a ser removido: ");
    scanf("%d", &idRemover);

    int indice = -1;

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].idCliente == idRemover) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\n\t Cliente não encontrado!\n"); // Mensagem de cliente não encontrado
        pausar();  // Adicionando pausar()
        return;
    }
    // Verifica se o cliente possui locações ativas(relacionamento com a classe "Locação")
    for (int i = 0; i < numLocacoes; i++) {
        if (locacoes[i].idCliente == idRemover && locacoes[i].ativa) {
            printf("\n\t Este cliente possui locações ativas e não pode ser removido!\n");
            pausar();  // Adicionando pausar()
            return;
        }
    }

    // Remover cliente (deslocando os elementos do array)
    for (int i = indice; i < numClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    numClientes--; //Decrescimo da quantidade de clientes cadastrados

    printf("\n\t Cliente removido com sucesso!\n");//Mensagem de cliente removido com sucesso
    pausar();  // Adicionando pausar()
}

/////////////////////////////// CADASTRO DE AUTOMÓVEIS  ///////////////////////////////////////


#define MAX_AUTOMOVEIS 1000 // Quantidade máxima de automoveis que são suportados pelo sistema

typedef struct {
    char placa[10];
    char modelo[50];
    char marca[50];
    int ano;
    char numeroChassi[30];
    char tipo[20]; // Tipo do automovel(Sedan, SUV, Hatch, etc.)
    int disponivel; // 0 = indisponível, 1 = disponível
} Automovel;

Automovel automoveis[MAX_AUTOMOVEIS];
int numAutomoveis = 0;

// Funções que serão utilizadas
void menuAutomoveis(void);
void cadastrarAutomovel();
void listarAutomoveis();
void buscarAutomovel();
void removerAutomovel();


void menuAutomoveis(void) {
    int opcao;

    do {
        limparTela();
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
                pausar();
        }
    } while(opcao != 0);
}
// Função para cadastrar automóveis
void cadastrarAutomovel() {
    limparTela();
    printf("\n\n\t ========== CADASTRO DE AUTOMÓVEL ==========\n\n");

    if (numAutomoveis >= MAX_AUTOMOVEIS) {
        printf("\n\t Limite de automóveis atingido!\n");
        pausar();
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
    pausar();
}

void listarAutomoveis() {
    limparTela();
    printf("\n\n\t ========== LISTA DE AUTOMÓVEIS ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n");
        pausar();
        return;
    }

    for (int i = 0; i < numAutomoveis; i++) {
        printf("\t Placa: %s\n", automoveis[i].placa);
        printf("\t Modelo: %s\n", automoveis[i].modelo);
        printf("\t Marca: %s\n", automoveis[i].marca);
        printf("\t Ano: %d\n", automoveis[i].ano);
        printf("\t Número do Chassi: %s\n", automoveis[i].numeroChassi);
        printf("\t Tipo: %s\n", automoveis[i].tipo);
        printf("\t Disponível: %s\n", automoveis[i].disponivel ? "Sim" : "Não");
        printf("\t ----------------------------------------\n");
    }

    pausar();
}
// Função para buscar automóveis no sistema
void buscarAutomovel() {
    limparTela();
    printf("\n\n\t ========== BUSCAR AUTOMÓVEL ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n");
        pausar();
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
            printf("\t Disponível: %s\n", automoveis[i].disponivel ? "Sim" : "Não");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Automóvel não encontrado!\n");// Mensagem de automóvel não encontrado
    }

    pausar();
}
// Função para remover automovel do sistema
void removerAutomovel() {
    limparTela();
    printf("\n\n\t ========== REMOVER AUTOMÓVEL ==========\n\n");

    if (numAutomoveis == 0) {
        printf("\t Nenhum automóvel cadastrado!\n"); // Mensagem de nenhum automóvel cadastrado
        pausar();
        return;
    }

    char placaRemover[10]; // Placa do automóvel a ser removido
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
        printf("\n\t Automóvel não encontrado!\n");
        pausar();
        return;
    }

    // Remover automóvel (deslocando os elementos do array)
    for (int i = indice; i < numAutomoveis - 1; i++) {
        automoveis[i] = automoveis[i + 1];
    }

    numAutomoveis--; // Decrementa o número de automóveis cadastrados

    printf("\n\t Automóvel removido com sucesso!\n");// Mensagem de automóvel removido com sucesso
    pausar();
}

/////////////////////////////// CADASTRO DE FUNCIONARIOS  ///////////////////////////////////////

#define MAX_FUNCIONARIOS 1000 // Quantidade de funcionarios que são suportados pelo sistema
#define TAM_NOME 1000 // Tamanho máximo do nome

typedef struct {
    int idFuncionario;
    char nomeFuncionario[100];
    char cpf[15];
    Data dataNascimento;
    char telefone[20];
    float salario;
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int numFuncionarios = 0;

// Protótipos
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
                cadastrarFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                buscarFuncionario();
                break;
            case 4:
                removerFuncionario();
                break;
            case 0:
                break;
            default:
                printf("\n\t Opção inválida!\n");
                pausar();
        }
    } while(opcao != 0);
}

void cadastrarFuncionario() {
    limparTela();
    printf("\n\n\t ========== CADASTRO DE FUNCIONARIO ==========\n\n");

    if (numFuncionarios >= MAX_FUNCIONARIOS) {
        printf("\n\t Limite de funcionarios atingido!\n");
        pausar();
        return;
    }

    Funcionario novoFuncionario;
    novoFuncionario.idFuncionario = numFuncionarios + 1;

    printf("\t Nome: ");
    scanf(" %[^\n]", novoFuncionario.nomeFuncionario);

    printf("\t CPF: ");
    scanf(" %[^\n]", novoFuncionario.cpf);

    printf("\t Data de Nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &novoFuncionario.dataNascimento.tm_mday,
          &novoFuncionario.dataNascimento.tm_mon,
          &novoFuncionario.dataNascimento.tm_year);
    novoFuncionario.dataNascimento.tm_mon -= 1;
    novoFuncionario.dataNascimento.tm_year -= 1900;

    printf("\t Telefone: ");
    scanf(" %[^\n]", novoFuncionario.telefone);

    printf("\t Salário: R$ ");
    scanf("%f", &novoFuncionario.salario);

    funcionarios[numFuncionarios] = novoFuncionario;
    numFuncionarios++;

    printf("\n\t Funcionario cadastrado com sucesso!\n");
    pausar();
}

void listarFuncionarios() {
    limparTela();
    printf("\n\n\t ========== LISTA DE FUNCIONARIOS ==========\n\n");

    if (numFuncionarios == 0) {
        printf("\t Nenhum funcionario cadastrado!\n");
        pausar();
        return;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        printf("\t ID: %d\n", funcionarios[i].idFuncionario);
        printf("\t Nome: %s\n", funcionarios[i].nomeFuncionario);
        printf("\t CPF: %s\n", funcionarios[i].cpf);
        printf("\t Data de Nascimento: %02d/%02d/%04d\n",
               funcionarios[i].dataNascimento.tm_mday,
               funcionarios[i].dataNascimento.tm_mon + 1,
               funcionarios[i].dataNascimento.tm_year + 1900);
        printf("\t Telefone: %s\n", funcionarios[i].telefone);
        printf("\t Salário: R$ %.2f\n", funcionarios[i].salario);
        printf("\t ----------------------------------------\n");
    }
    pausar();
}

void buscarFuncionario() {
    limparTela();
    printf("\n\n\t ========== BUSCAR FUNCIONARIO ==========\n\n");

    if (numFuncionarios == 0) {
        printf("\t Nenhum funcionario cadastrado!\n");
        pausar();
        return;
    }
    // busca de funcionarios por CPF
    char cpfBusca[15];
    printf("\t Digite o CPF do funcionario: ");
    scanf(" %[^\n]", cpfBusca);

    int encontrado = 0;
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
            printf("\t Salário: R$ %.2f\n", funcionarios[i].salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Funcionario não encontrado!\n"); //Aviso de funcionario não encontrado
    }
    pausar();
}


//Função para remover funcionario
void removerFuncionario() {
    limparTela();
    printf("\n\n\t ========== REMOVER FUNCIONARIO ==========\n\n");

    if (numFuncionarios == 0) {
        printf("\t Nenhum funcionario cadastrado!\n");// Mensagem de nenhum funcionario cadastrado
        pausar();
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
        printf("\n\t Funcionario não encontrado!\n");// Mensagem de funcionario não encontrado
        pausar();
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

    numFuncionarios--;
    printf("\n\t Funcionario removido com sucesso!\n");// Mensagem de funcionario removido com sucesso
    pausar();
}
