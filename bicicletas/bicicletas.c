#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bicicletas.h"
#include "../validacao/validacao.h"
#include "../util/util.h"

void bicicletas(void){
    Bicicleta* bicicleta;
    int op_bicicleta, statusExibe;

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
                statusExibe = exibeBicicleta(bicicleta);
                if (statusExibe != 1) {
                    printf("\nBicicleta inexistente!!\n\n");
                }
                getchar();
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
    bicicleta->status = 1;
    // tipo 1 para a função listar entender que é bicicleta
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

int exibeBicicleta(Bicicleta* bicicleta) {
    if (bicicleta == NULL) {
        printf("\n= = = Bicicleta Inexistente = = =\n");
    } else {
        if (bicicleta->status == 1) {   
            printBicicleta(bicicleta);
            return 1;
        } 

        return 0;
    }
}

void atualizarBicicleta(void){
    Bicicleta* bicicleta;
    FILE* fp;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados da Bicicleta                         ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta: ");
    if (verificaNumero(scanf("%d", &bicicleta->id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }

    const char* nomeArquivo = "bicicletas.dat";
    bicicleta = encontrarPeloID(bicicleta, nomeArquivo, fp, sizeof(Bicicleta), bicicleta->id);
    
    if (bicicleta == NULL) {
        printf("Bicicleta não encontrada!!!\n\n");
        free(bicicleta);
        return;
    }else {
        bicicleta = preencheBicicleta();
        bicicleta->status = 0;
        regravarBicicleta(bicicleta);
        free(bicicleta);
    }

    printf("║                             Bicicleta atualizada                              ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void deletarBicicleta(void){
    int id;
    FILE* fp;
    Bicicleta* bicicleta;
    const char* nomeArquivo = "bicicletas.dat";

    fp = fopen(nomeArquivo, "r+b");
    if (fp == NULL) {
        printf("Error ao abrir o arquivo!!\n\n");
        exit(1);
    }
    bicicleta = (Bicicleta*) malloc(sizeof(Bicicleta));    

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
    bicicleta = encontrarPeloID(bicicleta, nomeArquivo, fp, sizeof(Bicicleta), id);

    if (bicicleta == NULL) {
        printf("Bicicleta não encontrada!!\n\n");
        while (getchar() != '\n');
        getchar();
        return NULL;
    }else {
        bicicleta->status = 0;
        regravarBicicleta(bicicleta);
        
        printf("║                                                                               ║\n");
        printf("║                                                                               ║\n");
        printf("║                       Bicicleta excluída com sucesso                          ║\n");
        printf("║                                   Aguarde...                                  ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        sleep(1);
    }  
}

void regravarBicicleta(Bicicleta* bicicleta) {
    int achou;
    FILE* fp;
    Bicicleta* bicicletaLida;

    bicicletaLida = (Bicicleta*) malloc(sizeof(Bicicleta));
    fp = fopen("bicicletas.dat", "r+b");

    if (fp == NULL ){
        printf("Erro ao abrir arquivo!!\n\n");
        getchar();
        fclose(fp);
        free(bicicleta);
        return;
    }
    achou = 0;
    while (fread(bicicletaLida, sizeof(Bicicleta), 1, fp) && !achou) {
        if (bicicletaLida->id == bicicleta->id) {
            achou = 1;
            // faz o apontador voltar um item, pois ao encontrar o item a ser modificado ele está no item seguinte
            fseek(fp, -1*sizeof(Bicicleta), SEEK_CUR);
            fwrite(bicicleta, sizeof(Bicicleta), 1, fp);
        }
    }
    fclose(fp);
    free(bicicletaLida);
}