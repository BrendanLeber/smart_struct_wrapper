all: format tidy

tidy:
	clang-tidy -config='' -p build smart_wrapper.cpp

format:
	clang-format -style=file -i smart_wrapper.?pp
