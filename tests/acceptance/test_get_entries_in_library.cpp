#include <vector>

#include <doctest/doctest.h>

#include <taglab/library.h>
#include <taglab/storage/sqlite.h>

#include "../utils.h"

using namespace std;
using namespace taglab;
using namespace taglab::storage;

TEST_CASE("get entries in library")
{
    // ---- Given library with entries
    auto entries = vector<Entry>{{"test/file1"}, {"test/file2"}, {"test/file3"}};
    auto storage = SQLiteStorage::inMemory();
    storage.addEntries(entries);
    auto library = Library{std::move(storage)};

    // ---- When entries retrieved
    auto resultEntries = library.entries();

    // ---- Then return all entries
    CHECK(resultEntries == entries);
}
