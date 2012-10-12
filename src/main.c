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

#define FirstDigit 48

unsigned long fileLen;

char* ReadFile(char *name)
{
	FILE *file;
	char *buffer;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", name);
		return;
	}

	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer=(char *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
                                fclose(file);
		return;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

	return buffer;

}


void BinToHex(char* BinData, char* HexData)
{
   long int Number = 0;
   int BinLength = strlen(BinData);

   for(int i=0; i<BinLength; i++)
   {
      Number += ((BinData[BinLength - i - 1] - FirstDigit) * pow(2, i));
   }

   snprintf(HexData, BinLength,"%d", Number);
}

int main(int argc, char *argv[])
{
	char *polinomio;
	char *entrada;

	if(argc != 3)
	{
        	printf("\nQuantidade de parametros invalida!\n");
	        return 1;
	}

	if(atoi(argv[2]) == 0)//polinomio de 8 bits
	{
		polinomio = "100000111";
	}
	else if(atoi(argv[2]) == 1)//polinomio de 16 bits
	{
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


	//Chama a função LeEntrada, que fará a leitura bit a bit do arquivo
	//LeEntrada(entrada);

	for (int i=0; i<fileLen; i++)
        printf("%c",entrada[i]);

	//Fecha o arquivo de entrada
	free(entrada);
	printf("\nPROGRAMA ENCERRADO COM SUCESSO!\n");

	return 0;
}

