#ifndef PM_INCLUDED
#define PM_INCLUDED

#include "Modulation.hpp"

class PM : public Modulation
{
public:
    PM(const Sinus& baseband, const Sinus& carrier, double factor = 1.0);

protected:
    void Update() override;
};

#endif //PM_INCLUDED
