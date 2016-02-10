#ifndef AM_INCLUDED
#define AM_INCLUDED

#include "Modulation.hpp"

class AM : public Modulation
{
public:
    AM(const Sinus& baseband, const Sinus& carrier, double factor = 1.0);

protected:
    void Update() override;
};

#endif //AM_INCLUDED
