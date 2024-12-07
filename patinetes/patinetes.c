#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
                pat = preenchePatinete();
                gravaArquivo("patinetes.dat", pat, sizeof(Patinete));
                break;
            case 2:
                pat = pesquisarPatinete();
                exibePatinete(pat);
                break;
            case 3:
                atualizarPatinete();
                break;
            case 4:
                pat = pesquisarPatinete();
                deletarPatinete(pat);
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_patinete != 0);
} 

Patinete* preenchePatinete(void) {
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
    pat->id = obterProximoID();

    printf("║ Modelo: ");
    scanf(" %50[^\n]", pat->modelo);
    if (!validarNumAndChar(pat->modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
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
    printf("║                                                                               ║\n");
    printf("║                      Patinete cadastrado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
    return pat;
}

int obterProximoID() {
    FILE* arquivo = fopen("patinetes.dat", "rb");
    if (arquivo == NULL) {
        return 1;
    }
    Patinete temp;
    int ultimoID = 0;

    while (fread(&temp, sizeof(Patinete), 1, arquivo) == 1) {
        ultimoID = temp.id;
    }

    fclose(arquivo);
    return ultimoID + 1;
}

Patinete* pesquisarPatinete(void){
    FILE *fp;
    Patinete* pat;
    int id;
    int encontrado = 0;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    scanf("%d", &id);
    getchar();

    pat = (Patinete*) malloc(sizeof(Patinete));
    fp = fopen("patinetes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(pat);
        exit(1);
    }
    while (fread(pat, sizeof(Patinete), 1, fp) == 1) {
        if (pat->id == id) {
            encontrado = 1;
            break;
        }
    }
    fclose(fp);
    if (encontrado) {
        return pat;
    } else {
        free(pat);
        return NULL;
    }
    printf("Tecle <ENTER> para continuar...");
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

void atualizarPatinete(void){
    return;
    /*
    struct patinete patinete;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados do Patinete                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(scanf("%d", &patinete.id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");

    printf("║                                                                               ║\n");
    patinete.modelo = (char*) malloc(20*sizeof(char));
    printf("║ Modelo: ");
    scanf("%99s", patinete.modelo);

    if (!validarNumAndChar(patinete.modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }

    printf("║ Cor: ");
    patinete.cor = (char*) malloc(20*sizeof(char));
    scanf("%99s", patinete.cor);
    if (validarPalavra(patinete.cor)) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    patinete.marca = (char*) malloc(12*sizeof(char));
    printf("║ Marca: ");
    scanf("%99s", patinete.marca);

    if (!validarNumAndChar(patinete.marca)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();
    
    printf("║ Ano de Fabricação: ");
    scanf("%d", &patinete.ano);

    if (!validaAno(patinete.ano)) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(scanf("%d", &patinete.bateria)) != 1 || patinete.bateria < 0 || patinete.bateria > 100) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                      Patinete Atualizado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    free(patinete.modelo);
    free(patinete.marca);
    free(patinete.cor);
    sleep(1);
    */
}

void deletarPatinete(Patinete* patLido) {
    FILE *fp, *temp;
    Patinete* patArq;
    int achou = 0;

    if (patLido == NULL) {
        printf("O patinete informado não existe!\n");
        return;
    } 

    patArq = (Patinete*) malloc(sizeof(Patinete));
    if(patArq == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    fp = fopen("patinetes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(patArq);
        exit(1);
    }

    temp =fopen("temp.dat","wb");
    if (temp == NULL) {
        printf("Ops! Erro na criação do arquivo temporário!\n");
        fclose(fp);
        free(patArq);
        exit(1);
    }

    while (fread(patArq, sizeof(Patinete), 1, fp) == 1) {
        if (patArq->id == patLido->id) {
            achou = 1;
        } else {
            fwrite(patArq, sizeof(Patinete), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    free(patArq);

    if (achou) {
        remove("patinetes.dat");
        rename("temp.dat", "patinetes.dat");
        printf("║                                                                               ║\n");
        printf("║                          Patinete excluído com sucesso!                       ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    } else {
        remove("temp.dat");
        printf("\nPatinete não encontrado!\n");
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
    /*
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Deletar Patinete                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do patinete a excluir: ");
    */
}

