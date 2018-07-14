#pragma once

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

#include <memory>
#include <new>
#include <utility>

#include "legacy.h"

class smart_wrapper
{
private:
    struct legacy_deleter
    {
        void operator()(legacy_t* ptr)
        {
            auto tmp = ptr;
            legacy_free(&tmp);
        }
    };

    std::unique_ptr<legacy_t, legacy_deleter> sp;

protected:
    legacy_t* raw()
    {
        return sp.get();
    }

    legacy_t const* raw() const
    {
        return sp.get();
    }

public:
    smart_wrapper()
        : sp(legacy_new(0))
    {
        if (!sp) {
            throw std::bad_alloc();
        }
    }

    explicit smart_wrapper(int value)
        : sp(legacy_new(value))
    {
        if (!sp) {
            throw std::bad_alloc();
        }
    }

    smart_wrapper(smart_wrapper const& src)
        : sp(legacy_clone(src.raw()))
    {
    }

    smart_wrapper(smart_wrapper&& src) noexcept
        : sp(std::move(src.sp))
    {
    }

    smart_wrapper& operator=(smart_wrapper const& rhs)
    {
        if (this != &rhs) {
            sp.reset(legacy_clone(rhs.raw()));
        }

        return *this;
    }

    smart_wrapper& operator=(smart_wrapper&& rhs) noexcept
    {
        sp = std::move(rhs.sp);
        return *this;
    }

    /**
     * std::unique_ptr<> calls operator() of legacy_deleter to
     * delete the underlying object via calling legacy_free().
     */
    ~smart_wrapper() = default;

    // accessors for the underlying legacy C struct code
    int value() const
    {
        return legacy_get_value(raw());
    }

    void value(int new_value)
    {
        legacy_set_value(raw(), new_value);
    }
};
