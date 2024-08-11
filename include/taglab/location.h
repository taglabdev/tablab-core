#pragma once

#include <cstdint>
#include <filesystem>
#include <ostream>
#include <utility>

#include <taglab/utils/concepts.h>

namespace taglab {

struct Location {
    int64_t id;
    std::string name;
    std::filesystem::path path;

    Location() = default;

    template<class... Args>
    Location(Args &&...args)
        : Location{{}, std::forward<Args>(args)...}
    {
    }

    Location(int64_t _id, String auto &&_name, Path auto &&_path)
        : id{_id}
        , name{std::forward<decltype(_name)>(_name)}
        , path{std::forward<decltype(_path)>(_path)}
    {
    }
};

std::ostream &operator<<(std::ostream &os, Location const &location);

};
