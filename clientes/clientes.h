#ifndef CLIENTES_H
#define CLIENTES_H

struct cliente {
    char nome[81];
    char cpf[15];
    char email[51];
    char fone[20];
    char dtnas[12];    
};
void clientes(void);
void cadastrarCliente(void);
void pesquisarCliente(void);
void atualizarCliente(void);
void deletarCliente(void);

#endif 