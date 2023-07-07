#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"
#include "hashing.h"
#include "tratamento.h"

void main(){
    struct aluno al, resultado;

    al.matricula = 1;
    strcpy(al.nome,"Guilherme");
    al.n1 = 10;

    Hash *ha;
    ha = criaHash(30);

    int pos, buscado, tam = 30;

    pos = chaveDivisao(al.matricula, ha->TABLE_SIZE); //hashing
    insereHash(ha, al, pos);

    buscado = chaveDivisao(al.matricula, ha->TABLE_SIZE); //hashing
    if(buscaHash(ha, &resultado, buscado)) {
        printf("Nome:");
        puts(resultado.nome);
    }

    pos = chaveDivisao(al.matricula, ha->TABLE_SIZE); //hashing
    pos = sondagemLinear(pos, ha); //tratamento
    insereHash(ha, al, pos);

    pos = chaveDivisao(al.matricula, ha->TABLE_SIZE); //hashing
    pos = sondagemLinear(pos, ha); //tratamento
    if(buscaHash(ha, &resultado, buscado)) {
        printf("Nome:");
        puts(resultado.nome);
    }

    liberaHash(ha);
}