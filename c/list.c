#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"


void AddFirst (List* l, Person* person) {
    Node* n = CreateNode(person);
    linkFirst(l, n);
}

void Add(List* l, Person* person) {
    Node* n = CreateNode(person);
    linkLast(l, n);
}

void RemoveFirst(List* l) {
    if (l->first != NULL){
        unlink(l, l->first) ;
    }
}

void RemoveLast(List* l) {
    if (l->last != NULL) {
        unlink(l, l->last);
    }
}

void Remove(List* l, int index) {
    unlink(l, index);
}

Person Get(List* l, int index) {
    Node* n = node(l, index);
    return n->person;
}

void Print(List* l) {
    Node* pointer = l->first;

    while (pointer != NULL) {
        printf("[");
        printf("Nombre: %s", pointer->person.name);
        printf("Apellido: %s", pointer->person.last_name);
        printf("Edad: %d", pointer->person.age);
        printf("]\n");
        pointer = pointer->next;
    }
}

Node* CreateNode(Person* person) {
    Node* n = malloc(sizeof(Person));
    strncpy(n->person.name, person->age, 50);
    strncpy(n->person.last_name, person->last_name, 50);
    n->person.age = person->age;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void FreeNode(Node* node) {
    free(node);
}

Node* node(List* l, int index) {
    Node* n = NULL;
    if (index < l->size) {
        if (index < (l->size >> 1)) {
            n = l->first;
            for (int i = 0; i < index; i++) {
                n = n->next;
            }
        } else {
            n = l->last;
            for (int j = l->size - 1; j > index; j--) {
                n = n->prev; 
            }
        }
    }

    return n;
}

void linkFirst(List* l,  Node* node) {
    if (l->first == NULL) {
        l->first = node;
        l->last = node;
    } else {
        l->first->prev = node;
        node->next = l->first;
        l->first = node;
    }
    l->size++;
}

void linkLast(List* l, Node* node) {
    if (l->last == NULL) {
        l->last = node;
        l->first = node;
    } else {
        l->last->next = node;
        node->prev = l->last;
        l->last = node;
    }
}

void unlink(List* l, Node* node) {
    Node* next = node->next;
    Node* prev = node->prev;

    if (prev == NULL) {
        l->first = next;
    } else {
        prev->next = next;
    }

    if (next == NULL) {
        l->last = prev;
    } else { 
        next->prev = prev;
    }

    FreeNode(node);
    l->size--;
}