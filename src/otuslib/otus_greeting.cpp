#include "otus_precompiled.h"
#include "otus_greeting.h"

namespace otus
{

std::string Greeting::sayHello() const
{
    auto f = std::async(std::launch::async, []()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return "Oh, hi!";
    });
    return f.get();
}

} //namespace otus
