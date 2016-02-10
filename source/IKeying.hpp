#ifndef IKEYING_INCLUDED
#define IKEYING_INCLUDED

#include "Plotable.hpp"

class Sinus;
class Keying;

class IKeying : public Plotable
{
public:
    IKeying(const Keying& baseband, const Sinus& carrier, double factor = 0.0);

    void Update() override;

    const double &factor;
    const double &enabled;

    const Sinus &carrier;
    const Keying &baseband;
};

#endif //IKEYING_INCLUDED
