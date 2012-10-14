/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
crc.h
=========================================================================================================*/


#ifndef CRC_H
#define CRC_H

//calcula a operação OU exclusivo entre os caracteres A e B recebidos por parametro
char xor(char a,char b);

//calcula o CRC a partir de uma sequencia de binarios e do polinomio definido
void CalculaCRC(char* bin, char* polinomio);

#endif
