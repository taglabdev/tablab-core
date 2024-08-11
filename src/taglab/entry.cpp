#include <taglab/entry.h>

using namespace taglab;

bool Entry::operator==(Entry const & /* other */) const
{
    return {};
}

namespace taglab {

std::ostream &operator<<(std::ostream &os, Entry const &entry)
{
    return os << entry.path;
}

};
