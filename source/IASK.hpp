#ifndef IASK_INCLUDED
#define IASK_INCLUDED

#include "IKeying.hpp"

class IASK : public IKeying
{
public:
    IASK(const Keying& baseband, const Sinus& carrier, double factor = 0.0);
};

#endif //IASK_INCLUDED
