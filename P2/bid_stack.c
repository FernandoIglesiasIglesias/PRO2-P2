/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Iglesias Iglesias LOGIN 1: f.iglesias2
 * AUTHOR 2: Luís Rodríguez Represa LOGIN 2: luis.rodriguez.represa
 * GROUP: 2.4
 * DATE: 29 / 03 / 2022
 */

#include "bid_stack.h"

void createEmptyStack (tStack *stack) {
    stack->top=SNULL;
}
bool isEmptyStack (tStack stack) {
    return (stack.top==SNULL);
}
tItemS peek (tStack stack) {
    return stack.data[stack.top];
}
void pop (tStack *stack) {
    stack->top--; // Se sobreescriben los datos
}
bool push (tItemS d, tStack *stack) {
    if (stack->top==SMAX-1) // Comprobamos si la pila está llena
        return false;
    else {
        stack->top++;
        stack->data[stack->top]=d;
        return true;
    }
}
