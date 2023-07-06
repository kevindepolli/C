#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main(){
    struct aluno al, al2;
    printf("informe a matricula: ");
    scanf("%d", &al.matricula);
    printf("Informe o nome: ");
    scanf("%s", &al.nome);
    printf("Informe a nota 1: ");
    scanf("%f", &al.n1);

    Hash *ha;
    ha = criaHash(1427);

    if(insereHash_SemColisao(ha, al)) printf("Aluno Inserido com sucesso!");

    int busca;
    printf("Matricula para busca: ");
    scanf("%d", &busca);
    int resultado = buscaHash_SemColisao(ha, busca, &al2);

    if(resultado != 0){
        printf("Encontrou o aluno %s\n", al2.nome);
    }


    if(insereHash_EnderAberto(ha, al)) printf("Aluno Inserido com sucesso!");

    if(buscaHash_EnderAberto(ha, al.matricula, &al)) printf("Aluno encontrado com sucesso!");

    
    liberaHash(ha);
    return 0;
}