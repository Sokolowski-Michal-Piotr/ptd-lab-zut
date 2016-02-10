#ifndef ASK_INCLUDED
#define ASK_INCLUDED

#include "Keying.hpp"

class ASK : public Keying
{
public:
    ASK(const Binary& baseband, const Sinus& carrier, double factor = 0.0);

protected:
    void Update() override;
};

#endif //ASK_INCLUDED
