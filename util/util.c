#include <stdio.h>
#include <stdlib.h>
#include "../util/util.h"

void gravaArquivo(char nomeDoArquivo[], void* estrutura, size_t tamanhoEstrutura) {
    FILE* fp;
    fp = fopen(nomeDoArquivo, "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(estrutura, tamanhoEstrutura, 1, fp);
    fclose(fp);
}

int obterProximoID(const char* nomeArquivo, size_t tamanhoEstrutura) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        return 1;
    }
    int ultimoID = 0;
    char buffer[tamanhoEstrutura];

    while (fread(buffer, tamanhoEstrutura, 1, arquivo) == 1) {
        ultimoID = ((int*)buffer)[0];
    }

    fclose(arquivo);
    return ultimoID + 1;
}

void* encontrarPeloID(void* estrutura, char* nomeArquivo, FILE* fp, size_t tamanhoEstrutura, int id) {
    int encontrado = 0;
    fp = fopen(nomeArquivo, "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(estrutura);
        return NULL;
        // exit(1);
    }
    while (fread(estrutura, tamanhoEstrutura, 1, fp) == 1) {
        // verifica se o último id é igual ao id informado
        if (*(int*)estrutura == id) {
            encontrado = 1;
            break;
        }
    }
    fclose(fp);
    if (encontrado) {
        return estrutura;
    } else {
        // free(estrutura);
        return NULL;
    }
}