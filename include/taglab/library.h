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

    /** temporarily synchronous for ease of implementation */
    void scanLocations();

    std::vector<Entry> entries() const;
    std::vector<Location> locations() const;

    static Library makeWithDbStorage(std::filesystem::path const &path);
    static Library makeWithInMemoryStorage();

private:
    std::unique_ptr<Storage> storage_;
};

};
