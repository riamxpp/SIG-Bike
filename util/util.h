#ifndef UTIL_H
#define UTIL_H
#include <stddef.h>
#include "../bicicletas/bicicletas.h"
#include "../patinetes/patinetes.h"

void gravaArquivo(char nomeDoArquivo[], void* estrutura, size_t tamanhoEstrutura);
int obterProximoID(const char* nomeArquivo, size_t tamanhoEstrutura);
void* encontrarPeloID(void* estrutura, char* nomeArquivo, FILE* fp, size_t tamanhoEstrutura, int id);
void printBicicleta(Bicicleta* bicicleta);
void printPatinete(Patinete* patinete);
#endif