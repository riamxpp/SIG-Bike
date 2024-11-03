#include <stdio.h>
#include <stdlib.h>
#include "view.h"

int menuLocacao(void){
    int op_locacao;
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Módulo Locação                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║                            1. Reservar Bicicleta                              ║\n");
    printf("║                            2. Reservar Patinete                               ║\n");
    printf("║                            3. Devolver Bicicleta                              ║\n");
    printf("║                            4. Devolver Patinete                               ║\n");
    printf("║                            5. Consultar Locação                               ║\n");
    printf("║                                                                               ║\n");
    printf("║                            0. Voltar                                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf(" Digite a opção desejada: ");
    scanf("%d", &op_locacao);
    getchar();
    return op_locacao;
}

void menuReservarBicicleta(void){
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              Reservar Bicicleta                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
}

void menuReservarPatinete(void){
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              Reservar Patinete                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
}