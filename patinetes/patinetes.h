#ifndef PATINETES_H
#define PATINETES_H

typedef struct patinete {
    int id;
    char modelo[51];
    char cor[51];
    char marca[51];
    int ano;
    int bateria;
    char status;
    int tipo;
} Patinete;

void patinetes(void);
Patinete* preenchePatinete(void);
int obterProximoID();
Patinete* pesquisarPatinete(void);
void exibePatinete(Patinete* pat);
void atualizarPatinete(void);
void deletarPatinete(Patinete* patLido);


#endif