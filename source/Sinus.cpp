#include "Sinus.hpp"

Sinus::Sinus(int samples, double amp, double freq, double phase)
    : amp(args['a'])
    , freq(args['f'])
    , phase(args['p'])
    , Plotable(samples)
{
    args['a'] = amp;
    args['f'] = freq;
    args['p'] = phase;
}

void Sinus::Update()
{
    double omega = 2 * M_PI * freq;
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = (double)i / GetSize();
        y[i] = amp * sin(omega * x[i] + phase);
    }
}
