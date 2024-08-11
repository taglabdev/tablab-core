#include <taglab/library.h>

using namespace taglab;

Library::Library(std::unique_ptr<Storage> storage)
    : storage_{std::move(storage)}
{
}

void Library::addLocation(Location const &location)
{
    storage_->addLocation(location);
}

std::vector<Entry> Library::entries() const
{
    return storage_->entries();
}

std::vector<Location> Library::locations() const
{
    return storage_->locations();
}
