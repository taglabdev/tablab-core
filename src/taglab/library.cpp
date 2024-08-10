#include <taglab/library.h>

using namespace taglab;

Library::Library(std::unique_ptr<Storage> storage)
    : storage_{std::move(storage)}
{
}

std::vector<Entry> Library::entries() const
{
    return storage_->entries();
}
