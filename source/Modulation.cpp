#include "Modulation.hpp"

#include "Sinus.hpp"

Modulation::Modulation(const Sinus& baseband, const Sinus& carrier, double factor)
    : baseband(baseband)
    , carrier(carrier)
    , factor(args['k'])
    , Plotable(carrier.GetSize())
{
    args['k'] = factor;
}
