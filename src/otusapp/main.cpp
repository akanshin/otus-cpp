#include "otusapp_precompiled.h"

int main(int argc, char** argv)
{
    otus::Greeting greeting;
    std::cout << greeting.sayHello() << std::endl;
    return EXIT_SUCCESS;
}
