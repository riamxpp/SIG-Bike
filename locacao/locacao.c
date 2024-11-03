#include <stdio.h>
#include <stdlib.h>
#include "locacao.h"
#include <unistd.h>
#include "view.h"

void locacao(void){
    int op_locacao;
    do{
        op_locacao = menuLocacao();
        switch (op_locacao) {
            case 1:
                reservarBicicleta();
                break;
            case 2:
                reservarPatinete();
                break;
            case 3:
                devolverBicicleta();
                break;
            case 4:
                devolverPatinete();
                break;
            case 5: 
                consultarAluguel();
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_locacao != 0);
}

void reservarBicicleta(void){
    menuReservarBicicleta();
    printf("║ Informe o ID da Bicicleta:                                                    ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void reservarPatinete(void){
    menuReservarPatinete();
    printf("║ Informe o ID do Patinete:                                                     ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void devolverBicicleta(void){
    menuDevolverBicicleta();
    printf("║ Informe o ID da Bicicleta:                                                    ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void devolverPatinete(void){
    menuDevolverPatinete();
    printf("║ Informe o ID do Patinete:                                                     ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void consultarAluguel(void){
    menuConsultarAluguel();
    printf("║ Você deseja consultar por Bicicleta ou Patinete:                              ║\n");
    printf("║                                                                               ║\n");
    printf("║ Informe o ID:                                                                 ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}