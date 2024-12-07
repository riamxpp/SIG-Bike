#ifndef BICICLETAS_H
#define BICICLETAS_H


typedef struct bicicleta {
    int id;
    int tam_quadro;
    char *cor;
    char *marca;
    char *modelo;
    int ano;
} Bicicleta;
void gravaArquivo(char nomeDoArquivo[], void* estrutura, size_t tamanhoEstrutura);
void bicicletas(void);
Bicicleta* preencheBicicleta(void);
void cadastrarBicicleta(FILE *fp);
void gravaPatinete(Bicicleta* bicicleta);
void pesquisarBicicleta(FILE *fp);
// void atualizarBicicleta(void);
void deletarBicicleta(void);

#endif 