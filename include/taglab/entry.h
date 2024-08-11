#pragma once

#include <cstdint>
#include <utility>

#include <taglab/concepts.h>

namespace taglab {

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
