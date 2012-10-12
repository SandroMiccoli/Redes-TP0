/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
crc.c
=========================================================================================================*/

int xor(int a,int b)
{
	if ((a || b) && !(a && b))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
