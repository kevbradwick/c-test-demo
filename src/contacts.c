#include <stdlib.h>
#include "contacts.h"


void add_contact(Contacts_t *list, const char *name, const char *number)
{
    // create a new person
    Person_t *person = calloc(1, sizeof(Person_t));
    person->name = name;
    person->telephone = number;

    if (list->last != NULL) {
        list->last->next = person;
    }

    // adding a new person will always put it at the last in the list
    person->prev = list->last;
    list->last = person;
    list->total++;

    // this is the first contact in the list
    if (list->first == NULL) {
        list->first = person;
    }
}


Person_t *get_contact(int index, Contacts_t *list)
{
    Person_t *person = list->first;

    for (int i=0; i<list->total; i++) {
        if (i == index) {
            return person;
        }
        if (person != NULL) {
            person = person->next;
        }
    }

    return NULL;
}
