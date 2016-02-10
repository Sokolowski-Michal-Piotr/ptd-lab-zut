#include "Hamming.hpp"

#include <cmath>
#include <vector>
#include <cstdint>
#include <stdexcept>

static const uint64_t PARITY_MASK[] = {
    0b0101010101010101010101010101010101010101010101010101010101010101,
    0b0110011001100110011001100110011001100110011001100110011001100110,
    0b0111100001111000011110000111100001111000011110000111100001111000,
    0b0111111110000000011111111000000001111111100000000111111110000000,
    0b0111111111111111100000000000000001111111111111111000000000000000,
    0b0111111111111111111111111111111110000000000000000000000000000000
};

Hamming::Hamming(int n, int k)
    : n(n)
    , k(k)
    , m(n-k)
{
    
}

int Hamming::Distance(uint64_t data)
{
    int count = 0;

    while (data)
    {
        count++;
        data &= data - 1;
    }

    return count;
}

uint8_t Hamming::Detect(uint64_t data)
{
    uint8_t errorPos = 0;

    for (int i = 0; i < m; i++)
        errorPos |= (Distance(data & PARITY_MASK[i]) & 1) << i;

    return errorPos;
}

uint64_t Hamming::Correct(uint64_t data)
{
    return data ^ 1 << Detect(data) - 1;
}

uint64_t Hamming::Encode(uint64_t msg)
{
    uint64_t result = 0;

    for (size_t i = 1, d_mask = 1; i <= n; i++)
    {
        if ((i & i - 1) == 0) continue;

        if (msg & d_mask)
            result |= 1 << i - 1;
        d_mask <<= 1;
    }

    for (size_t i = 0; i < m; i++)
        result |= (Distance(result & PARITY_MASK[i]) & 1) << (1 << i) - 1;

    return result;
}

uint64_t Hamming::Decode(uint64_t msg, bool correct)
{
    uint64_t result = 0;

    if (correct)
        msg = Correct(msg);

    for (size_t i = 1, d_bit = 0; i <= n; i++)
    {
        if ((i & i - 1) == 0) continue;

        if (msg & 1 << i - 1)
            result |= 1 << d_bit;
        d_bit++;
    }

    return result;
}

bool Hamming::IsCorrupted(uint64_t msg) 
{
    return Detect(msg) != 0;
}

int Hamming::GetN() 
{
    return n;
}

int Hamming::GetK()
{
    return k;
}

int Hamming::GetM()
{
    return m;
}