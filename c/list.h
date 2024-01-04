#ifndef list_h
#define list_h

#include "person.h"

typedef struct Node {
    Node* prev;
    Person person;
    Node* next;
} Node;

typedef struct List {
    int size;
    Node* first;
    Node* last;
} List;

#endif