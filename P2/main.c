/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Iglesias Iglesias LOGIN 1: f.iglesias2
 * AUTHOR 2: Luís Rodríguez Represa LOGIN 2: luis.rodriguez.represa
 * GROUP: 2.4
 * DATE: 19 / 04 / 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "bid_stack.h"
#include "product_list.h"
#define MAX_BUFFER 255

void New (char *param1, char *param2, char *param3, char *param4, tList *L);
// Objetivo:
// añade un nuevo producto con su identificador, el vendedor, su categoría, su precio y el número de pujas efectuadas sobre el producto, al final de la lista
// Entradas:
// productId (tipo char)
// userId (tipo char)
// productCategory (tipo enum, que se pasará a string mediante una función auxiliar)
// productPrice (tipo float)
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista con el producto nuevo
// Precondiciones:
// el precio recibido debe ser válido
// el nuevo elemento a introducir en la lista no puede existir en la lista previamente
// Postcondiciones:
// el contador de pujas se inicializa a 0
// el producto se incorpora al final de la lista
// se le asocia una nueva pila de pujas vacía
void Bid (char *param1, char *param2, char *param3, tList *L);
// Objetivo:
// puja por un producto, modificando su precio al ofertado por el pujador y el número de pujas efectuadas sobre ese producto,
// se imprimirá dicha información
// Entradas:
// productId (tipo char)
// userId (tipo char)
// productPrice (tipo float)
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista
// su pila de pujas asociada, que tendrá las pujas efectuadas sobre el producto
// Precondiciones:
// el precio recibido debe ser un precio válido
// es necesario que exista dicho producto (mismo productId)
// el pujador y el vendedor deben ser distintos
// el precio de la puja debe ser mayor al precio original
// la pila no puede estar llena
// Postcondiciones:
// el contador de pujas variará, pues se ha efectuado una puja, por lo tanto su valor incrementará en uno
// la pila de pujas asociada se verá modificada, pues se le ha añadido una puja
void Stats (tList L);
// Objetivo:
// la función imprime el identificador del producto, su vendedor, su categoría, su precio y el número de pujas efectuadas sobre el producto
// también se mostrará el producto sobre el que se efectuó un mayor incremento de precio respecto a su precio original, mostrando sus datos correspondientes más su incremento en porcentaje
// a mayores aporta por categorías (book or painting) el número de productos, la suma de los precios y el precio medio por producto
// Entradas:
// la lista (no se modificará)
// Salidas:
// producto, su vendedor, su categoría, su precio y el número de pujas efectuadas sobre el producto
// el producto sobre el que se efectuó un mayor incremento de precio respecto a su precio original, mostrando sus datos correspondientes más su incremento en porcentaje
// aporta por categorías (book or painting) el número de productos, la suma de los precios y el precio medio por producto
// Precondiciones:
// el nuevo elemento a introducir en la lista no puede existir en la lista previamente
// si no hay pujas no se imprimirá la estadística de top bidder
// Postcondiciones:
// no hay
void Delete (char *param1, tList *L);
// Objetivo:
// añade un nuevo producto con su identificador, el vendedor, su categoría, su precio y el número de pujas efectuadas sobre el producto, al final de la lista
// Entradas:
// productId (tipo char)
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista
// Su pila asociada
// Precondiciones:
// el productId buscado tiene que estar en la lista
// Postcondiciones:
// la posición del producto se eliminará
// su pila de pujas está vacía
void Award (char *param1, tList *L);
// Objetivo:
// se buscará el producto y se dará por vendido
// Entradas:
// productId (tipo char)
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista sin el producto vendido (se ha eliminado)
// Precondiciones:
// debe existir el producto en la lista
// su pila de pujas no puede estar vacía
// Postcondiciones:
// la lista se ha visto afectada, pues se ha borrado de la lista el producto
// la pila de pujas se ha vaciado
void Withdraw (char *param1, char *param2, tList *L);
// Objetivo:
// busca el producto y elimina su mayor puja
// Entradas:
// productId (tipo char)
// userId (tipo char)
// la lista (como se modificará se pasa *L)
// Salidas:
// la lista
// la pila de pujas sin la puja eliminada
// Precondiciones:
// debe existir el producto en la lista
// su pila de pujas no puede estar vacía
// el userId recibido debe coincidir con el autor de la puja
// Postcondiciones:
// el contador de pujas disminuirá, pues se ha eliminado una puja (bidCounter -1)
// se elimina la puja de la cima de la pila
void Remove (tList *L);
// Objetivo:
// elimina de la lista aquellos productos que no tengan pujas
// Entradas:
// la lista (como se modificará se pasa *L)
// Salidas:
// La lista con el producto nuevo
// Precondiciones:
// La lista no puede estar vacía
// Postcondiciones:
// Las posiciones posteriores del producto borrado pueden verse afectadas
char *book_or_painting (tProductCategory category); // (Función auxiliar)
// Objetivo:
// convierte productCategory a un string, devolverá book o bien painting
// Entradas:
// productCategory (tipo enum)
// Salidas:
// string: "book" o "painting"
// Precondiciones:
// category debe ser válido ("book" o "painting")
// Postcondiciones
// no hay

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s\n",commandNumber,command,param1,param2,param3,param4);
            New(param1,param2,param3,param4,L);
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c\n",commandNumber,command);
            Stats(*L);
            break;
        case 'B':
            printf("********************\n");
            printf("%s %c: product %s bidder %s price %s\n",commandNumber,command,param1,param2,param3);
            Bid(param1,param2,param3,L);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: product %s\n",commandNumber,command,param1);
            Delete(param1,L);
            break;
        case 'A':
            printf("********************\n");
            printf("%s %c: product %s\n",commandNumber,command,param1);
            Award(param1,L);
            break;
        case 'W':
            printf("********************\n");
            printf("%s %c: product %s bidder %s\n",commandNumber,command,param1,param2);
            Withdraw(param1,param2,L);
            break;
        case 'R':
            printf("********************\n");
            printf("%s %c\n",commandNumber,command);
            Remove(L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename,tList *L) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4,L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tList L;
    createEmptyList(&L);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name,&L);

    return 0;
}

