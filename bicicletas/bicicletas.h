#ifndef BICICLETAS_H
#define BICICLETAS_H

struct Bicicleta {
    int id;
    int tam_quadro;
    char *cor;
    char *marca;
    char *modelo;
    int ano;
};
void bicicletas(void);
void cadastrarBicicleta(FILE *fp);
void pesquisarBicicleta(void);
void atualizarBicicleta(void);
void deletarBicicleta(void);

#endif 