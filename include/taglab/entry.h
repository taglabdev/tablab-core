#pragma once

#include <filesystem>
#include <ostream>

namespace taglab {

struct Entry {
    std::filesystem::path path;

    bool operator==(Entry const &other) const;
};

std::ostream &operator<<(std::ostream &os, Entry const &entry);

}; // taglab
