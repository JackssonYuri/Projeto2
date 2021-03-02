#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                         //global.


//Função para codificar de binário para a base 64
char *Codificar(const char *base, size_t menor)
{

    char *saida; //ponteiro para a saída
    size_t i, j, k;
     //elen
    //contadores para o ciclo
if (base == NULL || menor % 4)

    return NULL;

    for (i = 0, j = 0; i < menor; i += 3, j += 4) {
     k = base[i];
     k = i + 1 < menor ? k << 8 | base[ i + 1 ] : k << 8;
     k = i + 2 < menor ? k << 8 | base[ i + 2 ] : k << 8;
 }
 //para o uso dos 6 bytes na saída
 saida[j] = base64[( k >> 18 ) & 0x3F];
 saida[j + 1] = base64[( k >> 12 ) & 0x3F];


/*para o preenchimento: caso o último bloco tenha menos de 3 bytes adiciono um preenchimento, e caso os outros blocos tenham menos de 3 byts recebem 1 ou 2 preenchimentos
o 0x3F é usado pq todos os bytes são divididos em uma série de 6 bits*/
        if ( i  == 1 ) {
            saida[ j + 2] = base64[ ( k >> 6 ) & 0x3F];
        } else {
            saida[ j + 2 ] = ' = ';
            putc( ' = ', stdout);
        }

        if ( i == 2 ) {
            saida [ j + 3] =  base64[ k & 0x3F];
        } else {
            saida[ j + 3 ] = ' = ';
            putc( ' = ', stdout);
        }
        return;
}

unsigned char*Decodificar( const char *base, unsigned char *saida, size_t menor) {
    size_t recebe;
    size_t i;
    size_t j;

    if (base == NULL || saida == NULL)

        return 0;


    recebe = strlen(base);
    if(menor % 4 != 0)
        return 0;

    for( i = 0, j = 0; i < recebe; i += 4, j += 3) {

    int nbytes[] = { 3, 2, 1, 2 };
    unsigned char out[3];
    saida[0] = base[0] << 2 | base[1] >> 4;
    saida[1] = base[1] << 4 | base[2] >> 2;
    saida[2] = base[2] << 6 | base[3] >> 0;
    fwrite(saida, nbytes, 1, stdout);
}

 return Decodificar;
}

int main(void) {

    char *ponteiro;
    ponteiro = &base64; //crio um ponteiro pra receber o endereço da base64

    long input_size = strlen(ponteiro);
    char *Codificar(const char *base, size_t menor);
    printf("A Codificacao e : %s \n", Codificar);

    long decode_size = strlen(Decodificar);
    unsigned char*Decodificar( const char *base, unsigned char *saida, size_t menor);
    printf("A decodificacao e: %s \n", Decodificar);

}











