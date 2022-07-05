#include "Message.hpp"
#include <iostream>

int main(void)
{
    Message msg("Hello, CMake World");
    std::cout<<msg<<std::endl;
    return 0;
}