void New (char *param1, char *param2, char *param3, char *param4, tList *L) {
    tItemL item;
    tPosL pos;
    createEmptyStack(&item.bidStack); // Inicializamos una nueva pila de pujas vacías
    strcpy(item.productId,param1);
    strcpy(item.seller,param2);
    if (strcmp(param3, "book") == 0) {     // Comprobamos si el producto es book o painting
        item.productCategory = book;
    }
    else {
        item.productCategory = painting;
    }
    item.productPrice = atof(param4); // Utilizamos atof para pasar productPrice de string a float
    item.bidCounter=0;
    pos = findItem(item.productId,*L);
    if(pos==LNULL) {  // Comprobamos si el elemento está en la lista
        if (insertItem(item,L)==true) {   // En caso de que pos=LNULL, insertItem inserta automáticamente después de la última posición
            printf("* New: product %s seller %s category %s price %s\n",param1,param2,param3,param4); // Como devuelve true es que se ha podido insertar
        }
    }
    else    // En caso contrario imprimimos el error
        printf("+ Error: New not possible\n");
}
char *book_or_painting (tProductCategory category) {  // Hacemos una función que nos permita pasar productCategory a un string:
    if (category == book)
        return "book";
    else
        return "painting";
}
void Bid (char *param1, char *param2, char *param3, tList *L) {
    tPosL pos;
    tItemS item_S;
    tItemL item, item_temp;  // Declaramos un item auxiliar para poder comprobar las condiciones
    pos = findItem(param1, *L);  // Buscamos la posición del productId del producto por el que queremos pujar
    if (pos != LNULL) {  // La posición debe ser distinta de LNULL, es decir, que el producto por el que se quiere pujar esté en la lista
        item_temp = getItem(pos, *L);
        strcpy(item.productId, param1);
        strcpy(item.seller, param2);
        item.productPrice = atof(param3); // Utilizamos atof para pasar productPrice de string a float
        item_temp.bidCounter = 0;  // Inicializamos a 0 el contador de pujas
        if (strcmp(param2,item_temp.seller)!=0) {  // El vendedor y el pujador deben ser distintos
            if (item.productPrice > item_temp.productPrice) { // El precio de la puja debe ser mayor que el precio original
                strcpy(item_S.bidder, param2);
                item_S.productPrice = atof(param3);
                if (item_temp.bidStack.top!=SMAX-1) { // Comprobamos que la pila esté llena
                    push(item_S, &item_temp.bidStack);  // Insertamos los elementos en la pila
                    ++item_temp.bidCounter; // Se le suma uno al contador de pujas
                    printf("* Bid: product %s bidder %s category %s price %.2f bids %d\n", item_temp.productId,
                           item.seller,
                           book_or_painting(item_temp.productCategory), item.productPrice, item_temp.bidCounter);
                    updateItem(item_temp, pos, L); // Actualizamos los datos
                } else // Si la pila estuviese llena
                    printf("+ Error: Bid not possible\n");
            }
            else // Si el precio de la puja no es mayor que el del precio anterior, imprimimos error:
                printf("+ Error: Bid not possible\n");
        }
        else  // Si el vendedor y el pujador son los mismos, imprimimos el error:
            printf("+ Error: Bid not possible\n");
    }
    else // Si no existiese el producto al que se desea pujar, imprimimos el error:
        printf("+ Error: Bid not possible\n");
}
void Stats (tList L) {
    tItemL item, item_aux;
    tPosL pos;
    int totalBooks=0, totalPaintings=0;            // Declaramos dos variables que vayan contando la cantidad de productos de cada categoría
    float sumPricesBooks=0, sumPricesPaintings=0; // Declaramos dos variables para la suma de los precios de cada categoría
    float mediaBooks,mediaPaintings;             // Declaramos dos variables para la media de los precios de cada categoría
    float incremento=0;
    float porcentaje;
    int control=0;
    if (!isEmptyList(L)) {                      // Comprobamos si la lista está vacía
        for (pos = first(L); pos != LNULL; pos = next(pos, L)) { // Recorremos la lista
            item = getItem(pos, L);
            if (item.bidCounter!=0) {     // En caso de que el bid counter sea distinto de cero, implicará que ya ha habido alguna puja sobre el producto
                if (incremento < (peek(item.bidStack).productPrice-item.productPrice)/item.productPrice) { // Buscamos el mayor incremento de precio
                    control++; // Le sumamos uno a la variable de control para luego cuando hagamos el printf final saber si imprimir el error o el mensaje de top bid
                    incremento = ((peek(item.bidStack).productPrice - item.productPrice)/item.productPrice); // Calculamos el incremento
                    porcentaje = (incremento)*100; // Calculamos el porcentaje del incremento
                    item_aux = item;
                }
                printf("Product %s seller %s category %s price %.2f bids %d top bidder %s\n", item.productId,
                       item.seller,
                       book_or_painting(item.productCategory), item.productPrice, item.bidCounter,
                       peek(item.bidStack).bidder);
            }
            else
                printf("Product %s seller %s category %s price %.2f. No bids\n",item.productId,item.seller,
                       book_or_painting(item.productCategory),item.productPrice);

            if (item.productCategory == book) {      // Comprobamos si el producto es book o painting
                ++totalBooks;       // Sumamos uno al contador de books
                sumPricesBooks = sumPricesBooks + item.productPrice;        // Se va sumando el precio de cada book
            }
            else {
                ++totalPaintings;     // Sumamos uno al contador de paintings
                sumPricesPaintings = sumPricesPaintings + item.productPrice; // Se va sumando el precio de cada painting
            }
        }
        if (totalBooks==0)       // En caso de que el total de books sea 0
            mediaBooks=0;       // La media del precio será 0
        else
            mediaBooks = sumPricesBooks/(float)totalBooks;

        if (totalPaintings==0)      // En caso de que el total de paintings sea 0
            mediaPaintings=0;      // La media del precio será 0
        else
            mediaPaintings = sumPricesPaintings/(float)totalPaintings;

        printf("\n");
        printf("Category  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n",totalBooks,sumPricesBooks,mediaBooks);
        printf("Painting  %8d %8.2f %8.2f\n",totalPaintings,sumPricesPaintings,mediaPaintings);
        if (control!=0) // En caso de la variable de control haya cambiado (respecto a su valor inicial 0) es que ha habido alguna puja, por lo tanto hay un top bid
            printf("Top bid: Product %s seller %s category %s price %.2f bidder %s top price %.2f increase %.2f%%\n",item_aux.productId,item_aux.seller, book_or_painting(item_aux.productCategory),
               item_aux.productPrice, peek(item_aux.bidStack).bidder, peek(item_aux.bidStack).productPrice,porcentaje);
        else // Si la variable de control no ha cambiado (respecto a su valor inicial 0) es que no hay un top bid
            printf("Top bid not possible\n");
    }
    else {
        printf("+ Error: Stats not possible\n");
    }
}
void Delete (char *param1, tList *L) {
    tPosL pos;
    tItemL item;
    strcpy(item.productId,param1);
    pos = findItem(param1,*L); // Buscamos la posición donde se encuentra el producto
    if (pos != LNULL) {  // Comprobamos si el producto se encuentra en la lista
        // Si se encuentra en la lista:
        item = getItem(pos,*L);
        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n",item.productId,item.seller,
               book_or_painting(item.productCategory),item.productPrice,item.bidCounter);
        while (!isEmptyStack(item.bidStack)) {
            pop(&item.bidStack); // Se eliminan las pujas
        }
        updateItem(item,pos,L);
        deleteAtPosition(pos,L); // Se elimina
    }
    else { // En caso de que no se encuentre el producto en la lista imprimimos el error:
        printf("+ Error: Delete not possible\n");
    }
}
void Award (char *param1, tList *L) {
    tItemL item;
    tPosL pos;
    strcpy(item.productId,param1);
    pos = findItem(item.productId,*L);  // Buscamos el producto en la lista con ese productId
    if ((pos != LNULL) && (!isEmptyStack(item.bidStack))) {  // Comprobamos que exista un producto con ese productId y que la pila de pujas no esté vacía
        item = getItem(pos,*L);
        printf("* Award: product %s bidder %s category %s price %.2f\n", item.productId, peek(item.bidStack).bidder,
                   book_or_painting(item.productCategory), peek(item.bidStack).productPrice);
        while (!isEmptyStack(item.bidStack)) {
            pop(&item.bidStack); // Vaciamos su pila de pujas
        }
        updateItem(item,pos,L);
        deleteAtPosition(pos,L); // Lo eliminamos de la lista
    }
    else   // En casi de que el producto no esté en la lista o la pila de pujas esté vacía, imprimimos el error:
        printf("+ Error: Award not possible\n");
}
void Withdraw (char *param1, char *param2, tList *L) {
    tItemL item;
    char bidder[10];  // Utilizaremos un char para guardar el bidder para hacer luego la comparación
    tPosL pos;
    strcpy(item.productId,param1);
    strcpy(bidder,param2);
    pos = findItem(item.productId,*L);
    if (pos != LNULL) {  // Comprobamos que el producto esté en la lista
        item = getItem(pos,*L);
        if (!isEmptyStack(item.bidStack)) {   // Comprobamos si la pila está vacía
            if (strcmp(bidder, peek(item.bidStack).bidder)==0) {  // Comprobamos que el userId que recibimos sea igual con el autor de la puja
                printf("* Withdraw: product %s bidder %s category %s price %.2f bids %d\n",item.productId, peek(item.bidStack).bidder,
                       book_or_painting(item.productCategory), peek(item.bidStack).productPrice,item.bidCounter);
                pop(&item.bidStack);
                --item.bidCounter;
                updateItem(item,pos,L);
            }
            else // Si el userId que nos introducen no es el mismo que el autor de la puja, imprimimos el error:
                printf("+ Error: Withdraw not possible\n");
        }
        else // En caso de que la pila de pujas estuviese vacía, imprimimos el error:
            printf("+ Error: Withdraw not possible\n");
    }
    else  // En caso de que el producto no esté en la lista, imprimimos el error:
        printf("+ Error: Withdraw not possible\n");
}
void Remove (tList *L) {
    tItemL item;
    tPosL pos,pos_aux;
    int control=0;  // Declaramos una variable de control para luego saber si al recorrer la lista se ha encontrado algún producto sin pujas
    if (!isEmptyList(*L)) { // Comprobamos que la lista no esté vacía
        pos = last(*L);
        while (pos!=LNULL) {  // Mientras no se llegue a la primera posición:
            item = getItem(pos,*L);
            if (item.bidCounter==0) {     // Si el producto no tiene pujas:
                control++; // Sumamos uno a la variable de control, para que no salte el error
                printf("Removing product %s seller %s category %s price %.2f bids %d\n",item.productId, item.seller,
                       book_or_painting(item.productCategory),item.productPrice,item.bidCounter);
                pos_aux = previous(pos,*L);   // Guardamos la posición en una auxiliar para no perderla después de hacer el delete
                deleteAtPosition(pos,L);
                pos = pos_aux;
            }
            pos = previous(pos,*L);
        }
        if (control==0) {   // En caso de que no haya ningún producto sin pujas la variable de control seguirá en cero, por lo tanto imprimimos el error:
            printf("+ Error: Remove not possible\n");
        }
    }
    else  // En caso de que la lista esté vacía, imprimimos el error:
        printf("+ Error: Remove not possible\n");
}