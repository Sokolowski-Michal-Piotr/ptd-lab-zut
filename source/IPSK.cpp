#include "IPSK.hpp"

#include "Sinus.hpp"
#include "Keying.hpp"

IPSK::IPSK(const Keying& baseband, const Sinus& carrier, double factor)
    : IKeying(baseband, carrier, factor)
{

}
