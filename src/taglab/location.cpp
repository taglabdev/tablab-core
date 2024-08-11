#include <taglab/location.h>

#include <format>

namespace taglab {

std::ostream &operator<<(std::ostream &os, Location const &location)
{
    return os << std::format("Location(name: {}, path: {})", location.name, location.path.string());
}

};
