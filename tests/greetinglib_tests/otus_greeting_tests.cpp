#include "precompiled.h"
#include "otus_greeting.h"

TEST(GreetingTest, test_greeting)
{
    otus::Greeting greeting;
    ASSERT_EQ(std::string{"Oh, hi!"}, greeting.sayHello());
}
