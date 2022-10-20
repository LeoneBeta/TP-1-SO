#pragma once

// Tamanho máximo do nome de arquivo.
#define TAMANHO_NOME_ARQUIVO 80

// Tamanho máximo de uma instrução LPAS.
#define TAMANHO_INSTRUCAO 10

// Número máximo de instruções do programa LPAS.
#define NUMERO_MAXIMO_DE_INSTRUCOES 100

// Número máximo de variáveis do programa.
#define NUMERO_MAXIMO_DE_VARIAVEIS 25

// Número máximo de programas da máquina de execução.
#define NUMERO_MAXIMO_DE_PROGRAMAS 4

// Códigos das instruções LPAS.
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUB 31
#define MUL 32
#define DIV 33
#define HALT 40

// Representa uma instrução LPAS.
typedef char Instrucao[TAMANHO_INSTRUCAO];

// Representa o nome do programa.
typedef char NomePrograma[TAMANHO_NOME_ARQUIVO];

// Representa a estrutura de um programa LPAS.
typedef struct  {
   	// Número de instruções do programa.
	unsigned short numeroDeInstrucoes;

	// Nome do programa.
	NomePrograma nome;

	/* Memória de código para armazenar as instruções LPAS que compõem o programa.
	   Cada instrução é armazenada em uma posição do vetor. */
	Instrucao instrucoes[NUMERO_MAXIMO_DE_INSTRUCOES];
} Programa;


/* Códigos resultantes da excução do programa LPAS. Os códigos válidos são:
 
	 0 = execução bem sucedida; 
	 1 = instrução LPAS inválida;
	 2 = argumento de instrução LPAS inválido;
	 3 = argumento de instrução LPAS ausente;
	 4 = duas ou mais instruções LPAS na mesma linha de código;
	 5 = símbolo inválido.
*/
typedef enum { EXECUCAO_BEM_SUCEDIDA, 
			   INSTRUCAO_LPAS_INVALIDA, 
			   ARGUMENTO_INSTRUCAO_LPAS_INVALIDO, 
               ARGUMENTO_INSTRUCAO_LPAS_AUSENTE, 
			   MUITAS_INSTRUCOES, 
			   SIMBOLO_INVALIDO 
} Erro;

typedef struct {
	unsigned short numeroLinha;
	Instrucao instrucao;
	NomePrograma nome;
	Erro erro;
} ErroExecucao;			   


typedef struct  {
	// Número de programas LPAS carregados na memória da Máquina de Execução.
	int numeroDeProgramas;

	// Memória de código que armazena os programas LPAS a serem executados na máquina de execução.
	Programa codigo[NUMERO_MAXIMO_DE_PROGRAMAS];

	// Registrador da máquina de execução LPAS.
	int registrador;

	// Memória de dados que armazena as variáveis do programa LPAS que está em execução na ME.
	int variaveis[NUMERO_MAXIMO_DE_VARIAVEIS];

	// Identifica a instrução, o número da linha e o nome do programa onde o erro de execução ocorreu.
	ErroExecucao erroExecucao;
} MaquinaExecucao;
