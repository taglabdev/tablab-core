#pragma once

#include <memory>
#include <vector>

#include <taglab/storage.h>
#include <taglab/entry.h>

namespace taglab {

class Library
{
public:
    Library(std::unique_ptr<Storage> /* storage */) { }

    std::vector<Entry> entries() const { return {}; }
};

};
