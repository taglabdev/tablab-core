#include <taglab/storage/sqlite.h>

#include <SQLiteCpp/Transaction.h>
#include <SQLiteCpp/Statement.h>

#include <format>
#include <numeric>
#include <ranges>

namespace vws = std::ranges::views;
using namespace taglab;
using namespace taglab::storage;

SQLiteStorage::SQLiteStorage(std::string_view path)
    : db_{path, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE}
{
    db_.exec("CREATE TABLE Entry ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
             "path TEXT NOT NULL);");

    db_.exec("CREATE TABLE Location ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT,"
             "name TEXT NOT NULL,"
             "path TEXT NOT NULL);");
}

void SQLiteStorage::addEntries(std::vector<Entry> const &entries)
{
    auto const values = entries | vws::transform([](auto const &entry) {
                            return std::format("('{}')", entry.path.string());
                        });
    auto const valuesString = std::accumulate(
            std::next(std::cbegin(values)), std::cend(values), *std::cbegin(values),
            [](auto const &first, auto const &second) { return format("{},{}", first, second); });
    auto const command = std::format("INSERT INTO Entry (path) VALUES {};", valuesString);
    db_.exec(command);
}

void SQLiteStorage::addLocation(Location const &location)
{
    db_.exec(std::format("INSERT INTO Location (name, path) VALUES ('{}', '{}');", location.name,
                         location.path.string()));
}

std::vector<Entry> SQLiteStorage::entries() const
{
    auto query = SQLite::Statement{db_, "SELECT * FROM Entry"};
    auto entries = std::vector<Entry>{};
    while (query.executeStep()) {
        auto entry = Entry{};
        entry.id = query.getColumn(0);
        entry.path = query.getColumn(1);
        entries.push_back(std::move(entry));
    }
    return entries;
}

std::vector<Location> SQLiteStorage::locations() const
{
    auto query = SQLite::Statement{db_, "SELECT * FROM Location"};
    auto locations = std::vector<Location>{};
    while (query.executeStep()) {
        auto location = Location{};
        location.id = query.getColumn(0);
        location.name = query.getColumn(1).getString();
        location.path = query.getColumn(2);
        locations.push_back(std::move(location));
    }
    return locations;
}

SQLiteStorage SQLiteStorage::inMemory()
{
    return SQLiteStorage(":memory:");
}
