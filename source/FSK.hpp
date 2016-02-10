#ifndef FSK_INCLUDED
#define FSK_INCLUDED

#include "Keying.hpp"

class FSK : public Keying
{
public:
    FSK(const Binary& baseband, const Sinus& carrier);
    FSK(const Binary& baseband, const Sinus& carrier, double factor);

protected:
    void Update() override;
};

#endif //FSK_INCLUDED
