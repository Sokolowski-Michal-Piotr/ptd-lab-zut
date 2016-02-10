#ifndef SINUS_INCLUDED
#define SINUS_INCLUDED

#include "Plotable.hpp"

class Sinus : public Plotable
{
public:
    Sinus(int samples, 
          double amp = 1.0, double freq = 1.0, double phase = 0.0);

    const double &amp, &freq, &phase;

protected:
    void Update() override;
};

#endif //SINUS_INCLUDED
