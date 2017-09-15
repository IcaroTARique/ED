/****
 *
 * Título: Lista Indexada sem Ordenação
 *
 * Autor: Ulysses de Oliveira
 *
 * Data de Criação: 16/04/2015
 * Última modificação: 16/04/2015
 *
 * Descrição: Gerencia uma lista de compras permitindo
 *            desfazer e refazer operações
 *
 * Entrada: Itens (strings) e opções escolhidas pelo usuário
 *
 * Saída: A lista criada pelo usuário
 *
 ****/

/*********************** Includes *************************/

   /* Funções de Entrada/Saída */
#include <string.h>   /* Processamento de strings */
#include <stdlib.h>   /* Funções de alocação dinâmica e */
                      /* geração de números aleatórios  */
#include <time.h>     /* Função time() para alimentar o */
                      /* gerador de números aleatórios  */
#include "Lista.h"    /* Interface do tipo lista  */


/***************** Definições de Funções ******************/

/****
 *
 * ExibeDoInicio(): Exibe na tela do primeiro ao último
 *                  elemento de uma lista indexada
 *
 * Parâmetros:
 *     *lista (entrada) - a lista
 *
 * Retorno: Nada
 *
 ****/
void ExibeDoInicio(tLista *lista)
{
   int i;
   int tamanho = Comprimento(lista);

   printf("\n\t*** Lista ***\n");

   for (i = 0; i < tamanho; ++i) {
      printf("%d\t", ObtemElemento(lista, i));
   }

   putchar('\n');
}

/****
 *
 * ExibeDoFinal(): Exibe na tela do último ao primeiro
 *                  elemento de uma lista indexada
 *
 * Parâmetros:
 *     *lista (entrada) - a lista
 *
 * Retorno: Nada
 *
 ****/
void ExibeDoFinal(tLista *lista)
{
   int tamanho = Comprimento(lista);
   int i;

      printf("\n\t*** Lista Invertida ***\n");

for ( i = tamanho - 1; i >= 0; --i) {
      printf("%d\t", ObtemElemento(lista, i));
   }

   putchar('\n');
}

/****
 *
 * ApresentaMenu(): Apresenta o menu do programa
 *
 * Parâmetros: Não há
 *
 * Retorno: Nada
 *
 ****/
void ApresentaMenu(void)
{
   printf( "\n\t>>>>> Opcoes <<<<<\n"
           "\n\t(1) Acrescenta um elemento"
           "\n\t(2) Remove um elemento"
           "\n\t(3) Altera dados"
           "\n\t(4) Posicao de um elemento"
           "\n\t(5) Exibe a lista do inicio"
           "\n\t(6) Exibe a lista do final"
           "\n\t(7) Comprimento da lista"
           "\n\t(8) Insere um elemento na posicao X"
           "\n\t(9) Encerra o programa"
           "\n\n\t>>> Escolha sua opcao: " );
}
/*
void Quick(tLista *lista, int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;
    printf("\n %d ",lista->elementos[i]);
    printf("\n %d ",lista->elementos[j]);
   meio = (int) ((i + j) / 2);
   pivo = lista->elementos[meio];

    printf("\n\n\n\ ENTREI NO QUICK \n\n\n");

   do{
      while (lista->elementos[i] < pivo) i = i + 1;
      while (lista->elementos[j] > pivo) j = j - 1;

      if(i <= j){
         aux = lista->elementos[i];
         lista->elementos[i] = lista->elementos[j];
         lista->elementos[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) Quick(&lista, inicio, j);
   if(i < fim) Quick(&lista, i, fim);

}
*/
void Bubble (tLista *lista, int tamanho)
{
   int i, j, temporario;
   for( i = 0; i < ( tamanho -1 );  i++ )
   {
      for( j=0; j <( tamanho -( i +1 ) ); j++ )
      {
         if( lista->elementos[j] > lista->elementos[j+1] )
         {
            temporario = lista->elementos[j];
            lista->elementos[j] = lista->elementos[j+1];
            lista->elementos[j+1] = temporario;
         }
      }
   }
}

/****
 *
 * main(): Testa as operações sobre listas
 *
 * Parâmetros: Nenhum
 *
 * Retorno: Zero
 *
 ****/


