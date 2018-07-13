# smart_wrapper

A modern C++ wrapper for old C structs using a `std::unique_ptr<>`
smart pointer.

[![Build Status](https://travis-ci.org/BrendanLeber/smart_wrapper.svg?branch=master)](https://travis-ci.org/BrendanLeber/smart_wrapper)

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

## License

<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

The class is licensed under the [MIT License](http://opensource.org/licenses/MIT):

Copyright &copy; 2018 [Brendan Leber](http://www.brendanleber.com/)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
“Software”), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contact

If you have questions regarding the library, I would like to invite
you to [open an issue at
GitHub](https://github.com/BrendanLeber/smart_wrapper/issues/new).
Please describe your request, problem, or question as detailed as
possible, and also mention the version of the project you are using as
well as the version of your compiler and operating system.  Opening an
issue at GitHub allows other users and contributors to this project to
collaborate.

Only if your request would contain confidential information, please
[send me an email](mailto:brendan@brendanleber.com).  For encrypted messages,
please use [this key](https://keybase.io/brendanleber/pgp_keys.asc).

## Security

[Commits by Brendan
Leber](https://github.com/BrendanLeber/smart_wrapper/commits) and
[releases](https://github.com/BrendanLeber/smart_wrapper/releases) are signed with
this [PGP
Key](https://keybase.io/brendanleber/pgp_keys.asc?fingerprint=EA6B6FC0EF151B355EBEA4AF3D51B090DCF5AC42).

