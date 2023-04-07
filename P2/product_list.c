/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Iglesias Iglesias LOGIN 1: f.iglesias2
 * AUTHOR 2: Luís Rodríguez Represa LOGIN 2: luis.rodriguez.represa
 * GROUP: 2.4
 * DATE: 29 / 03 / 2022
 */

#include "product_list.h"

void createEmptyList (tList* L) {   // Recibimos *l
    *L = LNULL;
}
bool isEmptyList(tList L){     // Recibimos la lista
    return L == LNULL;      // En caso de que sea LNULL (la lista está vacía) devuelve true, en caso contrario false
}
tPosL first(tList L){   // Recibimos la lista
    return L;
}
tPosL last(tList L){    // Recibimos la lista
    tPosL p;
    for(p=L; p->next != LNULL; p=p->next); // Recorremos la lista hasta el final
    return p;       // Como el bucle acaba al final de la lista (en la última posición, antes de LNULL) se devuelve p
}
tPosL next(tPosL p, tList L){       // Recibimos una posición y lista
    return p->next;
}
tPosL previous(tPosL p, tList L) {       // Recibimos posición y lista
    tPosL q;
    if (p == L)        // Comprobamos si nos encontramos en la primera posición
        return LNULL;   // El anterior de la primera posición es LNULL
    else
    {
        for (q = L; q->next != p; q = q->next);      // Recorremos la lista hasta que el siguiente de q sea igual p
        return q;   // Devolvemos la posición anterior a p
    }
}
bool createNode (tPosL *p) {
    *p = malloc(sizeof(**p));
    return *p != LNULL;
}
tPosL findPosition (tList L, tItemL d) { // Función auxiliar para insertItem
    tPosL p;
    p=L;
    while ((p->next!=LNULL)&&(strcmp(p->next->data.productId,d.productId)<0))
        p=p->next;
    return p;
}
bool insertItem(tItemL d, tList *L){        // Recibe un item y la lista
    tPosL q,p;
    if(!createNode(&q))             // Comprobamos si hay espacio para insertar
        return false;               // En caso de que no se pueda, se devuelve false
    else{
        q->data = d;
        q->next = LNULL;
        if(*L == LNULL){           // Comprobamos si la lista está vacía
            *L = q;                // Insertamos en lista vacía
        }
        else if (strcmp(d.productId,(*L)->data.productId)<0) {   // Insertar al principio
            q->next=*L;
            *L=q;
        }
        else {            // Buscamos la pos.
            p= findPosition(*L,d);
            q->next=p->next;        // Asigna LNULL si insertamos al final
            p->next=q;
            }
        return true;
        }
    }
void deleteAtPosition(tPosL p, tList * L){ // Recibe una posición y la lista
    tPosL q;
    if(p==*L) {    // En caso de que p sea la primera pos:
        *L=(*L)->next;        // Asignamos a L su siguiente
    }
    else if(p->next==LNULL) {           // En caso de que el siguiente de p sea LNULL, es decir, se encuentra al final de la lista:
        for(q=*L; q->next!=p; q=q->next);         // Recorremos hasta que next de q sea LNULL
        q->next=LNULL;
    }
    else{      // Si se encontrase por el medio de la lista, es decir, ni en la primera pos. ni en la última:
        q=p->next;
        p->data=q->data;
        p->next=q->next;
        p=q;
    }
    free(p);
}
tItemL getItem(tPosL p, tList L) {   // Recibe una posición y lista
    return (p->data);
}
void updateItem(tItemL d, tPosL p, tList*L){   // Recibe un item, una posición y la lista
    p->data = d;
}
tPosL  findItem(tProductId d, tList L){            // Recibe el identificador de producto y la lista
    tPosL p;
    for (p=first(L);(p!=LNULL)&&(strcmp(p->data.productId,d)<0);p=p->next); // Recorremos la lista hasta que p=LNULL
    // o bien hasta que p->data.productId sea mayor alfabéticamente que d
    if ((p!=LNULL) && (strcmp(p->data.productId,d)==0))  // Comprobamos que hizo parar el bucle for
        return p;
    else
        return LNULL;
}