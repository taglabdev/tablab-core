#pragma once

#include <cstdint>
#include <utility>

#include <taglab/utils/concepts.h>

namespace taglab {

struct Entry {
    int64_t id;
    std::filesystem::path path;

    Entry() = default;

    template<class... Args>
    Entry(Args &&...args)
        : Entry{{}, std::forward<Args>(args)...}
    {
    }

    Entry(int64_t _id, Path auto &&_path)
        : id{_id}
        , path{std::forward<decltype(_path)>(_path)}
    {
    }
};

}; // taglab
