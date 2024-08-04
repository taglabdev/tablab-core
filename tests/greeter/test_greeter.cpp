#include <doctest/doctest.h>

#include <greeter/greeter.h>

TEST_CASE("greet")
{
    auto constexpr GREET_TEXT = "Hello world!";
    auto greeter = Greeter{GREET_TEXT};
    CHECK(greeter.greet() == GREET_TEXT);
}
