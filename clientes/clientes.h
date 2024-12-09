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
Cliente* preencherCliente(void);
int obterProximoID();
Cliente* pesquisarCliente(void);
void exibeCliente(Cliente* cli);
void atualizarCliente(void);
void deletarCliente(void);

#endif 