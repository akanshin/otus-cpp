#include "precompiled.h"

int main(int argc, char** argv)
{
    std::cout << "Build: " << OTUSCPP_BUILD_ID << std::endl;

    otus::Greeting greeting;
    std::cout << greeting.sayHello() << std::endl;
    return EXIT_SUCCESS;
}
