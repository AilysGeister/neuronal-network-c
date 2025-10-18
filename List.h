#ifndef LIST_H
#define LIST_H

typedef struct elem {
    int value;
    struct elem* next;
}Element;

typedef Element* List;

/**
 * Function that allows you to add a new item at the top of the list.
 * @param l The list where we add a new element.
 * @param value The value to add.
 * @return The modified list.
 */
List  addHead(List l, int value);

/**
 * Function that allows you to add an item in the list.
 * @param l The list where we add a new element.
 * @param value The value to add.
 * @return The modified list.
 */
List  addTail(List l, int value);

/**
 * Function that removes the item at the top of a list.
 * @param l The list where we remove a element.
 * @return The modified list.
 */
List  deleteHead(List l);

/**
 * Function that allows to add an item in a list.
 * @param l The list where we remove a element.
 * @return The modified list.
 */
List  deleteTail(List l);

/**
 * Function that counts the number of items in a chained list.
 * @param l The list we want to count.
 * @return The number of element of the list.
 */
int countElement(List l);

/**
 * Procedure for displaying a list.
 * @param l The list the display.
 */
void printList(List l);

#endif //LIST_H