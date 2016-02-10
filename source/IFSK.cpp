#include "IFSK.hpp"

#include "Sinus.hpp"
#include "Keying.hpp"

IFSK::IFSK(const Keying& baseband, const Sinus& carrier, double factor)
    : IKeying(baseband, carrier, factor)
{

}
