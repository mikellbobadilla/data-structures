#include <stdio.h>
#include <string.h>

#include "list.h"
#include "person.h"

void Print(List* l);

int main() {
    List l;

    Person ps[3];

    strcpy(ps[0].name, "Sting");
    strcpy(ps[0].last_name, "Bobadilla");
    ps[0].age = 25;

    strcpy(ps[1].name, "Sofía");
    strcpy(ps[1].last_name, "De la Vega");
    ps[1].age = 20;

    strcpy(ps[1].name, "Alejandro");
    strcpy(ps[1].last_name, "Patiño");
    ps[1].age = 30;

    Print(&l);
}