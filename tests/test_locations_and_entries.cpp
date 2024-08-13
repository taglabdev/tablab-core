#include <doctest/doctest.h>

#include <taglab/library.h>

#include "utils.h"

using namespace std;
using namespace taglab;

auto operator==(Location const &exp, Location const &act) -> bool
{
    return exp.name == act.name && exp.path == act.path;
};

TEST_CASE("add location and get scanned entries")
{
    // ---- Given library
    auto library = Library::makeWithInMemoryStorage();

    // ---- When location is added
    auto const location = Location{"testloc", "somedir/testloc"};
    library.addLocation(location);

    // ---- Then locations can be retrieved
    auto const locations = library.locations();
    REQUIRE(locations.size() == 1);
    CHECK(location == locations.front());
}
