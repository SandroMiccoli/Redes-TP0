/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
crc.c
=========================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "crc.h"
#include "hex_bin.h"


//calcula a operação OU exclusivo entre os caracteres A e B recebidos por parametro
char xor(char a,char b)
{	
	if ((a == '1' && b == '0') || (a == '0' && b == '1'))// A xor B = 1
	{
		return '1';
	}
	else if ((a == '1' && b == '1') || (a == '0' && b == '0')) // A xor B = 0
	{
		return '0';
	}
	else //A ou B são diferentes de 1 ou 0: erro
	{
		printf("\nErro no xor. O programa sera encerrado!\n");
		exit(1);
	}
}

//calcula o CRC a partir de uma sequencia de binarios e do polinomio definido
void CalculaCRC(char* bin, char* polinomio)
{
	int i, j, pointer = 0; //i e j = contadores; pointer aponta para uma posicao do vetor de bits

	char *hex; //irá armazenar o CRC em hexadecimal
	
	//armazenam o tamanho dos vetores de binarios e do polinomio
	int tamBin = strlen(bin);
	int tamPol = strlen(polinomio);
	
	//aloca espacao para o vetor HEX
	hex = (char*) malloc ((tamPol/4)+3);
	*hex = NULL;
	hex[tamPol/4+2]='\0';

	//adiciona tamPol-1 zeros ao final do vetor de binários
	for(i=tamBin; i<tamBin+tamPol-1;i++)
	{
		bin[i]='0';
	}
	
	//calcula novo tamBin após adição dos 0's ao final
	tamBin = strlen(bin);

	//armazena os dividendos das divisões consecutivas até encontrar o resto
	char dividendo[tamPol+1];

	//inicializa o dividendo com os primeiros tamPol bits do vetor binário
	for(i=0;i<tamPol;i++)
	{
		dividendo[i]=bin[i];
	}
	dividendo[tamPol]='\0';

	//realiza as divisões sucessivas até encontrar o resto que é o CRC
	for(i=0;i<tamBin-tamPol+1;i++)
	{
		//verifica se o dividendo é divisível pelo polinômio
		if(dividendo[0]!='0')
		{
			//realiza o XOR bit a bit da divisão
			for(j=0;j<tamPol-1;j++)
			{
				dividendo[j]=xor(dividendo[j+1], polinomio[j+1]);
			}
			//adiciona o próximo bit ao dividendo, exceto na ultima interação
			if(tamBin!=tamPol+pointer+1)			
				dividendo[tamPol-1]=bin[tamPol+pointer];
		}
		else //dividendo não é divisível pelo polinômio
		{
			//realiza o XOR de cada bit do dividendo XOR 0
			for(j=0;j<tamPol-1;j++)
			{
				dividendo[j]=xor(dividendo[j+1], '0');
			}
			//adiciona o próximo bit ao dividendo, exceto na ultima interação
			if(tamBin!=tamPol+pointer+1)
				dividendo[tamPol-1]=bin[tamPol+pointer];
		}
		pointer++;
		//printf("\ndividendo: %s\n", dividendo);
	}

	printf("\nCRC binario: %s\n", dividendo);

	//calcula o CRC na base hexadecimal
	BinToHex(dividendo, hex);

	printf("\nCRC em hex: %s\n", hex);

	free(hex);
}
