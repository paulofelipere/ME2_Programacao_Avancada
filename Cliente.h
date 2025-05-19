//dividido

// Essa classe funciona de forma mais estrutual para o funcionamento da classe "Cliente"
#ifndef CLIENTE_H
#define CLIENTE_H
#define TAM_NOME 1000 // Quantidade de clientes que são suportados pelo sistema
#define TAM_ENDERECO 2000 // Tamanho máximo do nome
#define MAX_CLIENTES 1000 // Tamanho máximo do endereco

// Funções que serão utilizadas
void menuClientes();
void cadastrarCliente();
void listarClientes();
void buscarCliente();
void removerCliente();

typedef struct { // Estrutura para armazenar a data de nascimento(Remover dps que fizer a classe data)
    int dia;
    int mes;
    int ano;
} Data;
// Nesse caso, as informações de endereço e de informações do cliente ficam armazenadas na mesma classe
typedef struct { // Estrutura para armazenar o endereço do cliente
    char tipoVia[20];
    char nomeVia[100];
    int numero;
    char cep[10];
    char cidade[50];
    char estado[30];
    char bairro[50];
} Endereco;

typedef struct { // Estrutura para armazenar os dados do cliente
    int idCliente;
    char nomeCliente[TAM_NOME];
    char cpf[15];
    Data dataNascimento; // Estrutura para armazenar a data de nascimento
    Endereco endereco;
    char cnh[20];
    char telefone[20];
} Cliente;

extern Cliente clientes[MAX_CLIENTES];
extern int numClientes;

#endif // CLIENTE_H