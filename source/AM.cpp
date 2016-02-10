#include "AM.hpp"

#include "Sinus.hpp"

AM::AM(const Sinus& baseband, const Sinus& carrier, double factor)
    : Modulation(baseband, carrier, factor)
{

}

void AM::Update()
{
    x = carrier.GetX();
    for (size_t i = 0; i < GetSize(); i++)
        y[i] = (1 + factor * baseband[i]) * carrier[i];
}
