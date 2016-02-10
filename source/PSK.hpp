#ifndef PSK_INCLUDED
#define PSK_INCLUDED

#include "Keying.hpp"

class PSK : public Keying
{
public:
    PSK(const Binary& baseband, const Sinus& carrier, double factor = M_PI);

protected:
    void Update() override;
};

#endif //PSK_INCLUDED
