#include <taglab/storage/sqlite.h>

using namespace std;
using namespace SQLite;
using namespace taglab::storage;

SQLiteStorage::SQLiteStorage(string_view path)
    : db_{path, OPEN_READWRITE | OPEN_CREATE}
{
    db_.exec("CREATE TABLE Entry (id INTEGER PRIMARY KEY AUTOINCREMENT, path VARCHAR(255) NOT "
             "NULL);");
}

SQLiteStorage SQLiteStorage::inMemory()
{
    return SQLiteStorage(":memory:");
}
