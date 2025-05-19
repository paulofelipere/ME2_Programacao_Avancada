//dividido
// Essa classe funciona de forma mais estrutual para o funcionamento da classe automoveiss
#ifndef AUTOMOVEIS_H
#define AUTOMOVEIS_H

#define MAX_AUTOMOVEIS 1000 // Quantidade máxima de automoveis que são suportados pelo sistema
// Funções que serão utilizadas
void menuAutomoveis();
void cadastrarAutomovel();
void listarAutomoveis();
void buscarAutomovel();
void removerAutomovel();

// Estrutura para armazenar automóveis
typedef struct {
    char placa[10];
    char modelo[50];
    char marca[50];
    int ano;
    char numeroChassi[30];
    char tipo[20]; // Sedan, SUV, Hatch, etc.
    int disponivel; // 0 = indisponível, 1 = disponível
}Automovel;

extern Automovel automoveis[MAX_AUTOMOVEIS];
extern int numAutomoveis;


#endif //AUTOMOVEIS_H
