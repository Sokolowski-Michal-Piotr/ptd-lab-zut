#include "FFT.hpp"

typedef std::complex<double> complex;

FFT::FFT(const Plotable& input)
    : DFT(input)
{

}

void FFT::Update()
{
    for (size_t i = 0; i < spectrum.size(); i++)
        spectrum[i] = complex(input[i]);
    Recursion(spectrum);

    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = i;
        y[i] = std::abs(spectrum[i]);
    }
}

void FFT::Recursion(std::vector<complex>& data)
{
    const size_t size = data.size();
    if (size < 2) return;

    std::vector<complex> even(size / 2);
    std::vector<complex> odd(size / 2);

    for (size_t i = 0; i < size / 2; i++)
    {
        even[i] = data[i * 2];
        odd[i] = data[i * 2 + 1];
    }

    Recursion(even);
    Recursion(odd);

    for (size_t i = 0; i < size / 2; i++)
    {
        complex t = odd[i] * std::exp(complex(0.0, -2 * M_PI * i / size));
        data[i] = even[i] + t;
        data[i + size / 2] = even[i] - t;
    }
}
