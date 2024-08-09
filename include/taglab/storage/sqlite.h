#pragma once

#include <vector>
#include <string_view>
#include <numeric>
#include <ranges>
#include <format>

#include <SQLiteCpp/Database.h>

#include <taglab/entry.h>

namespace taglab::storage {

class SQLiteStorage
{
public:
    SQLiteStorage(std::string_view path);

    void addEntries(std::ranges::range auto const &entries)
    {
        using namespace std;
        auto const values = entries | views::transform([](auto const &entry) {
                                return format("('{}')", entry.path.string());
                            });
        auto const valuesString = accumulate(next(cbegin(values)), cend(values), *cbegin(values),
                                             [](auto const &first, auto const &second) {
                                                 return format("{},{}", first, second);
                                             });
        auto const command = format("INSERT INTO Entry (path) VALUES {};", valuesString);
        db_.exec(command);
    }

    static SQLiteStorage inMemory();

private:
    SQLite::Database db_;
};

};
