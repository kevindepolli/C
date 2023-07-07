//Arquivo TabelaHash.c
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"
#include "hashing.h"
#include "tratamento.h"

Hash* criaHash(int TABLE_SIZE){
    Hash *ha;
    ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL) {
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*));
        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (i=0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash* ha){
    if (ha != NULL) {
        int i;
        for (i=0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

//Tratando string
int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str); //desloca 10 bits para a direita
    for (i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

//Inserção sem tratamento de colisão
int insereHash(Hash* ha, struct aluno al, int pos){
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE || pos >= ha->TABLE_SIZE)
        return 0;

    struct aluno *novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if (novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

//Busca sem tratamento de colisão
int buscaHash(Hash* ha, struct aluno *al, int pos){
    if (ha == NULL || pos >= ha->TABLE_SIZE)
        return 0;
    
    if (ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);

    return 1;
}

