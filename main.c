#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main(){
    int busca, mat, x;

    struct aluno al, al2;
    printf("informe a matricula: ");
    scanf("%d", &al.matricula);
    printf("Informe o nome: ");
    scanf("%s", &al.nome);
    printf("Informe a nota 1: ");
    scanf("%f", &al.n1);

    Hash *ha;
    ha = criaHash(1427);

    int x = insereHash_SemColisao(ha, al);

    printf("Matricula para busca: ");
    scanf("%d", &busca);
    int resultado = buscaHash_SemColisao(ha, busca, &al2);

    if(resultado != 0){
        printf("Encontrou o aluno %s\n", al2.nome);
    }


    x = insereHash_EnderAberto(ha, al);

    x = buscaHash_EnderAberto(ha, mat, &al);
    
    liberaHash(ha);
    return 0;
}