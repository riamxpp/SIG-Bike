#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct cliente {
    int id;
    char nome[81];
    char cpf[15];
    char email[51];
    char fone[20];
    char dtnas[12];    
} Cliente;
void clientes(void);
Cliente* preencherCliente(int id);
int obterProximoID();
Cliente* pesquisarCliente(void);
Cliente* buscarCliente(char cpf[12], Cliente* cliente);
void exibeCliente(Cliente* cli, int todosCliente);
void deletarCliente(Cliente *cliLido);
void atualizarCliente(Cliente* cli);
void regravarCliente(Cliente* cli);
static int obterProximoIDCliente(const char* nomeArquivo);
void listarTodosClientes(void);

#endif 