/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Fernando Iglesias Iglesias LOGIN 1: f.iglesias2
 * AUTHOR 2: Luís Rodríguez Represa LOGIN 2: luis.rodriguez.represa
 * GROUP: 2.4
 * DATE: 29 / 03 / 2022
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "bid_stack.h"
#include "types.h"
#define LNULL NULL
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
} tItemL;

typedef struct tNode* tPosL;
typedef struct tNode {   // Almacena los datos
    tItemL data;  // Almacena la información
    tPosL next;     // Relaciona al siguiente elemento
}tNode;
typedef tPosL tList;

bool insertItem(tItemL d, tList *L);
// Objetivo:
// insertar un elemento en la lista
// Entradas:
// item
// la lista (como se modificará se pasa *L)
// Salidas:
// devuelve true en caso de que se haya podido insertar el elemento o false en caso contrario.
// Precondiciones:
// que haya espacio para insertar
// la posición donde se inserte debe ser válida
// Postcondiciones:
// se inserta de manera ordenada por el productId alfabéticamente
// si la posición fuese LNULL, se inserta al final de la lista
// las posiciones de los elementos posteriores al elemento insertado pueden haberse visto afectadas
void updateItem(tItemL d, tPosL p, tList *L);
// Objetivo:
// modificar el contenido del elemento de una posición indicada
// Entradas:
// item
// una posición
// la lista (como se modificará se pasa *L)
// Salidas:
// el item actualizado
// Precondiciones:
// la posición debe ser válida
// Postcondiciones:
// el item se ha actualizado y el orden de los elementos de la lista no se ve modificado
void deleteAtPosition(tPosL, tList *L);
// Objetivo:
// elimina el elemento de la posición indicada
// Entradas:
// posición
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista después de las modificaciones
// Precondiciones:
// la posición indicada debe ser válida y el producto en esa posición debe tener una pila de pujas vacía
// Postcondiciones:
// las posiciones de los elementos posteriores al elemento eleminado pueden haberse visto afectadas
tPosL findItem(tProductId d, tList L);
// Objetivo:
// devuelve la posición del primer elemento de la lista
// Entradas:
// productId
// la lista
// Salidas:
// la posición buscada si esta está en la lista o bien si no estuviese se devolvería LNULL
// Precondiciones:
// la lista no debe estar vacía
// Postcondiciones:
// no hay
void createEmptyList (tList* L);
// Objetivo:
// crea una lista vacía
// Entradas:
// tList* L
// Salidas:
// la lista vacía
// Precondiciones:
// no hay
// Postcondiciones:
// la lista está vacía (inicializada y sin elementos)
tItemL getItem(tPosL p, tList L);
// Objetivo:
// devuelve el contenido de la lista de la posición indicada
// Entradas:
// la posición
// la lista
// Salidas:
// el contenido del elemento que ocupa la posición indicada
// Precondiciones:
// la posición debe ser válida
// Postcondiciones:
// No hay
tPosL first(tList L);
// Objetivo:
// Devolver la posición del primer elemento de la lista
// Entradas:
// la lista
// Salidas:
// la primera posición de la lista
// Precondiciones:
// la lista no está vacía
// Postcondiciones:
// No hay
tPosL last(tList L);
// Objetivo:
// devolver la posición del último elemento de la lista
// Entradas:
// la lista
// Salidas:
// la última posición de la lista
// Precondiciones:
// la lista no está vacía
// Postcondiciones:
// no hay
tPosL previous(tPosL, tList L);
// Objetivo:
// devolver la posición de la lista del elemento anterior al de la posición indicada
// (si no tuviese anterior devuelve NULL)
// Entradas:
// la posición
// la lista
// Salidas:
// la posición anterior a la posición recibida
// Precondiciones:
// la posición recibida es una posición válida en la lista
// Postcondiciones:
// no hay
tPosL next(tPosL, tList L);
// Objetivo:
// devolver la posición siguiente de la posición indicada
// (si no tuviese siguiente devuelve NULL)
// Entradas:
// la posición
// la lista
// Salidas:
// la posición siguiente a la posición recibida
// Precondiciones:
// la posición recibida es una posición válida
// Postcondiciones:
// no hay
bool isEmptyList(tList L);
// Objetivo:
// comprobar si la lista está vacía
// Entradas:
// la lista
// Salidas:
// true en caso de que esté vacía, false en caso contrario
// Precondiciones:
// no hay
// Postcondiciones:
// no hay
#endif
