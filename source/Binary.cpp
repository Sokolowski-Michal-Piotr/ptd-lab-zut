#include "Binary.hpp"

Binary::Binary(size_t samples, size_t bits)
    : bits(bits)
    , samplesPerBit(samples / bits)
    , Plotable(samples)
{
    //if (samples % bits)
    //    throw std::invalid_argument("division with remainder");
}

Binary::Binary(size_t samples, std::string data)
    : Binary(samples, data.size())
{
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = (double)i / GetSize();
        y[i] = data[i / samplesPerBit] - '0';
    }
}

Binary::Binary(size_t samples, unsigned long long data, size_t bits)
    : Binary(samples, bits)
{
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = (double)i / GetSize();
        y[i] = data & 1 << bits - i / samplesPerBit - 1 ? 1 : 0;
    }
}

Binary::Binary(size_t samples, uint8_t *data, size_t bits)
    : Binary(samples, bits)
{
    size_t bitrange = samples / bits;
    for (size_t i = 0; i < GetSize(); i++)
    {
        x[i] = (double)i / GetSize();
        y[i] = data[i / (8 * samplesPerBit)] 
             & 1 << 8 - (i / samplesPerBit % 8) - 1 ? 1 : 0;
    }
}

size_t Binary::GetBitsCount() const
{
    return bits;
}

size_t Binary::GetSamplesPerBit() const
{
    return samplesPerBit;
}

void Binary::Update()
{

}
