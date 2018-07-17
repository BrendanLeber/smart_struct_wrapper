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

bool test_default_constructor()
{
    constexpr int expected = 0;
    smart_wrapper wrapped;
    return wrapped.value() == expected;
}

bool test_explicit_constructor()
{
    constexpr int expected = 42;
    smart_wrapper wrapped{ expected };
    return wrapped.value() == expected;
}

bool test_copy_constructor()
{
    constexpr int expected = 23;
    smart_wrapper original{ expected };
    smart_wrapper copy{ original };  // NOLINT we know we aren't using `original`
    return copy.value() == expected;
}

bool test_move_constructor()
{
    constexpr int expected = 32;
    smart_wrapper original{ expected };
    smart_wrapper moved{ std::move(original) };
    return moved.value() == expected;
}

TEST_CASE("Constructors")
{
    REQUIRE(test_default_constructor());
    REQUIRE(test_explicit_constructor());
    REQUIRE(test_copy_constructor());
    REQUIRE(test_move_constructor());
}


bool test_copy_assignment()
{
    constexpr int expected = 1023;
    smart_wrapper source{ expected };
    smart_wrapper target;
    target = source;
    return (target.value() == source.value()) && (target.value() == expected);
}

bool test_move_assignment()
{
    constexpr int expected = 1966;
    smart_wrapper source{ expected };
    smart_wrapper target;
    target = std::move(source);
    return target.value() == expected;
}

bool test_self_copy_assignment()
{
    constexpr int expected = 1023;
    smart_wrapper target{ expected };
    target = target;
    return target.value() == expected;
}

/**
 * Turn off self move warnings because we are testing self move to make
 * sure it doesn't introduce any memory errors.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wself-move"

bool test_self_move_assignment()
{
    constexpr int expected = 1966;
    smart_wrapper target{ expected };
    target = std::move(target);
    return target.value() == expected;  // NOLINT
}

#pragma clang diagnostic pop

TEST_CASE("Assignment")
{
    REQUIRE(test_copy_assignment());
    REQUIRE(test_move_assignment());
    REQUIRE(test_self_copy_assignment());
    REQUIRE(test_self_move_assignment());
}


bool test_get_default_accessor()
{
    constexpr int expected = 0;
    smart_wrapper sw{};
    return expected == sw.value();
}

bool test_set_get_accessor()
{
    constexpr int expected = 52;
    smart_wrapper sw{};
    sw.value(expected);
    return expected == sw.value();
}


TEST_CASE("Accessors")
{
    REQUIRE(test_get_default_accessor());
    REQUIRE(test_set_get_accessor());
}
