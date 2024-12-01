#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bicicletas.h"
#include <unistd.h>
#include "../validacao/validacao.h"


struct bicicleta {
    int id;
    int tam_quadro;
    char *cor;
    char *marca;
    char *modelo;
    int ano;
};


void bicicletas(void){
    int op_bicicleta;
    
    do{
        system("clear||cls");
        printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                               Módulo Bicicletas                               ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("║                                1. Cadastrar                                   ║\n");
        printf("║                                2. Pesquisar                                   ║\n");
        printf("║                                3. Atualizar                                   ║\n");
        printf("║                                4. Deletar                                     ║\n");
        printf("║                                                                               ║\n");
        printf("║                                0. Voltar                                      ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf(" Digite a opção desejada: ");
        if (verificaNumero(scanf("%d", &op_bicicleta)) != 1) {
            printf("\nEntrada inválida, digite apenas números.  \n");
            while (getchar() != '\n');
            getchar();
            return;
        }
        getchar();

        switch (op_bicicleta) {
            case 1:
                cadastrarBicicleta();
                break;
            case 2:
                pesquisarBicicleta();
                break;
            case 3:
                atualizarBicicleta();
                break;
            case 4:
                deletarBicicleta();
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_bicicleta != 0);
}

void cadastrarBicicleta(void){
    struct bicicleta bicicleta;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Bicicleta                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ ID: ");

    if (verificaNumero(scanf("%d", &bicicleta.id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    bicicleta.modelo = (char*) malloc(20*sizeof(char));
    printf("║ Modelo: ");
    scanf("%99s", bicicleta.modelo);

    if (!validarNumAndChar(bicicleta.modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor: ");
    bicicleta.cor = (char*) malloc(20*sizeof(char));

    if (validarPalavra(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", bicicleta.cor)) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    bicicleta.marca = (char*) malloc(12*sizeof(char));
    printf("║ Marca: ");
    scanf("%99s", bicicleta.marca);

    if (!validarNumAndChar(bicicleta.marca)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Ano de Fabricação; ");
    if (verificaNumero(scanf("%d", &bicicleta.ano)) != 1 || bicicleta.ano < 1000 || bicicleta.ano > 9999) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Tamanho do Quadro:  ");
    if (verificaNumero(scanf("%d", &bicicleta.tam_quadro)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                      Bicicleta cadastrada com sucesso!                        ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    free(bicicleta.modelo);
    free(bicicleta.marca);
    free(bicicleta.cor);
    sleep(1);
}

void pesquisarBicicleta(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Bicicleta                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta:  ");

    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite um número.  \n");
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
    printf("║ Tamanho do Quadro:                                                            ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void atualizarBicicleta(void){
    struct bicicleta bicicleta;
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados da Bicicleta                         ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta: ");
    
    if (verificaNumero(scanf("%d", &bicicleta.id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
    printf("║ Modelo: ");
    bicicleta.modelo = (char*) malloc(20*sizeof(char));
    scanf("%99s", bicicleta.modelo);
    if (!validarNumAndChar(bicicleta.modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor: ");
    bicicleta.cor = (char*) malloc(20*sizeof(char));

    if (validarPalavra(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", bicicleta.cor)) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    bicicleta.marca = (char*) malloc(12*sizeof(char));
    scanf("%99s", bicicleta.marca);
    
    if (!validarNumAndChar(bicicleta.marca)){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();
    
    printf("║ Ano de Fabricação: ");
    if (verificaNumero(scanf("%d", &bicicleta.ano)) != 1 || bicicleta.ano < 1000 || bicicleta.ano > 9999) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Tamanho do Quadro:  ");
    if (verificaNumero(scanf("%d", &bicicleta.tam_quadro)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                             Bicicleta atualizada                              ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    free(bicicleta.modelo);
    free(bicicleta.marca);
    free(bicicleta.cor);
    sleep(1);
}

void deletarBicicleta(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Excluir Bicicleta                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da bicicleta à excluir: ");

    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();
    printf("║                                                                               ║\n");
    printf("║                                                                               ║\n");
    printf("║                       Bicicleta excluída com sucesso                          ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}
