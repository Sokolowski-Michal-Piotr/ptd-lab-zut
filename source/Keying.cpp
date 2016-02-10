#include "Keying.hpp"

#include "Sinus.hpp"
#include "Binary.hpp"

Keying::Keying(const Binary& baseband, const Sinus& carrier, double factor)
    : baseband(baseband)
    , carrier(carrier)
    , factor(args['k'])
    , Plotable(carrier.GetSize())
{
    args['k'] = factor;
}

size_t Keying::GetBitsCount() const
{
    return baseband.GetBitsCount();
}

size_t Keying::GetSamplesPerBit() const
{
    return baseband.GetSamplesPerBit();
}
