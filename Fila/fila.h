#ifndef _fila_H_
#define _fila_H_

#define MAX_ELEMENTOS 35

typedef int tElemento;

typedef struct {
    int frente, fundo;
    tElemento itens[MAX_ELEMENTOS];
}tFila;

//extern int FilaCheia (const tFila *f);
extern void CriaFila(tFila *f);
extern int FilaVazia (const tFila *f);
extern tElemento ElementoFrente(const tFila *f);
extern tElemento ElementoFundo(const tFila *f);
extern void Acrescenta(const tElemento *item, tFila *f);
extern void Retira (tFila *f);
extern int Comprimento(const tFila *f);

#endif // _fila_H_
