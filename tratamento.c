#include <stdlib.h>
#include "tratamento.h"
#include "hashing.h"
#include "tabelaHash.h"


//Sondagem Linear
int sondagemLinear(int pos, Hash *ha) {
    for(int i=0;i<ha->TABLE_SIZE;i++){
        pos = ((pos + i) & 0x7FFFFFFF) % ha->TABLE_SIZE;
        if(ha->itens[pos] == NULL) return pos;
    }
}

//Sondagem Quadrática
int sondagemQuadratica(int pos, Hash *ha) {
    for(int i=0;i<ha->TABLE_SIZE;i++){
        pos = pos + 2 * i + 5 * i * i;
        pos = (pos & 0x7FFFFFFF) % ha->TABLE_SIZE;
        if(ha->itens[pos] == NULL) return pos;
    }
}

//Duplo Hash************
int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE -1) + 1;
    return ((H1 + i * H2) & 0x7FFFFFFF) % TABLE_SIZE;
}
