/**
 * Smart Wrapper for Legacy Code
 * Version 0.0.1
 * https://github.com/BrendanLeber/smart_wrapper
 *
 * Licened under the MIT License <http://opensource.org/licenses/MIT>.
 *
 * Copyright (c) 2018 Brendan Leber
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "legacy.h"

legacy_t* legacy_new(int value)
{
    legacy_t* ptr = (legacy_t*) malloc(sizeof(legacy_t));
    if (ptr != NULL) {
        ptr->value = value;
    }
    return ptr;
}

legacy_t* legacy_clone(legacy_t const* src)
{
    assert(src != NULL);
    legacy_t* clone = (legacy_t*) malloc(sizeof(legacy_t));
    if (clone != NULL) {
        memcpy(clone, src, sizeof(legacy_t));
    }
    return clone;
}

void legacy_free(legacy_t** pptr)
{
    assert(pptr != NULL);
    if (*pptr != NULL) {
        free(*pptr);
        *pptr = NULL;
    }
}

int legacy_get_value(legacy_t const* ptr)
{
    assert(ptr != NULL);
    return ptr->value;
}

void legacy_set_value(legacy_t* ptr, int new_value)
{
    assert(ptr != NULL);
    ptr->value = new_value;
}
