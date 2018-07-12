#include "legacy.h"

legacy_t* legacy_new(int value)
{
    legacy_t* ptr = (legacy_t*) malloc(sizeof(legacy_t));
    printf("legacy_new(%d) - %p\n", value, (void*) ptr);
    return ptr;
}

void legacy_free(legacy_t** pptr)
{
    printf("legacy_free(%p)\n", (void*) *pptr);

    assert(pptr != NULL);
    if (*pptr != NULL) {
        free(*pptr);
        *pptr = NULL;
    }
}

int legacy_get_value(legacy_t const* ptr)
{
    assert(ptr != NULL);
    printf("legacy_get_value(%p) - %d\n", (void const*) ptr, ptr->value);
    return ptr->value;
}

void legacy_set_value(legacy_t* ptr, int new_value)
{
    assert(ptr != NULL);
    printf("legacy_set_value(%p, %d) - %d\n", (void*) ptr, new_value, ptr->value);
    ptr->value = new_value;
}
