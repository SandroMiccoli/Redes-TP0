/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
main.c
=========================================================================================================*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "crc.h"
#include "hex_bin.h"

int main(int argc, char *argv[])
{
	char *polinomio; //armazena o polinomio gerador
	char *entrada; //ponteiro para o arquivo de entrada
	int tamPol; //tamanho do polinomio gerador
	char *bin; //armazena os bits lidos do arquivo de entrada

	//verificação do numero de parâmetros do programa
	if(argc != 3)
	{
        	printf("\nQuantidade de parametros invalida!\n");
	        return 1;
	}

	//verificação do polinômio gerador
	if(atoi(argv[2]) == 0)//polinomio de 8 bits
	{
		tamPol = 8;		
		polinomio = "100000111";	
	}
	else if(atoi(argv[2]) == 1)//polinomio de 16 bits
	{
		tamPol = 16;		
		polinomio = "11000000000000101";
	}
	else //polinômio não pré-definido
	{
		printf("\nPolinomio desconhecido. O programa sera encerrado!\n");
		return 1;
	}

	//Nome do arquivo de entrada
	char *arquivoEntrada = argv[1];

	//Abertura do arquivo
	entrada = ReadFile(arquivoEntrada);

	//aloca espacao para o vetor de bits do arquivo
	bin=(char *)malloc((fileLen*8)+tamPol+1);
	*bin = NULL;
	bin[fileLen*8+tamPol]='\0';

	//chama a função que converte a entrada para binário
	ArquivoToBin(bin,entrada);

	//chama a função que calcula o CRC
	CalculaCRC(bin, polinomio);
	
	//libera a memória
	free(entrada);
    free(bin);
    
	printf("\nPROGRAMA ENCERRADO COM SUCESSO!\n");

	return 0;
}

