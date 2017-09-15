#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void CriaFila (tFila *f)
{
    f->frente = f->fundo = -1;
}

int FilaVazia (const tFila *f)
{
    return f->fundo == f->frente;
}

static int FilaCheia (tFila *f)
{
    int deslocamento, i;
    if(f->fundo < MAX_ELEMENTOS){
        return 0;
    }

    if(f->frente == -1 && f->fundo == MAX_ELEMENTOS -1){
        return 1;
    }

    deslocamento = MAX_ELEMENTOS - (f->fundo - f->frente);

    printf("\n DESLOCAMENTO -> %d", deslocamento);

    for (i = f->frente + 1;  i <= f->fundo; ++i){

        f->itens[i-deslocamento] = f->itens[i];
    }

        f->frente -= deslocamento;

        f->fundo -= deslocamento;

    return 0;
}

tElemento ElementoFrente(const tFila *f){

    if(!FilaVazia(&f)) {
        printf("\n Fila VAZIA !");
    }

    return f->itens[f->frente + 1]; // f->fila[++f->frente]; --> É A MESMA COISA ??
}

tElemento ElementoFundo(const tFila *f)
{
if(!FilaVazia(&f)) {
        printf("\n Fila VAZIA !");
    }
    return f->itens[f->fundo];
}

void Acrescenta(const tElemento *item, tFila *f)
{
    //if(f->fundo == MAX_ELEMENTOS)
    //    f->fundo = 0;
    //else
    //    ++f->fundo;
    f->fundo = (f->fundo +  1) % (MAX_ELEMENTOS + 1)
    return f->itens[f->fundo] = *item;
}

void Retira (tFila *f)
{
    ++f->frente;
    return f->itens[f->frente];
}

int Comprimento(const tFila *f)
{
    return f->fundo - f->frente;
}

