#pragma once

#include <cstdint>
#include <filesystem>
#include <utility>

#include <SQLiteCpp/Column.h>

#include <taglab/utils/concepts.h>
#include <taglab/utils/meta.h>

namespace taglab {

struct Location {
    int64_t id;
    std::string name;
    std::filesystem::path path;

    template<class... Args>
    Location(Args &&...args)
        requires(noneOf(std::same_as<Args, SQLite::Column>...))
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

};
