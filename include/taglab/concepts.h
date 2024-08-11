#pragma once

#include <filesystem>

namespace taglab {

template<class T>
concept String = std::convertible_to<T, std::string>;

template<class T>
concept Path = std::convertible_to<T, std::filesystem::path> || String<T>;

};
