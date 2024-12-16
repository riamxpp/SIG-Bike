#ifndef LOCACAO_H
#define LOCACAO_H
#include "../bicicletas/bicicletas.h"
#include "../clientes/clientes.h"

typedef struct locacaoBicicleta {
    int idLocacao;
    int idBicicleta;
    char cpfCliente[15];
    char clienteNome[81];
    char dataInicio[12];
    char dataFim[12];    
    int diasLocacao;
    float valor;
    int status;
    int tipo;
} LocacaoBicicleta;

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

void reservarBicicleta(void);
void reservarPatinete(void);
void devolverBicicleta(void);
void devolverPatinete(void);
void consultarAluguel(void);
void locacao(void);
LocacaoBicicleta* preencheLocacaoBicicleta(Cliente* cliente, Bicicleta* bicicleta, LocacaoBicicleta* locaBike);
Data* pegaInicioReserva();
Data* pegaFimReserva();

#endif 