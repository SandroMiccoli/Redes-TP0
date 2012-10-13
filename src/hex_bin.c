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


char* ReadFile(char *name)
{
	FILE *file;
	char *buffer;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Não foi possível abrir o arquivo: %s", name);
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
		fprintf(stderr, "Não há memória suficiente!");
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
   int Number = 0, i;
   int BinLength = strlen(BinData);

   for(i=0; i<BinLength; i++)
   {
      Number += ((BinData[BinLength - i - 1] - FirstDigit) * pow(2, i));
   }

   snprintf(HexData, BinLength,"%d", Number);
}


const char * const quads[] = {"0000", "0001", "0010", "0011", "0100", "0101",
                              "0110", "0111", "1000", "1001", "1010", "1011",
                              "1100", "1101", "1110", "1111"};

const char * hex_to_bin_quad(unsigned char c){
  if (c >= '0' && c <= '9') return quads[     c - '0'];
  if (c >= 'A' && c <= 'F') return quads[10 + c - 'A'];
  if (c >= 'a' && c <= 'f') return quads[10 + c - 'a'];
  return -1;
}

void arquivo_to_bin(char * bin, char * arquivo){
    char hex[2];
    for (int i=0; i<fileLen; i++){
        sprintf(hex,"%02x", (unsigned int) arquivo[i] & 0xff);
        for (int j=0; j<2; j++){
            strncat(bin,hex_to_bin_quad(hex[j]),4);
        }

	}
}
