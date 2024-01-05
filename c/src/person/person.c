#include <stdio.h>
#include <string.h>

#include "person.h"

void print_person(Person* p) {
    printf("[Nombre: %s, Apellido: %s, Edad: %d]\n", p->name, p->last_name, p->age);
}
