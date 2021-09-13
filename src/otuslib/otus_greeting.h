#ifndef OTUS_CPP_OTUS_GREETING_H
#define OTUS_CPP_OTUS_GREETING_H

#include "otus_exports.h"

#include <string>

namespace otus
{

class OTUS_API Greeting
{
public:
    Greeting() = default;
    ~Greeting() = default;

    std::string sayHello() const;
};

} //namespace otus

#endif //OTUS_CPP_OTUS_GREETING_H