int main (void)
{
   tLista lista;
   int    i, valor, indice, op;

   IniciaLista(&lista);

      /* Será criada uma lista inicial com 10 elementos. */
      /* Os conteúdos destes elementos serão números     */
      /* inteiros entre 0 e 100 gerados aleatoriamente   */

      /* Alimenta o gerador de números aleatórios */


      /* Cria a lista inicial */

   for (i = 1; i <= 10; ++i) {
      valor = (int) rand()%100 + 1;
      AcrescentaElemento(&lista, valor);
   }

     ExibeDoInicio(&lista);
     Bubble(&lista, 10);
   // Quick(&lista, 0, 9);

   while (1) {
      ApresentaMenu();

      scanf("%d", &op);
      //op = LeOpcao("12345678");

      if (op == 9) { /* Encerra o programa */
         printf("\nBye!\n");
         break; /* Saída do laço */
      }

      switch (op) {
         case 1: /* Acrescenta um elemento */
            printf("\n>>> Digite o valor a ser acrescentado: ");
            scanf("%d", &valor);

            if (AcrescentaElemento(&lista, valor)) {
               printf("\n>>> Impossivel acrescentar\n");
            } else {
                  /* Acréscimo foi bem sucedido. Faz o ponteiro */
                  /* original apontar para turma redimensionada */
               printf("\n>>> Acrescimo bem sucedido\n");
            }
            break;

         case 2: /* Remove um aluno */
            printf("\n>>> Digite o valor a ser removido: ");
            scanf("%d", &valor);

            indice = BuscaBinaria(&lista, valor);

            if (indice >= 0) {
               (void) RemoveElemento(&lista, indice);
               printf("\n>>> Remocao bem sucedida\n");
            } else {
               printf("\n>>> Valor nao encontrado\n");
            }

            break;

         case 3: /* Altera valor de um elemento */
            printf("\n>>> Digite o valor a ser alterado: ");
            scanf("%d", &valor);

            indice = BuscaBinaria(&lista, valor);

            if (indice >= 0) {
               printf("\n>>> Digite o valor que substituira' %d: ", valor);
               scanf("%d", &valor);

               (void) AlteraElemento(&lista, indice, valor);
               printf("\n>>> alteracao bem sucedida\n");
            } else {
               printf("\n>>> Valor nao encontrado\n");
            }

            break;

         case 4: /* Posição de um elemento */
            printf("\n>>> Digite o valor do elemento: ");
            scanf("%d", &valor);

            indice = BuscaBinaria(&lista, valor);

            if (indice >= 0) {
               printf("\n>>> O elemento %d: se encontra na "
                      "posicao %d", valor, indice);
            } else {
               printf("\n>>> Valor nao encontrado\n");
            }

            break;

         case 5: /* Apresenta a lista a partir do início */
            ExibeDoInicio(&lista);
            break;

         case 6: /* Apresenta a lista a partir do final */
            ExibeDoFinal(&lista);
            break;

         case 7: /* Apresenta o comprimento da lista */
            printf( "\n>>>Comprimento da lista: %d\n",
                    Comprimento(&lista) );
            break;

         case 8:
            printf("\n>>> Escolha qual posicao colocar o numero (DE 1 a N):");
            scanf("%d", &indice);

            if (indice >= 0) {
                printf("\n>>> Digite o valor que deseja: ", valor);
                scanf("%d", &valor);
            }
            indice -= 1;
            InsereElemento(&lista, valor, indice);
            printf( "\n>>>Elemento inserido na posicao %d\n", indice );
            break;

         default: /* O programa não deve chegar até aqui */
            printf("\nEste programa contem um erro\n");
            return 1;
      }
   }

   return 0;
}

/******************* Exemplo de Execução ******************

Lista a partir do inicio:
13      10      1       16      42      7       83      41      11      74

Lista a partir do final:
74      11      41      83      7       42      16      1       10      13
Comprimento da lista: 10


Elemento de indice 5: 7

Elemento de indice 5 apos incremento: 8

Lista a partir do inicio:
13      10      1       16      42      8       83      41      11      74

Um elemento de valor 99 sera' inserido na posicao 5

Comprimento da lista: 11

Lista a partir do inicio:
13      10      1       16      42      99      8       83      41      11      74

Elemento removido na posicao 5: 99

Comprimento da lista: 10

Lista a partir do inicio:
13      10      1       16      42      8       83      41      11      74

**********************************************************/

