#pragma once

#include <vector>

#include <taglab/entry.h>
#include <taglab/location.h>

namespace taglab {

class Storage
{
public:
    virtual ~Storage() = default;

    virtual void addEntries(std::vector<Entry> const &entries) = 0;
    virtual void addLocation(Location const &location) = 0;

    virtual std::vector<Entry> entries() const = 0;
    virtual std::vector<Location> locations() const = 0;
};

};
