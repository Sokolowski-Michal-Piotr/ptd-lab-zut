#ifndef HAMMING_INCLUDED
#define HAMMING_INCLUDED

#include <cstdint>

class Hamming
{
public:
    Hamming(int n = 7, int k = 4);

    uint64_t Encode(uint64_t msg);
    uint64_t Decode(uint64_t msg, bool correct = true);

    uint64_t Correct(uint64_t data);

    bool IsCorrupted(uint64_t msg);

    int GetN();
    int GetK();
    int GetM();

private:
    int Distance(uint64_t data);

    uint8_t Detect(uint64_t data);

    const int n, k, m;
};

#endif //HAMMING_INCLUDED
