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

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "smart_wrapper.hpp"

TEST_CASE("Constructors")
{
    // default constructor
    REQUIRE([]() -> bool {
        constexpr int expected = 0;
        smart_wrapper wrapped;
        return wrapped.value() == expected;
    });

    // explicit constructor
    REQUIRE([]() -> bool {
        constexpr int expected = 42;
        smart_wrapper wrapped{ expected };
        return wrapped.value() == expected;
    });

    // copy constructor
    REQUIRE([]() -> bool {
        constexpr int expected = 23;
        smart_wrapper original{ expected };
        smart_wrapper copy{ original };
        return copy.value() == expected;
    });

    // move constructor
    REQUIRE([]() -> bool {
        constexpr int expected = 32;
        smart_wrapper original{ expected };
        smart_wrapper moved{ std::move(original) };
        return moved.value() == expected;
    });
}


TEST_CASE("Assignment")
{
    // copy assignment
    REQUIRE([]() -> bool {
        constexpr int expected = 1023;
        smart_wrapper source{ expected };
        smart_wrapper target;
        target = source;
        return (target.value() == source.value()) && (target.value() == expected);
    });

    // move assignment
    REQUIRE([]() -> bool {
        constexpr int expected = 1966;
        smart_wrapper source{ expected };
        smart_wrapper target;
        target = std::move(source);
        return target.value() == expected;
    });
}
