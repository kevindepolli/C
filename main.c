#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"
#include "hashing.h"
#include "tratamento.h"

int main(){
    struct aluno al, al2;

    al.matricula = 1;
    strcpy(al.nome,"Guilherme");
    al.n1 = 10;

    Hash *ha;
    ha = criaHash(1427);

    if(insereHash_SemColisao(ha, al)) printf("Aluno Inserido com sucesso!\n");

    int busca;
    printf("Matricula para busca: ");
    scanf("%d", &busca);
    int resultado = buscaHash_SemColisao(ha, busca, &al2);

    if(resultado != 0){
        printf("Encontrou o aluno %s\n", al2.nome);
    }


    if(insereHash_EnderAberto(ha, al)) printf("Aluno Inserido com sucesso!\n");

    if(buscaHash_EnderAberto(ha, al.matricula, &al)) printf("Aluno encontrado com sucesso!\n");

    
    liberaHash(ha);
    return 0;
}