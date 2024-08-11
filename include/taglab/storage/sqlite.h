#pragma once

#include <vector>
#include <string_view>

#include <SQLiteCpp/Database.h>

#include <taglab/storage.h>
#include <taglab/entry.h>

namespace taglab::storage {

class SQLiteStorage : public Storage
{
public:
    SQLiteStorage(std::string_view path);

    void addEntries(std::vector<Entry> const &entries) override;

    std::vector<Entry> entries() const override;

    static SQLiteStorage inMemory();

private:
    SQLite::Database db_;
};

};
