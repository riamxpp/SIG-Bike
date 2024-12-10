#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bicicletas.h"
#include "../validacao/validacao.h"
#include "../util/util.h"

void bicicletas(void){
    Bicicleta* bicicleta;
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

        Bicicleta *bicicleta  = malloc(sizeof(Bicicleta));
        switch (op_bicicleta) {
            case 1:
                bicicleta = preencheBicicleta();
                printf("%d", bicicleta->id);
                gravaArquivo("bicicletas.dat", bicicleta, sizeof(Bicicleta));
                free(bicicleta);
                break;
            case 2:
                bicicleta = pesquisarBicicleta();
                exibeBicicleta(bicicleta);
                break;
            case 3:
                // atualizarBicicleta();
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

Bicicleta* preencheBicicleta(void) {
    Bicicleta* bicicleta;
    bicicleta = (Bicicleta*) malloc(sizeof(Bicicleta));
    if (bicicleta == NULL) {
        printf("Erro ao alocar memória para o Bicicleta.\n");
        exit(1);
    }

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Bicicleta                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    const char* arquivoBicicletas = "bicicletas.dat";
    bicicleta->id = obterProximoID(arquivoBicicletas, sizeof(Bicicleta));

    printf("║ Modelo: ");
    scanf(" %50[^\n]", bicicleta->modelo);
    if (!validarNumAndChar(bicicleta->modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        free(bicicleta);
        while (getchar() != '\n');
        return NULL;
    }

    printf("║ Cor: ");
    scanf(" %50[^\n]", bicicleta->cor);
    if (!validarNome(bicicleta->cor)) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        free(bicicleta);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }

    printf("║ Marca: ");
    scanf(" %50[^\n]", bicicleta->marca);
    if (!validarNumAndChar(bicicleta->marca)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        free(bicicleta);
        while (getchar() != '\n');
        getchar();
        return NULL;
    }

    printf("║ Ano de Fabricação: ");
    scanf("%d", &bicicleta->ano);
    if (!validaAno(bicicleta->ano)) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        free(bicicleta);
        while (getchar() != '\n');
        getchar();
        return NULL;
    } 

    printf("║ Tamanho do Quadro:  ");
    if (verificaNumero(scanf("%d", &bicicleta->tam_quadro)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return NULL;
    }
    bicicleta->status = "a";
    bicicleta->tipo = 1;
    
    printf("║                                                                               ║\n");
    printf("║                      Bicicleta cadastrado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);    

    return bicicleta;
}

Bicicleta* pesquisarBicicleta(){
    FILE *fp;
    Bicicleta* bicicleta;
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Bicicleta                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta:  ");
    scanf("%d", &id);
    getchar();

    char* nomeArquivo = "bicicletas.dat";

    bicicleta = encontrarPeloID(bicicleta, nomeArquivo, fp, sizeof(Bicicleta), id);

    if (bicicleta == NULL) {
        printf("Erro ao pesquisar bicicleta!!\n\n");
        getchar();
        return NULL;
    }
    return bicicleta;
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void exibeBicicleta(Bicicleta* bicicleta) {
    if (bicicleta == NULL) {
        printf("\n= = = Bicicleta Inexistente = = =\n");
    } else {
        printf("\n= = = Bicicleta Cadastrado = = =\n");
        printf("║ ID: %d\n", bicicleta->id);
        printf("║ Modelo: %s\n", bicicleta->modelo);
        printf("║ Cor: %s\n", bicicleta->cor);
        printf("║ Marca: %s\n", bicicleta->marca);
        printf("║ Ano de Fabrica: %d\n", bicicleta->ano);
        printf("║ Bateria (capacidade): %d\n", bicicleta->tam_quadro);
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

// void atualizarBicicleta(void){
//     Bicicleta* bicicleta;
//     system("clear||cls");
//     printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
//     printf("║                          Atualizar Dados da Bicicleta                         ║\n");
//     printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
//     printf("║ Informe o ID da Bicicleta: ");
    
//     if (verificaNumero(scanf("%d", &bicicleta->id)) != 1) {
//         printf("\nEntrada inválida, digite apenas números.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     }

//     printf("║                                                                               ║\n");
//     printf("║                           ↪Digite os Novos Dados↩                             ║\n");
//     printf("║ Modelo: ");
//     bicicleta->modelo = (char*) malloc(20*sizeof(char));
//     scanf("%99s", bicicleta->modelo);
//     if (!validarNumAndChar(bicicleta->modelo)) {
//         printf("\nEntrada inválida, digite apenas letras e números.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     }

//     printf("║ Cor: ");
//     bicicleta->cor = (char*) malloc(20*sizeof(char));
//     scanf("%99s", bicicleta->cor);
//     if (validarPalavra(bicicleta->cor)) {
//         printf("\nEntrada inválida, digite apenas letras.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     }

//     printf("║ Marca: ");
//     bicicleta->marca = (char*) malloc(12*sizeof(char));
//     scanf("%99s", bicicleta->marca);
    
//     if (!validarNumAndChar(bicicleta->marca)){
//         printf("\nEntrada inválida, digite apenas letras e números.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     };

//     printf("║ Ano de Fabricação: ");
//     scanf("%d", &bicicleta->ano);
    
//     if (!validaAno(bicicleta->ano)) {
//         printf("\nEntrada inválida, digite apenas números.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     }

//     printf("║ Tamanho do Quadro:  ");
//     if (verificaNumero(scanf("%d", &bicicleta->tam_quadro)) != 1) {
//         printf("\nEntrada inválida, digite apenas números.  \n");
//         while (getchar() != '\n');
//         getchar();
//         return;
//     }

//     printf("║                             Bicicleta atualizada                              ║\n");
//     printf("║                                   Aguarde...                                  ║\n");
//     printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
//     free(bicicleta->modelo);
//     free(bicicleta->marca);
//     free(bicicleta->cor);
//     sleep(1);
// }

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
