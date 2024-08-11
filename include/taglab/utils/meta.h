#pragma once

#include <concepts>

constexpr bool NoneOf(std::same_as<bool> auto... params)
{
    return !(params || ...);
}
