#include "smart_wrapper.hpp"

int main()
{
    {
        std::cout << "*** default constructor/destructor\n";
        smart_wrapper wrapped;
    }

    return 0;
}
