#ifndef PATINETES_H
#define PATINETES_H

typedef struct patinete {
    int id;
    char modelo[51];
    char cor[51];
    char marca[51];
    int ano;
    int bateria;
} Patinete;

void patinetes(void);
Patinete* preenchePatinete(void);
void gravaPatinete(Patinete* pat);
int obterProximoID();
void pesquisarPatinete(void);
void atualizarPatinete(void);
void deletarPatinete(void);


#endif