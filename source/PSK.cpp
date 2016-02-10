#include "PSK.hpp"

#include "Sinus.hpp"
#include "Binary.hpp"

PSK::PSK(const Binary& baseband, const Sinus& carrier, double factor)
    : Keying(baseband, carrier, factor)
{

}

void PSK::Update()
{
    double omega = 2 * M_PI * carrier.freq;
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = double(i) / GetSize();
        y[i] = carrier.amp * sin(omega * x[i] + carrier.phase 
             + M_PI * baseband[i] + factor);
    }
}
