#pragma once

#include <concepts>
#include <cstdint>
#include <filesystem>
#include <utility>

namespace taglab {

template<class T>
concept Path = std::convertible_to<T, std::filesystem::path> || std::convertible_to<T, std::string>;

struct Entry {
    int64_t id;
    std::filesystem::path path;

    Entry(Path auto &&_path)
        : path{std::forward<decltype(_path)>(_path)}
    {
    }

    Entry(int64_t _id, Path auto &&_path)
        : id{_id}
        , path{std::forward<decltype(_path)>(_path)}
    {
    }
};

}; // taglab
