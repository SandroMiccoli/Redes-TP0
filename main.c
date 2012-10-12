/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
main.c
=========================================================================================================*/

#include <stdlib.h>
#include <string.h>
#include "crc.h"

int main(int argc, char *argv[])
{

	if(argc != 3)
	{
        	printf("\nQuantidade de parametros invalida!\n");
	        return 1;
	}

	if(atoi(argv[2]) == 0)//polinomio de 8 bits
	{
		char polinomio[10] = "100000111";
	}
	else if(atoi(argv[2] == 1)//polinomio de 16 bits
	{
		char polinomio[18] = "11000000000000101";
	}
	else
	{
		printf("\nPolinomio desconhecido. O programa sera encerrado!");
		return 1;
	}

	//Arquivo de entrada
	FILE *entrada;

	//Nome do arquivo de entrada
	char *arquivoEntrada = argv[1];

	//Abertura do arquivo
	entrada = fopen(arquivoEntrada, "rb");

	//Verifica se a abertura foi bem-sucedida
	if(!entrada)
	{
		printf("\nErro ao abrir o arquivo de entrada. O programa sera encerrado!");
		exit(1);
	}

	//Chama a função LeEntrada, que fará a leitura bit a bit do arquivo
	LeEntrada(entrada);

	//Fecha o arquivo de entrada
	fclose(entrada);
	printf("\nPROGRAMA ENCERRADO COM SUCESSO!\n");

	return 0;
}

