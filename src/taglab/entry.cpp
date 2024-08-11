#include <taglab/entry.h>

using namespace taglab;

namespace taglab {

std::ostream &operator<<(std::ostream &os, Entry const &entry)
{
    return os << entry.path;
}

};
