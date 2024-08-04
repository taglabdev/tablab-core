#include "greeter.h"

using namespace std;

Greeter::Greeter(string greetMessage)
    : greetMessage_{std::move(greetMessage)}
{
}

string_view Greeter::greet()
{
    return greetMessage_;
}
