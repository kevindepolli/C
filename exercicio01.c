#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"
#include "hashing.h"
#include "tratamento.h"

void main(){
    struct aluno al, al2;

    al.matricula = 1;
    strcpy(al.nome,"Guilherme");
    al.n1 = 10;

    Hash *ha;
    ha = criaHash(30);

    int pos, tam = 30;

    pos = chaveDivisao(al.matricula, tam);
    insereHash_SemColisao(ha, al, pos);

    liberaHash(ha);
}