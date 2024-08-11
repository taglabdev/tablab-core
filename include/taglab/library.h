#pragma once

#include <memory>
#include <vector>

#include <taglab/storage.h>
#include <taglab/entry.h>
#include <taglab/location.h>

namespace taglab {

class Library
{
public:
    Library(std::unique_ptr<Storage> storage);

    void addLocation(Location const &location);

    std::vector<Entry> entries() const;
    std::vector<Location> locations() const;

private:
    std::unique_ptr<Storage> storage_;
};

};
