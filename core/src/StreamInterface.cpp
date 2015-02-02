#include "titan/core/StreamInterface.hpp"

namespace titan
{

std::ostream& operator<<(std::ostream& stream, const StreamInterface& streamInterface)
{
    stream<<streamInterface.toString();
    return stream;
}

}
