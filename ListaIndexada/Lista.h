#ifndef _Lista_H_
#define _Lista_H_

#define MAX_ELEMENTOS 30

typedef int tElemento;

typedef struct {
    int nElementos;
    tElemento elementos[MAX_ELEMENTOS];
} tLista;

extern void IniciaLista(tLista *lista);
extern int Comprimento(const tLista *lista);
extern tElemento ObtemElemento (const tLista *lista, int indice);
//extern int EstaCheia(const tLista *lista);
extern int EstaVazia(const tLista *lista);
extern int InsereElemento(tLista *lista, tElemento item, int indice);
extern tElemento RemoveElemento (tLista *lista, int indice);
extern int BuscaElemento (const tLista *lista, tElemento elemento);
extern int AcrescentaElemento (tLista *lista, tElemento elemento);
extern int AlteraElemento (tLista *lista, int indice, tElemento novoValor);


#endif // _Lista_H_
