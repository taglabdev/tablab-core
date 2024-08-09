#include <ranges>
#include <vector>
#include <sstream>

#include <doctest/doctest.h>

namespace doctest {
template<typename T>
struct StringMaker<std::vector<T>> {
    static String convert(std::vector<T> const &in)
    {
        auto oss = std::ostringstream{};
        oss << "[";
        if (in.size() > 0)
            oss << in.front();
        for (auto const &element : in | std::views::drop(1)) {
            oss << ", " << element;
        }
        oss << "]";
        return oss.str().c_str();
    }
};
}
