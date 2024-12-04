#include <stdio.h>
#include <string.h>
#include <stddef.h>


// char* pegaID(char str[255]){
//   char* primeiros = (char*) malloc(3*sizeof(char));
//   // remove o \n do final da string
//   str[strcspn(str, "\n")] = "\0";
//   //copia os 3 primeiros caracteres da string para a variável primeiro
//   strncpy(primeiros, str, 3);
//   primeiros[3] = '\0';

//   return primeiros;
// }

void obterTresPrimeiros(char* str, char* destino, size_t tamanhoDestino) {
  removerNovaLinha(str);

  strncpy(destino, str, tamanhoDestino - 1);
  destino[3] = '\0';
}

void removerNovaLinha(char* str) {
  str[strcspn(str, "\n")] = "\0";
}