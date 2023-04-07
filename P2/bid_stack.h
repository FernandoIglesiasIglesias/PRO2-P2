/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Iglesias Iglesias LOGIN 1: f.iglesias2
 * AUTHOR 2: Luís Rodríguez Represa LOGIN 2: luis.rodriguez.represa
 * GROUP: 2.4
 * DATE: 29 / 03 / 2022
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include "stdbool.h"
#define SNULL -1
#define SMAX 25

typedef int tPosS;
typedef struct tItemS {
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;
typedef struct stack {
    tItemS data[SMAX];
    tPosS top;
}tStack;

void createEmptyStack (tStack *stack);
// Objetivo:
// Crea una pila vacía
// Entrada:
// *stack
// Salidas:
// la pila vacía
// Precondiciones:
// no hay
// Postcondiciones:
// la pila no tiene elementos
bool push (tItemS d, tStack *stack);
// Objetivo:
// inserta un elemento en la cima de la pila y devuelve true en caso favorable o false en caso contrario
// Entrada:
// item
// *stack
// Salidas:
// la pila con su nuevo elemento
// Precondiciones:
// la pila no puede estar llena
// Postcondiciones:
// la pila varía, tiene un elemento nuevo
void pop (tStack *stack);
// Objetivo:
// elimina el elemento de la cima de la pila
// Entrada:
// *stack
// Salidas:
// la pila
// Precondiciones:
// la pila no está vacía
// Postcondiciones:
// la pila tiene un elemento menos, se ha eliminado el de la cima
tItemS peek (tStack stack);
// Objetivo:
// recupera el elemento de la cima de la pila sin llegar a eliminarlo
// Entrada:
// stack
// Salidas:
// item (el elemento de la cima de la pila)
// Precondiciones:
// la pila no está vacía
// Postcondiciones:
// no hay
bool isEmptyStack (tStack stack);
// Objetivo:
// devuelve true en caso de que la pila esté vacía, en caso contrario devuelve false
// Entrada:
// stack
// Salidas:
// true si la lista está vacía, false en caso contrario
// Precondiciones:
// la pila no está vacía
// Postcondiciones:
// no hay
#endif
