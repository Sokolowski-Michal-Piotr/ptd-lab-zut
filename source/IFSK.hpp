#ifndef IFSK_INCLUDED
#define IFSK_INCLUDED

#include "IKeying.hpp"

class IFSK : public IKeying
{
public:
    IFSK(const Keying& baseband, const Sinus& carrier, double factor = 0.0);
};

#endif //IFSK_INCLUDED
