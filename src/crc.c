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

char xor(char a,char b)
{
	printf("\n%c xor %c", a, b);	
	if ((a == '1' && b == '0') || (a == '0' && b == '1'))
	{
		return '1';
	}
	else if ((a == '1' && b == '1') || (a == '0' && b == '0'))
	{
		return '0';
	}
	else
	{
		printf("\nErro no xor. O programa sera encerrado!\n");
		exit(1);
	}
}

void CalculaCRC(char* bin, char* polinomio)
{
	int i, j, pointer = 0;
	
	int tamBin = strlen(bin);
	int tamPol = strlen(polinomio);

	bin = realloc (bin, (tamBin + tamPol-1)*(sizeof(char)));

	for(i=tamBin; i<tamPol-1;i++)
	{
		bin[i]='0';
	}

	char dividendo[tamPol];

	//inicializa o dividendo
	for(i=0;i<tamPol;i++)
	{
		dividendo[i]=bin[i];
	}
	printf("\ndividendo: %s\n", dividendo);

	for(i=0;i<tamBin-tamPol+1;i++)
	{
		if(dividendo[0]!='0')
		{
			for(j=0;j<tamPol-1;j++)
			{
				dividendo[j]=xor(dividendo[j+1], polinomio[j+1]);
			}
			if(i!=tamBin-1)			
				dividendo[tamPol-1]=bin[tamPol+pointer];
		}
		else
		{
			printf("\nbit + significativo e 0\n");
			for(j=0;j<tamPol-1;j++)
			{
				dividendo[j]=xor(dividendo[j+1], '0');
			}
			if(i!=tamBin-1)	
				dividendo[tamPol-1]=bin[tamPol+pointer];
		}
		pointer++;
		printf("\ndividendo: %s\n", dividendo);
	}	
	printf("\nCRC: %s\n", dividendo);
}
