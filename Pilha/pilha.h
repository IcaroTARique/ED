#ifndef _lista_H_
#define _lista_H_

#define MAX_ELEMENTOS 35

typedef int tElemento;

typedef struct {
    int topo;
    tElemento itens[MAX_ELEMENTOS];
}tPilha;

extern void CriaPilha(tPilha *p);
extern int PilhaVazia(const tPilha *p);
//extern int PilhaCheia(const tPilha *p);
extern tElemento ElementoTopo (const tPilha *p);
extern void Empilha (tPilha *p,const tElemento *item);
extern void Desempilha (tPilha *p);
extern int Comprimento(const tPilha *p);

#endif // _lista_H_
