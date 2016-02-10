#include "DFT.hpp"

DFT::DFT(const Plotable& input)
    : input(input)
    , spectrum(input.GetSize())
    , Plotable(input.GetSize() / 2)
{

}

void DFT::Update()
{
    const size_t N = input.GetSize();
    for (size_t i = 0; i < N; i++)
    {
        spectrum[i] = 0;
        for (size_t j = 0; j < N; j++)
            spectrum[i] += input[j] * exp(std::complex<double>(0.0, -2 * M_PI * i * j / N));
    }

    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = i;
        y[i] = std::abs(spectrum[i]);
    }
}

const std::vector<std::complex<double>>& DFT::GetSpectrum() const
{
    return spectrum;
}