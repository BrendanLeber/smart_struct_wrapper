#pragma once

#include <iostream>
#include <memory>
#include <new>

#include "legacy.h"


class smart_wrapper
{
private:
    struct legacy_deleter
    {
        void operator()(legacy_t* ptr)
        {
            std::cout << "legacy_deleter::operator()(" << ptr << ")\n";
            auto tmp = ptr;
            legacy_free(&tmp);
        }
    };

    using legacy_sp = std::unique_ptr<legacy_t, legacy_deleter>;
    legacy_sp wrap;

public:
    smart_wrapper()
        : wrap(legacy_new(0))
    {
        std::cout << "smart_wrapper::smart_wrapper() - " << wrap.get() << '\n';
        if (!wrap) {
            throw std::bad_alloc();
        }
    }

    smart_wrapper(smart_wrapper const& src) = delete;             // copy constructor
    smart_wrapper(smart_wrapper&& src)      = delete;             // move constructor
    smart_wrapper& operator=(smart_wrapper const& rhs) = delete;  // copy assignment operator
    smart_wrapper& operator=(smart_wrapper&& rhs) = delete;       // move assignment operator

    ~smart_wrapper()
    {
        std::cout << "smart_wrapper::~smart_wrapper() - " << wrap.get() << '\n';
        // std::unique_ptr<> calls operator() of legacy_deleter to
        // delete the underlying object by calling legacy_free().
    }

    int get_value() const
    {
        auto v = legacy_get_value(wrap.get());
        std::cout << "smart_wrapper::get_value(" << wrap.get() << ") -> " << v << '\n';
        return v;
    }

    void set_value(int new_value)
    {
        std::cout << "smart_wrapper::set_value(" << wrap.get() << ", " << new_value << ")\n";
        legacy_set_value(wrap.get(), new_value);
    }
};
