#include "ASK.hpp"

#include "Sinus.hpp"
#include "Binary.hpp"

ASK::ASK(const Binary& baseband, const Sinus& carrier, double factor)
    : Keying(baseband, carrier, factor)
{
    
}

void ASK::Update()
{
    double omega = 2 * M_PI * carrier.freq;
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = double(i) / GetSize();
        y[i] = (baseband[i] > 0.8 ? 1.0 : factor) * carrier[i];
    }
}
