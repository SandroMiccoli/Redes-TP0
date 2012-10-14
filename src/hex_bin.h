/*=======================================================================================================
TRABALHO PRATICO 0 - Redes de Computadores
@LEANDRO DUARTE DE ASSIS
@SANDRO MICCOLI ALVES
hex_bin.h
=========================================================================================================*/


#ifndef HEX_BIN_H_
#define HEX_BIN_H_

#define FirstDigit 48

long fileLen; //armazena o tamanho do arquivo

//realiza a leitura dos dados do arquivo
char* ReadFile(char *name);

//converte binário para hexadecimal
void BinToHex(char* bin, char *hex);

//converte hexadecimal para binário
const char * HexToBin(unsigned char c);

//converte os dados lidos do arquivo para binario
void ArquivoToBin(char * bin, char * arquivo);



#endif /* HEX_BIN */
