#include <algorithm>
#include <filesystem>

#include <doctest/doctest.h>

#include <fstream>
#include <taglab/library.h>

#include "utils.h"

using namespace std;
using namespace taglab;
namespace fs = filesystem;
namespace rngs = ranges;

auto const LIBRARY_DIR = fs::path(TEST_TEMP_DIR) / "somedir/testloc";

auto operator==(Location const &exp, Location const &act) -> bool
{
    return exp.name == act.name && exp.path == act.path;
};

auto operator==(Entry const &exp, Entry const &act) -> bool
{
    return exp.path == act.path;
};

void createEntriesInFilesystem(vector<Entry> const &entries)
{
    rngs::for_each(
            entries,
            [](auto const &p) {
                fs::create_directories(p.parent_path());
                ofstream{p};
            },
            [&](auto const &e) { return LIBRARY_DIR / e.path; });
}
void clearTestTempDir()
{
    for (auto const &entry : fs::directory_iterator{TEST_TEMP_DIR}) {
        fs::remove_all(entry.path());
    }
}

TEST_CASE("location and entries")
{
    clearTestTempDir();

    auto library = Library::makeWithInMemoryStorage();

    auto const location = Location{"testloc", LIBRARY_DIR};
    library.addLocation(location);

    SUBCASE("retrieve locations")
    {
        auto const locations = library.locations();
        REQUIRE(locations.size() == 1);
        CHECK(location == locations.front());
    }

    SUBCASE("scan location for entries")
    {
        auto const entries = vector<Entry>{"entry1", "innerdir/entry2"};
        createEntriesInFilesystem(entries);

        library.scanLocations();

        auto const resultEntries = library.entries();
        REQUIRE(resultEntries.size() == 2);
        CHECK(resultEntries.at(0) == Entry{"entry1"});
        CHECK(resultEntries.at(1) == Entry{"innerdir/entry2"});
    }
}
