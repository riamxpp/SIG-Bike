#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "patinetes.h"
#include <string.h>
#include "../validacao/validacao.h"

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
                gravaPatinete(pat);
                break;
            case 2:
                pesquisarPatinete();
                break;
            case 3:
                atualizarPatinete();
                break;
            case 4:
                deletarPatinete();
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

    /*
    if (verificaNumero(scanf("%d", &pat->id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        free(pat);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }
    */

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

void gravaPatinete(Patinete* pat) {
    FILE* fp;
    fp = fopen("patinetes.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(pat, sizeof(Patinete), 1, fp);
    fclose(fp);
}

void pesquisarPatinete(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }

    getchar();
    printf("║                                                                               ║\n");
    printf("║ Modelo:                                                                       ║\n");
    printf("║ Cor:                                                                          ║\n");
    printf("║ Marca:                                                                        ║\n");
    printf("║ Ano de Fabricação:                                                            ║\n");
    printf("║ Bateria (capacidade):                                                         ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
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

void deletarPatinete(void){
    int id;
    
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
    getchar();

    printf("║                                                                               ║\n");
    printf("║                          Patinete excluído com sucesso!                       ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}