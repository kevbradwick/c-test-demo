#ifndef CONTACTS_H_
#define CONTACTS_H_


typedef struct Person {
    const char *name, *telephone;
    struct Person *next, *prev;
} Person_t;


typedef struct Contacts {
    Person_t *first, *last;
    int total;
} Contacts_t;

void add_contact(Contacts_t *list, const char *name, const char *number);

Person_t *get_contact(int index, Contacts_t *list);


#endif // CONTACTS_H_
