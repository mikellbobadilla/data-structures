#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "person.h"

struct node {
    struct node* prev;
    Person person;
    struct node* next;
} node;

typedef struct linked_list {
    int size;
    struct node* first;
    struct node* last;
} linked_list;

#endif