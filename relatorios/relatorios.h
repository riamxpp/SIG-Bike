#ifndef RELATORIOS_H
#define RELATORIOS_H

void relatorios(void);
void listarClientes(void);
void listarBicicletas(void);
void listarPatinetes(void);
void bicicleta_mais_alugadas(void);
void patinetes_mais_alugados(void);
int verificaNumero(int num);
int validarNumAndCharAndCaractere(char[]);
int validarNumAndChar(char[]);
int validarPalavra(char[]);
void listarTodosOsItens(FILE* fp, char* nomeDoArquivo, size_t tamanhoEstrutura, int tipo);

#endif