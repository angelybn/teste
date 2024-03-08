#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "element.h"

typedef struct DLinkedList DLinkedList;

DLinkedList *dlist_create();
void dlist_destroy(DLinkedList *list);
void dlist_insertFirst(DLinkedList *list, Element element);
void dlist_insertLast(DLinkedList *list, Element element);
void dlist_insertAt(DLinkedList *list, int index, Element element);
void dlist_removeFirst(DLinkedList *list);
void dlist_removeLast(DLinkedList *list);
void dlist_removeAt(DLinkedList *list, int index);
Element dlist_getFirst(DLinkedList *list);
Element dlist_getLast(DLinkedList *list);
Element dlist_getAt(DLinkedList *list, int index);
void dlist_setAt(DLinkedList *list, int index, Element element);
int dlist_size(DLinkedList *list);
int dlist_isEmpty(DLinkedList *list);
void dlist_printForward(DLinkedList *list);
void dlist_printReverse(DLinkedList *list);
DLinkedList* reverse(DLinkedList* l);

#endif