#pragma once

#include <concepts>

constexpr bool noneOf(std::same_as<bool> auto... params)
{
    return !(params || ...);
}
