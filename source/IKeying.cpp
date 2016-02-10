#include "IKeying.hpp"

#include "Sinus.hpp"
#include "Keying.hpp"

IKeying::IKeying(const Keying& baseband, const Sinus& carrier, double factor)
    : baseband(baseband)
    , carrier(carrier)
    , factor(args['k'])
    , enabled(args['e'])
    , Plotable(carrier.GetSize())
{
    args['e'] = 1E-6;
    args['k'] = factor;
}

void IKeying::Update()
{
    size_t bits = baseband.GetBitsCount();
    size_t samplesPerBit = baseband.GetSamplesPerBit();

    double threshold = factor * (carrier.amp * carrier.amp / 2
        * baseband.GetSamplesPerBit());

    double sum;
    for (size_t i = 0; i < GetSize(); i++)
    {
        if (i % samplesPerBit == 0)
            sum = 0.0;
        sum += baseband[i] * carrier[i];

        x[i] = (double)i / GetSize();
        y[i] = sum > threshold ? 1 : 0;

        if (enabled < 0.0)
            y[i] = sum;
    }
}
