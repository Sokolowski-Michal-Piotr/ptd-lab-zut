#include "FSK.hpp"

#include "Sinus.hpp"
#include "Binary.hpp"

FSK::FSK(const Binary& baseband, const Sinus& carrier)
    : Keying(baseband, carrier, 1.0 / baseband.GetBitsCount())
{

}

FSK::FSK(const Binary& baseband, const Sinus& carrier, double factor)
    : Keying(baseband, carrier, factor)
{

}

void FSK::Update()
{
    double omega = 2 * M_PI * carrier.freq;
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = double(i) / GetSize();
        y[i] = carrier.amp * sin(omega * (baseband[i] > 0.8 ? 1.0 : factor) * x[i] + carrier.phase);
    }
}
