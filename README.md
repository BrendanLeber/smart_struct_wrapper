# smart_wrapper

A modern C++ wrapper for old C structs using a `std::unique_ptr<>`
smart pointer.

## Why I created this?

At my day job we have a massive legacy code base written in C.  My
team is creating our project using modern C++ and we have a use for
the legacy code.  We didn't want to re-invent the wheel and create
bugs in well used and tested existing code.  So this is a "toy"
example of how to wrap the legacy calls in a C++ object and use the
standard library smart pointer features to control ownership.

It is just an example but it compiles without any warnings and
[valgrind](http://valgrind.org) does not detect any memory leaks.

## Contributing

Pull requests are welcome.

- Please use `make format` to format your code according to the
  project settings in `.clang-format`.

- Please use `make tidy` to check your code for errors according to
  the project settings in `.clang-tidy`.

- To save time the default target in [Makefile](Makefile) calls
  `clang-format` followed by `clang-tidy` so they can be run easily
  with an editor macro.

## Author

- Brendan Leber &lt;brendan@brendanleber.com&gt;
