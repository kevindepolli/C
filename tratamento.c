#include "tratamento.h"
#include "hashing.h"


//Sondagem Linear
int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

//Sondagem Quadrática
int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {
    pos = pos + 2 * i + 5 * i * i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

//Duplo Hash
int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE -1) + 1;
    return ((H1 + i * H2) & 0x7FFFFFFF) % TABLE_SIZE;
}
