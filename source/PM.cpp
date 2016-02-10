#include "PM.hpp"

#include "Sinus.hpp"

PM::PM(const Sinus& baseband, const Sinus& carrier, double factor)
    : Modulation(baseband, carrier, factor)
{

}

void PM::Update()
{
    x = carrier.GetX();
    double omega = 2 * M_PI * carrier.freq;
    for (size_t i = 0; i < GetSize(); i++)
        y[i] = carrier.amp * sin(omega * x[i] + carrier.phase
            + factor * baseband[i]);
}
