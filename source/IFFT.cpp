#include "IFFT.hpp"

#include "DFT.hpp"
#include "FFT.hpp"

typedef std::complex<double> complex;

IFFT::IFFT(const DFT& input)
    : IDFT(input)
{

}

void IFFT::Update()
{
    std::vector<complex> data(spectrum);
    Recursion(data);
    for (auto &d : data)
        d /= GetSize();

    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = (double)i / GetSize();
        y[i] = data[i].real();
    }
}

void IFFT::Recursion(std::vector<complex>& data)
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
        complex t = odd[i] * std::exp(complex(0.0, 2 * M_PI * i / size));
        data[i] = even[i] + t;
        data[i + size / 2] = even[i] - t;
    }
}
