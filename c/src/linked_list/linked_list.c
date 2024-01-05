#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"


struct node* create_node(Person p) {
    struct node* n = (struct node*) malloc(sizeof(node));
    strncpy(n->person.name, p.name, 50);
    strncpy(n->person.last_name, p.last_name, 50);
    n->person.age = p.age;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void delete_node(struct node* node) {
    free(node);
}

void add_first(linked_list* list, Person p) {
    struct node* node = create_node(p);
    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->first->prev = node;
        node->next = list->first;
        list->first = node;
    }
    list->size++;
}

void add_last(linked_list* list, Person p) {
    struct node* node = create_node(p);
    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    list->size++;
}

void remove_first(linked_list* list) {
    if (list->first != NULL) {
        unlink(list, list->first);
    }
}

void remove_last(linked_list* list) {
    if (list->last != NULL) {
        unlink(list, list->last);
    }
}

void remove(linked_list* list,int index) {

}

void unlink(linked_list* list, struct node* node) {
    struct node* prev = node->prev;
    struct node* next = node->next;

    if (prev == NULL) {
        list->first = next;
    } else {
        prev->next = next;
    }

    if (next == NULL) {
        list->last = prev;
    } else {
        next->prev = prev;
    }

    delete_node(node);
    list->size--;
}

struct node* get_node(linked_list* list, int index) {
    struct node* node;

    if (index < list->size) {
        if (index < (list->size >> 1)) {
            node = list->first;
            for (int i = 0; i < index; i++) {
                node = node->next;
            }
        } else {
            node = list->last;
            for (int j = list->size -1; j > index; j--){
                node = node->prev;
            }
        }
    }
    return node;
}