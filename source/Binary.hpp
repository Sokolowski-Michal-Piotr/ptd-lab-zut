#ifndef BINARY_INCLUDED
#define BINARY_INCLUDED

#include "Plotable.hpp"

class Binary : public Plotable
{
public:
    Binary(size_t samples, std::string data);
    Binary(size_t samples, uint8_t *data, size_t bits);
    Binary(size_t samples, unsigned long long data, size_t bits);

    size_t GetBitsCount() const;
    size_t GetSamplesPerBit() const;

protected:
    Binary(size_t samples, size_t bits);

    void Update() override;

    size_t bits;
    size_t samplesPerBit;
};

#endif //BINARY_INCLUDED
