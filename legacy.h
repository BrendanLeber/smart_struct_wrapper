#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct legacy
{
    int value;
} legacy_t;

legacy_t* legacy_new(int value);
void legacy_free(legacy_t** pptr);
int legacy_get_value(legacy_t const* ptr);
void legacy_set_value(legacy_t* ptr, int new_value);

#if defined(__cplusplus)
}
#endif
