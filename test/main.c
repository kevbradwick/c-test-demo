#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#include "contacts.h"

static void test_add_contact_increments_total(void **state)
{
    Contacts_t *list = calloc(1, sizeof(Contacts_t));

    assert_int_equal(0, list->total);

    add_contact(list, "Kevin Bradwick", "07777777777");

    assert_int_equal(1, list->total);
}

static void test_get_contact(void **state)
{
    Contacts_t *list = calloc(1, sizeof(Contacts_t));
    add_contact(list, "Kevin Bradwick", "07777777777");
    Person_t *person = get_contact(0, list);

    assert_string_equal("Kevin Bradwick", person->name);
    assert_string_equal("07777777777", person->telephone);
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_add_contact_increments_total),
        cmocka_unit_test(test_get_contact),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
