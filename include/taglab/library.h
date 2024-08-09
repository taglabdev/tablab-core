#pragma once

#include <vector>

#include <taglab/storage.h>
#include <taglab/entry.h>

namespace taglab {

template<Storage StorageType>
class Library
{
public:
    Library(StorageType /* storage */) { }

    std::vector<Entry> entries() const { return {}; }
};

};
