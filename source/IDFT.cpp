#include "IDFT.hpp"

#include "DFT.hpp"

IDFT::IDFT(const DFT& input)
    : spectrum(input.GetSpectrum())
    , Plotable(input.GetSpectrum().size())
{

}

void IDFT::Update()
{
    for (size_t i = 0; i < GetSize(); i++)
    {
        std::complex<double> sum;
        for (size_t j = 0; j < GetSize(); j++)
            sum += spectrum[j] * exp(std::complex<double>(0.0, 2 * M_PI * i * j / GetSize()));
        sum /= GetSize();

        x[i] = (double)i / GetSize();
        y[i] = sum.real();
    }
}
