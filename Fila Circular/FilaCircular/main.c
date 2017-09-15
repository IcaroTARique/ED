#include <string.h>   /* Processamento de strings */
#include <stdlib.h>   /* Funções de alocação dinâmica e */
#include <stdio.h>    /* geração de números aleatórios  */
#include <time.h>     /* Função time() para alimentar o */
                      /* gerador de números aleatórios  */
#include "fila.h"    /* Interface do tipo pilha */

void ExibeDoInicio(tFila *f)
{
   int i;
   int tamanho = f->fundo;
   int inicio = f->frente + 1;

   printf("\n\t*** PILHA ***\n");
        printf("\n VALOR DE inicio = %d", inicio);
   for (i = inicio; i <= tamanho; ++i) {

      printf(" \t%d", f->itens[i]);
   }

   putchar('\n');
}

void ApresentaMenu(void)
{
   printf( "\n\t>>>>> Opcoes <<<<<\n"
           "\n\t(1) Acrescenta ITEM"
           "\n\t(2) Remove ITEM"
           "\n\t(3) Exibe a FILA"
           "\n\t(4) Comprimento da FILA"
           "\n\t(5) Elemento do FUNDO"
           "\n\t(6) Elemento da FRENTE"
           "\n\t(7) Encerra o programa"
           "\n\n\t>>> Escolha sua opcao: " );
}

int main(){
    tFila f;
    int i ,valor, op;

    CriaFila(&f);

    srand((int) time(NULL));

    for(i = 0; i <= 9; ++i){
        valor = (int) rand()%100+1;
        printf("\n VALOR : %d \n", valor);
        Acrescenta(&valor, &f);
    }
     while (1) {
        ApresentaMenu();
        scanf("%d", &op);
        //op = LeOpcao("12345678");

        if (op == 7) { /* Encerra o programa */
            printf("\nBye!\n");
            break; /* Saída do laço */
        }

        switch (op) {
            case 1:
                printf("\n>>> Digite o valor a ser COLOCADO NA FILA: ");
                scanf("%d", &valor);
                Acrescenta(&valor,&f);
                break;
            case 2:
                Retira (&f);
                printf("\n>>> Primeiro Item RETIRADO DA FILA ");
                break;
            case 3:
                ExibeDoInicio(&f);
                break;
            case 4:
                printf("\n>>> A quantidade de ITENS eh: %d", Comprimento(&f));
                break;
            case 5:
                printf("\n>>> Elemento da FRENTE : %d", ElementoFrente(&f));
                break;
            case 6:
                printf("\n>>> Elemento do FUNDO : %d",ElementoFundo(&f));
                break;

            default: /* O programa não deve chegar até aqui */
                printf("\nEste programa contem um erro\n");
                return 1;
        }
    }
return 0;
}

