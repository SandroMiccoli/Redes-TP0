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
	char *polinomio;
	char *entrada;
	int tamPol;

    	char *bin;

	if(argc != 3)
	{
        	printf("\nQuantidade de parametros invalida!\n");
	        return 1;
	}

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
	else
	{
		printf("\nPolinomio desconhecido. O programa sera encerrado!\n");
		return 1;
	}

	//Nome do arquivo de entrada
	char *arquivoEntrada = argv[1];

	//Abertura do arquivo
	entrada = ReadFile(arquivoEntrada);

	bin=(char *)malloc((fileLen*8)+tamPol+1);
	bin[fileLen*8+tamPol]='\0';
	
	printf("\nfileLen: %d\n", fileLen);
	printf("\ncaracteres (fileLen/8): %d\n", fileLen/8);
	printf("\ntamPol: %d\n", tamPol);
	printf("\nalocado pro bin: %d\n", (fileLen)*8+tamPol);

	*bin = NULL;

	arquivo_to_bin(bin,entrada);

	//printf("Binario: %s\n",bin);
	printf("\nPolinomio: %s\n", polinomio);

	CalculaCRC(bin, polinomio);
	
	free(entrada);
    free(bin);
	printf("\nPROGRAMA ENCERRADO COM SUCESSO!\n");


	return 0;
}

