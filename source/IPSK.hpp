#ifndef IPSK_INCLUDED
#define IPSK_INCLUDED

#include "IKeying.hpp"

class IPSK : public IKeying
{
public:
    IPSK(const Keying& baseband, const Sinus& carrier, double factor = 0.0);
};

#endif //IPSK_INCLUDED
