#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


void IniciaLista(tLista *lista)
{
    lista->nElementos = 0;
}

int Comprimento(const tLista *lista)
{
    return lista->nElementos;
}

tElemento ObtemElemento (const tLista *lista, int indice)
{
    if(indice < 0 || indice >= lista->nElementos){
        printf("\nElemento Invalido\n");
        exit(1);
    }
    return lista->elementos[indice];
}

static int EstaCheia(const tLista *lista)
{
    return lista->nElementos >= MAX_ELEMENTOS;
}

int EstaVazia(const tLista *lista)
{
    return lista->nElementos == 0;
}

int InsereElemento(tLista *lista, tElemento item, int indice)
{
    int i;
   if (EstaCheia(lista)) {
      printf("\nA lista esta cheia\n");
      return 1;
   }

   if (indice < 0 || indice > lista->nElementos) {
      printf("\nPosicao de insercao inexistente\n");
      return 1;
   }

   for (i = lista->nElementos - 1; i >= indice; --i)
      lista->elementos[i + 1] = lista->elementos[i];

   lista->elementos[indice] = item;

   lista->nElementos++;

   return 0;
}

tElemento RemoveElemento (tLista *lista, int indice)
{
    tElemento itemRemovido;

    if (indice < 0 || indice >= lista->nElementos) {
       printf("\nPosicao de remocao inexistente\n");
       exit(1);
    }

    itemRemovido = lista->elementos[indice];

    int i;

    for(i = indice; i < lista->elementos[indice]; i++)
        lista->elementos[i] = lista->elementos[i + 1];

    --lista->nElementos;

    return itemRemovido;

}
/*
int BuscaElemento(const tLista *lista, tElemento elemento)
{

    int i;

    for(i = 0; i < lista->nElementos; i++) {

        if(lista->elementos[i] == elemento) {
            return i;
        }

    }
    return -1; // PARA ELEMENTO NÃO ENCONTRADO
}
*/
int BuscaBinaria (const tLista *lista, tElemento elemento)
{
    int inf ;
    int sup ;
    int meio;

    inf = 0;
    sup = lista->nElementos -1;

    while (inf <= sup){

        meio = (inf + sup)/2;

        if(lista->elementos[meio] == elemento) {
            return meio;
        }

        if(elemento < lista->elementos[meio]){
            sup = meio -1;
        }else{
            inf = meio +1;
        }
    }
    return -1;
}

int AcrescentaElemento(tLista *lista, tElemento elemento)
{
    if(EstaCheia(lista)) {
       return 1;
    }

    lista->elementos[lista->nElementos] = elemento;

    ++lista->nElementos;

    return 0;
}

int AlteraElemento(tLista *lista, int indice, tElemento novoValor)
{
    if(indice < 0 || indice >= lista->nElementos){
        printf("\nPosicao para remocao INEXISTENTE\n");
        return 1;
    }

    lista->elementos[indice] = novoValor;

    return 0;

}





