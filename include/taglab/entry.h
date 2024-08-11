#pragma once

#include <concepts>
#include <cstdint>
#include <utility>

#include <SQLiteCpp/Column.h>

#include <taglab/utils/concepts.h>
#include <taglab/utils/meta.h>

namespace taglab {

struct Entry {
    int64_t id;
    std::filesystem::path path;

    template<class... Args>
    Entry(Args &&...args)
        requires(NoneOf(std::same_as<Args, SQLite::Column>...))
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
