#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "patinetes.h"
#include <string.h>
#include "../validacao/validacao.h"
#include "../util/util.h"

void patinetes(void){
    Patinete* pat;
    int op_patinete;
    do{
        system("clear||cls");
        printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                               Módulo Patinetes                                ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("║                               1. Cadastrar                                    ║\n");
        printf("║                               2. Pesquisar                                    ║\n");
        printf("║                               3. Atualizar                                    ║\n");
        printf("║                               4. Deletar                                      ║\n");
        printf("║                                                                               ║\n");
        printf("║                               0. Voltar                                       ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf(" Digite a opção desejada: ");
        if (verificaNumero(scanf("%d", &op_patinete)) != 1) {
            printf("\nEntrada inválida, digite apenas números.  \n");
            while (getchar() != '\n');
            getchar();
            return;
        }
        getchar();
        switch (op_patinete) {
            case 1:
                pat = preenchePatinete(0);
                gravaArquivo("patinetes.dat", pat, sizeof(Patinete));
                break;
            case 2:
                pat = pesquisarPatinete();
                exibePatinete(pat);
                getchar();
                break;
            case 3:
                atualizarPatinete();
                break;
            case 4:
                // pat = pesquisarPatinete();
                deletarPatinete();
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_patinete != 0);
    free(pat);
} 

Patinete* preenchePatinete(int id) {
    Patinete* pat;
    pat = (Patinete*) malloc(sizeof(Patinete));
    if (pat == NULL) {
        printf("Erro ao alocar memória para o patinete.\n");
        exit(1);
    }
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    const char* arquivoPatinetes = "patinetes.dat";
    if (id) {
        pat->id = id;
    }else {
        pat->id = obterProximoID(arquivoPatinetes, sizeof(Patinete));
    }

    printf("║ Modelo: ");
    scanf(" %50[^\n]", pat->modelo);
    if (!validarNumAndChar(pat->modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        free(pat);
        while (getchar() != '\n');
        return NULL;
    }

    printf("║ Cor: ");
    scanf(" %50[^\n]", pat->cor);
    if (!validarNome(pat->cor)) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }

    printf("║ Marca: ");
    scanf(" %50[^\n]", pat->marca);
    if (!validarNumAndChar(pat->marca)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }

    printf("║ Ano de Fabricação: ");
    scanf("%d", &pat->ano);
    if (!validaAno(pat->ano)) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
        return NULL;
    } 

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(scanf("%d", &pat->bateria)) != 1 || pat->bateria < 0 || pat->bateria > 100) {
        printf("\nEntrada inválida, digite um valor válido.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }
    pat-> status = 1;
    // tipo 2 para a função listar entender que é patinete
    pat->tipo = 2;

    printf("║                                                                               ║\n");
    printf("║                      Patinete cadastrado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
    return pat;
}

Patinete* pesquisarPatinete(void){
    FILE *fp;
    Patinete* pat;
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    scanf("%d", &id);
    pat = (Patinete*) malloc(sizeof(Patinete));
    fp = fopen("patinetes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    while (fread(pat, sizeof(Patinete), 1, fp) == 1) {
        if (pat->id == id && pat->status == 1) {
            fclose(fp);
            return pat;
        }
    }
    fclose(fp);
    return NULL;
    getchar();
}

void exibePatinete(Patinete* pat) {
    if (pat == NULL) {
        printf("\n= = = Patinete Inexistente = = =\n");
    } else {
        printf("\n= = = Patinete Cadastrado = = =\n");
        printf("║ ID: %d\n", pat->id);
        printf("║ Modelo: %s\n", pat->modelo);
        printf("║ Cor: %s\n", pat->cor);
        printf("║ Marca: %s\n", pat->marca);
        printf("║ Ano de Fabrica: %d\n", pat->ano);
        printf("║ Bateria (capacidade): %d\n", pat->bateria);
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void printPatinete(Patinete* pat){
    printf("\n= = = Patinete Cadastrado = = =\n");
    printf("║ ID: %d\n", pat->id);
    printf("║ Modelo: %s\n", pat->modelo);
    printf("║ Cor: %s\n", pat->cor);
    printf("║ Marca: %s\n", pat->marca);
    printf("║ Ano de Fabrica: %d\n", pat->ano);
    printf("║ Bateria (capacidade): %d\n", pat->bateria);
}

void atualizarPatinete(void) {
    Patinete* pat = (Patinete*) malloc(sizeof(Patinete));
    Patinete* novoPat = (Patinete*) malloc(sizeof(Patinete));

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados do Patinete                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta: ");
    if (verificaNumero(scanf("%d", &pat->id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
	pat = encontrarPeloID(pat, "patinetes.dat", sizeof(Patinete), pat->id);
    if (pat == NULL) {
        printf("Patinete não encontrado!!\n\n");
        free(pat);
        free(novoPat);
        return;
    }else {
        pat->status = 0;
        novoPat = preenchePatinete(pat->id);
        regravarPatinete(novoPat);
        free(pat);
    }

    printf("║                                                                               ║\n");
    printf("║                      Patinete Atualizado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void deletarPatinete(void) {
    int id;
    FILE* fp;
    Patinete* patinete = (Patinete*) malloc(sizeof(Patinete));
    char* nomeArquivo = "patinetes.dat";

    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo!!\n\n");
        return;
    }
    
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Deletar Patinete                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do patinete a excluir: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }

    patinete = encontrarPeloID(patinete, nomeArquivo, sizeof(Patinete), id);
    if (patinete == NULL) {
        printf("Patinete não encontrado!!\n\n");
        while (getchar() != '\n');
        getchar();
        return;
    }else {
        patinete->status = 0;
        regravarPatinete(patinete);
        printf("║                                                                               ║\n");
        printf("║                          Patinete excluído com sucesso!                       ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("Tecle <ENTER> para continuar...");
        getchar();
        getchar();
    }
}

void regravarPatinete(Patinete* patinete) {
    int achou = 0;
    FILE* fp;
    Patinete* patineteLido = (Patinete*) malloc(sizeof(Patinete));

    fp = fopen("patinetes.dat", "r+b");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!!\n\n");
        getchar();
        fclose(fp);
        free(patinete);
        free(patineteLido);
        return;
    }

    while (fread(patineteLido, sizeof(Patinete), 1, fp) && !achou) {
        if (patineteLido->id == patinete->id) {
            achou = 1;
            fseek(fp, -1*sizeof(Patinete), SEEK_CUR);
            fwrite(patinete, sizeof(Patinete), 1, fp);
        }
    }

    fclose(fp);
    free(patinete);
    free(patineteLido);
}