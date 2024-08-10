#pragma once

#include <vector>

#include <taglab/entry.h>

namespace taglab {

class Storage
{
    virtual void addEntries(std::vector<Entry> const &entries) = 0;
};

};
