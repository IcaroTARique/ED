#include <string.h>   /* Processamento de strings */
#include <stdlib.h>   /* Funções de alocação dinâmica e */
#include <stdio.h>    /* geração de números aleatórios  */
#include <time.h>     /* Função time() para alimentar o */
                      /* gerador de números aleatórios  */
#include "pilha.h"    /* Interface do tipo pilha */

void ExibeDoInicio(tPilha *p)
{
   int i;
   int tamanho = p->topo;

   printf("\n\t*** PILHA ***\n");

   for (i = 0; i <= tamanho; ++i) {
      printf("%d\t", p->itens[i]);
   }

   putchar('\n');
}

void ApresentaMenu(void)
{
   printf( "\n\t>>>>> Opcoes <<<<<\n"
           "\n\t(1) Acrescenta ITEM"
           "\n\t(2) Remove ITEM"
           "\n\t(3) Exibe a PILHA"
           "\n\t(4) Comprimento da PILHA"
           "\n\t(5) Elemento do TOPO"
           "\n\t(6) Encerra o programa"
           "\n\n\t>>> Escolha sua opcao: " );
}

int main(){

    tPilha p;
    int i, valor, op;


    CriaPilha(&p);

    srand((int) time(NULL));

      /* Cria a PILHA inicial */
   for (i = 0; i <= 9; ++i) {
      valor = (int) rand()%100 + 1;
      Empilha(&p, &valor);
   }

    while (1) {
        ApresentaMenu();
        scanf("%d", &op);
        //op = LeOpcao("12345678");

        if (op == 6) { /* Encerra o programa */
            printf("\nBye!\n");
            break; /* Saída do laço */
        }

        switch (op) {
            case 1:
                printf("\n>>> Digite o valor a ser EMPILHADO: ");
                scanf("%d", &valor);
                Empilha(&p, &valor);
                break;
            case 2:
                Desempilha(&p);
                printf("\n>>> Ultimo Item DESEMPILHADO ");
                break;
            case 3:
                ExibeDoInicio(&p);
                break;
            case 4:
                printf("\n>>> A quantidade de ITENS eh: %d", Comprimento(&p)+1);
                break;
            case 5:
                printf("\n>>> Elemento do topo : %d",ElementoTopo(&p));
                break;

            default: /* O programa não deve chegar até aqui */
                printf("\nEste programa contem um erro\n");
                return 1;
        }
    }
return 0;
}
