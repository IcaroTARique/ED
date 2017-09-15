#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void CriaPilha (tPilha *p)
{
    p->topo = -1;
}

int PilhaVazia(const tPilha *p)
{
    return p->topo == -1;
}

static int PilhaCheia(const tPilha *p)
{
    return p->topo >= MAX_ELEMENTOS -1;
}

tElemento ElementoTopo (const tPilha *p)
{
    if(PilhaVazia(&p)){
        printf("\nA Pilha esta Vazia\n");
    }

    return p->itens[p->topo];
}

void Empilha (tPilha *p, const tElemento *item)
{
    if(!PilhaCheia(&p)){
        printf("\nA Pilha esta Cheia\n");
    }
    p->itens[++p->topo] = *item;

}

void Desempilha (tPilha *p)
{
    if(!PilhaVazia(&p)){
        printf("\nA Pilha esta Vazia\n");
    }
    return p->itens[--p->topo];
}

int Comprimento(const tPilha *p)
{
    return p->topo;
}


