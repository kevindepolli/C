//Arquivo TabelaHash.c
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

//definição do tipo hash
struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

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

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE) {
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
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
int insereHash_SemColisao(Hash* ha, struct aluno al){
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    //int chave = valorString(al.nome);
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
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
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno *al){
    if (ha == NULL)
        return 0;

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    
    if (ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);

    return 1;
}

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

//Inserção com tratamento de colisão
int insereHash_EnderAberto(Hash* ha, struct aluno al){
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int i, pos, newPos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);

    for (i=0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL) {
            struct aluno *novo;
            novo = (struct aluno*)malloc(sizeof(struct aluno));
            if (novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

//Busca com tratamento de colisão
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno *al){
    if (ha == NULL)
        return 0;
    int i, pos, newPos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for (i=0; i < ha->TABLE_SIZE; i++) {
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL)
            return 0;
        if (ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}

