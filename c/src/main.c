#include <stdio.h>
#include <string.h>

#include "person.h"

void print_person(Person* person);

int main() {

    Person person;

    strcpy(person.name, "Sting");
    strcpy(person.last_name, "Bobadilla");
    person.age = 25;

    PrintPerson(&person);

    return 0;
}