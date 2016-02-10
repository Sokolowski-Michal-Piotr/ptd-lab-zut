#ifndef MODULATION_INCLUDED
#define MODULATION_INCLUDED

#include "Plotable.hpp"

class Sinus;

class Modulation : public Plotable
{
protected:
    Modulation(const Sinus& baseband, const Sinus& carrier, double factor);

    const double &factor;
    const Sinus &baseband, &carrier;
};

#endif //MODULATION_INCLUDED
