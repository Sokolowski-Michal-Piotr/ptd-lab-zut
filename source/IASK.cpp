#include "IASK.hpp"

#include "Sinus.hpp"
#include "Keying.hpp"

IASK::IASK(const Keying& baseband, const Sinus& carrier, double factor)
    : IKeying(baseband, carrier, factor)
{

}
