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
void pesquisarBicicleta(FILE *fp);
void atualizarBicicleta(void);
void deletarBicicleta(void);

#endif 