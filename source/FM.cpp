#include "FM.hpp"

#include "Sinus.hpp"

FM::FM(const Sinus& baseband, const Sinus& carrier, double factor)
    : Modulation(baseband, carrier, factor)
{

}

void FM::Update()
{
    x = carrier.GetX();
    double omegac = 2 * M_PI * carrier.freq;
    double omegab = 2 * M_PI * baseband.freq;
    for (size_t i = 0; i < GetSize(); i++)
        y[i] = carrier.amp * sin(omegac * x[i] + carrier.phase
            - factor * (cos(omegab * x[i] + baseband.phase) - 1));
}
