#include "List.h"
#include <stdio.h>
#include <stdlib.h>

List  addHead(List l, int value) {
    //We creat a new element:
    List newel = (Element*) malloc(sizeof(Element));
    newel->value=value;

    //The address of the following element is assigned to the new element:
    newel->next=l;

    //We return the new list:
    return newel;
}

List  addTail(List l, int value) {
    //We creat a new element:
    List newel = (Element*) malloc(sizeof(Element));

    //We assign the value of the new element:
    newel->value=value;

    //The address of the following item is declared as null:
    newel->next=NULL;

    //If the list is empty, just return the created item:
    if (l==NULL) {
        return newel;
    } else { //Otherwise, we run the list using a temporary pointer and indicate that the last item in the list is linked to the new item:
        List temp=l;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=newel;
        return l;
    }

    //We return the new list:
    return l;
}

List  deleteHead(List l) {
    if(l!=NULL) {
        //If the list is not empty, we prepare to return the address of the element in 2nd position:
        List temp=l->next;
        //We release the first element:
        free(l);
        //Returns the new start of the list:
        return temp;
    } else {
        return NULL;
    }
}

List  deleteTail(List l) {
    //Go to the end of the list:
    List temp=l;
    while (temp->next!=NULL) {
        temp=temp->next;
    }

    //We free the memory space containing the tail:
    free(l);

    //The address of the new location is assigned:
    temp->next=NULL;

    //Returns the new list:
    return temp;
}

int countElement(List l) {
    int counter = 0;
    //We use a temporary list to don't modify the original list.
    List temp=l;
    //While the list isn't empty, we travel it and increment the counter:
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void printList(List l) {
    //If the list is empty we inform the user:
    if (l == NULL) {
        printf("The list is empty.\n");
        return;
    }

    //Otherwise we browse a temporary list to not change the original list:
    List temp=l;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
}
