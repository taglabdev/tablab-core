#include <algorithm>
#include <memory>
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
    auto storage = unique_ptr<SQLiteStorage>{new SQLiteStorage{SQLiteStorage::inMemory()}};
    storage->addEntries(entries);
    auto library = Library{std::move(storage)};

    // ---- When entries retrieved
    auto resultEntries = library.entries();

    // ---- Then return all entries
    CHECK(std::ranges::equal(entries, resultEntries, [](auto const &exp, auto const &act) {
        return exp.path == act.path;
    }));
}
