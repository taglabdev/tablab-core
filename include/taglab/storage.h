#pragma once

#include <vector>

#include <taglab/entry.h>

namespace taglab {

class Storage
{
public:
    virtual ~Storage() = default;

    virtual std::vector<Entry> entries() const = 0;
    virtual void addEntries(std::vector<Entry> const &entries) = 0;
};

};
