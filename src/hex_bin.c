/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
hex_bin.c
=========================================================================================================*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "crc.h"
#include "hex_bin.h"

//realiza a leitura do arquivo e retorna sem conteudo em um buffer
char* ReadFile(char *name)
{
	FILE *file;
	char *buffer;

	//abre o arquivo
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Não foi possível abrir o arquivo: %s", name);
		exit(1);
	}

	//determina o tamanho do arquivo
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//aloca memória para os dados
	buffer=(char *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Não há memória suficiente!");
                fclose(file);
		exit(1);
	}

	//faz a leitura dos dados do arquivo
	fread(buffer, fileLen, 1, file);
	fclose(file);

	return buffer;

}

//converte os dados em binário para hexadecimal
void BinToHex(char* bin, char *hex)
{
	//compara os bits 4 a 4 e faz a conversão para hexadecimal
	strcat(hex, "0x");
	while (*bin != '\0')
	{
		if (strncmp(bin, "0000", 4) == 0) strcat(hex,"0");
		else if (strncmp(bin, "0001", 4) == 0) strcat(hex,"1");
		else if (strncmp(bin, "0010", 4) == 0) strcat(hex,"2");
		else if (strncmp(bin, "0011", 4) == 0) strcat(hex,"3");
		else if (strncmp(bin, "0100", 4) == 0) strcat(hex,"4");
		else if (strncmp(bin, "0101", 4) == 0) strcat(hex,"5");
		else if (strncmp(bin, "0110", 4) == 0) strcat(hex,"6");
		else if (strncmp(bin, "0111", 4) == 0) strcat(hex,"7");
		else if (strncmp(bin, "1000", 4) == 0) strcat(hex,"8");
		else if (strncmp(bin, "1001", 4) == 0) strcat(hex,"9");
		else if (strncmp(bin, "1010", 4) == 0) strcat(hex,"A");
		else if (strncmp(bin, "1011", 4) == 0) strcat(hex,"B");
		else if (strncmp(bin, "1100", 4) == 0) strcat(hex,"C");
		else if (strncmp(bin, "1101", 4) == 0) strcat(hex,"D");
		else if (strncmp(bin, "1110", 4) == 0) strcat(hex,"E");
		else if (strncmp(bin, "1111", 4) == 0) strcat(hex,"F");

		bin += 4; /* avança 4 posições na string de zeros e uns */
	}
}

const char * const quads[] = {"0000", "0001", "0010", "0011", "0100", "0101",
                              "0110", "0111", "1000", "1001", "1010", "1011",
                              "1100", "1101", "1110", "1111"};

const char * HexToBin(unsigned char c){
  if (c >= '0' && c <= '9') return quads[     c - '0'];
  if (c >= 'A' && c <= 'F') return quads[10 + c - 'A'];
  if (c >= 'a' && c <= 'f') return quads[10 + c - 'a'];
  return -1;
}

//converte os caracteres lidos do arquivo para binário
void ArquivoToBin(char * bin, char * arquivo){
   	char hex[2];
	for (int i=0; i<fileLen; i++)
	{
	        sprintf(hex,"%02x", (unsigned int) arquivo[i] & 0xff);
	        for (int j=0; j<2; j++)
		{
		        strncat(bin,HexToBin(hex[j]),4);
	        }

	}
}
