#ifndef FM_INCLUDED
#define FM_INCLUDED

#include "Modulation.hpp"

class FM : public Modulation
{
public:
    FM(const Sinus& baseband, const Sinus& carrier, double factor = 1.0);

protected:
    void Update() override;
};

#endif //FM_INCLUDED
