#include <stdio.h>
#include <stdlib.h>
#include "../util/util.h"
#include "../patinetes/patinetes.h"
#include "../bicicletas/bicicletas.h"
#include "../locacao/locacao.h"

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
    FILE* arquivo = fopen(nomeArquivo, "rb+");
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
        fclose(fp);
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

void printBicicleta(Bicicleta* bicicleta) {
    printf("\n= = = Bicicleta Cadastrado = = =\n");
    printf("║ ID: %d\n", bicicleta->id);
    printf("║ Modelo: %s\n", bicicleta->modelo);
    printf("║ Cor: %s\n", bicicleta->cor);
    printf("║ Marca: %s\n", bicicleta->marca);
    printf("║ Ano de Fabrica: %d\n", bicicleta->ano);
    printf("║ Tamanho do quadro: %d\n", bicicleta->tam_quadro);
}

void printLocacao(LocacaoBicicleta* locaBike) {
    printf("\n= = = Locação = = =\n");
    printf("║ ID: %d\n", locaBike->idLocacao);
    printf("║ ID bicicleta: %d\n", locaBike->idBicicleta);
    printf("║ CPF cliente: %s\n", locaBike->cpfCliente);
    printf("║ Nome cliente: %s\n", locaBike->clienteNome);
    printf("║ Data ínicio: %s\n", locaBike->dataInicio);
    printf("║ Data Fim: %s\n", locaBike->dataFim);
    printf("║ Dias de locação: %d\n", locaBike->diasLocacao);
    printf("║ Valor: %f\n", locaBike->valor);
}

int pegaNum(int num){
    if (verificaNumero(scanf("%d", &num)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        return 0;
    }
    return num;
}