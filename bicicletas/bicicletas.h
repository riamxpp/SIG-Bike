#ifndef BICICLETAS_H
#define BICICLETAS_H


typedef struct bicicleta {
    int id;
    int tam_quadro;
    char cor[51];
    char marca[51];
    char modelo[51];
    int ano;
    char status;
    int tipo;
} Bicicleta;
void bicicletas(void);
Bicicleta* preencheBicicleta(void);
void cadastrarBicicleta(FILE *fp);
Bicicleta* pesquisarBicicleta();
void exibeBicicleta(Bicicleta* bicicleta);
// void atualizarBicicleta(void);
void deletarBicicleta(void);

#endif 