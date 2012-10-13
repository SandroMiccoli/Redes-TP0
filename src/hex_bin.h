/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
hex_bin.h
=========================================================================================================*/


#ifndef HEX_BIN_H_
#define HEX_BIN_H_

#define FirstDigit 48

long fileLen;

char* ReadFile(char *name);

void BinToHex(char* BinData, char* HexData);

const char * hex_to_bin_quad(unsigned char c);

void arquivo_to_bin(char * bin, char * arquivo);








#endif /* HEX_BIN */
