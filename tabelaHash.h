#ifndef  TABELAHASH_H
#define  TABELAHASH_H

struct aluno {
int matricula;
char nome[30];
float n1, n2, n3;
};

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

typedef struct hash Hash;
Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash(Hash* ha, struct aluno al, int pos);
int buscaHash(Hash* ha, struct aluno *al, int pos);

#endif