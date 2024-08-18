#include <memory>
#include <taglab/library.h>

#include "storage/sqlite.h"

using namespace taglab;

Library::Library(std::unique_ptr<Storage> storage)
    : storage_{std::move(storage)}
{
}

void Library::addLocation(Location const &location)
{
    storage_->addLocation(location);
}

void Library::scanLocations()
{
}

std::vector<Entry> Library::entries() const
{
    return storage_->entries();
}

std::vector<Location> Library::locations() const
{
    return storage_->locations();
}

Library Library::makeWithDbStorage(std::filesystem::path const &path)
{
    return Library{std::make_unique<storage::SQLiteStorage>(storage::SQLiteStorage{path})};
}

Library Library::makeWithInMemoryStorage()
{
    return Library{std::make_unique<storage::SQLiteStorage>(storage::SQLiteStorage::inMemory())};
}
