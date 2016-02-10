#ifndef KEYING_INCLUDED
#define KEYING_INCLUDED

#include "Plotable.hpp"

class Sinus;
class Binary;

class Keying : public Plotable
{
public:
    size_t GetBitsCount() const;
    size_t GetSamplesPerBit() const;

protected:
    Keying(const Binary& baseband, const Sinus& carrier, double factor);

    const double &factor;
    const Binary &baseband;
    const Sinus &carrier;
};

#endif //KEYING_INCLUDED
