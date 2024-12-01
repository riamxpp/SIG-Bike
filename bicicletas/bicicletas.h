#ifndef BICICLETAS_H
#define BICICLETAS_H

struct bicicleta {
    int id;
    int tam_quadro;
    char *cor;
    char *marca;
    char *modelo;
    int ano;
};
void bicicletas(void);
void cadastrarBicicleta(void);
void pesquisarBicicleta(void);
void atualizarBicicleta(void);
void deletarBicicleta(void);

#endif 