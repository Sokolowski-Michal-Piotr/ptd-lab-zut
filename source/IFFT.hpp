#ifndef IFFT_INCLUDED
#define IFFT_INCLUDED

#include <vector>
#include <complex>

#include "IDFT.hpp"

class DFT;

class IFFT : public IDFT
{
public:
    IFFT(const DFT& input);

protected:
    void Update() override;

private:
    void Recursion(std::vector<std::complex<double>>& data);
};

#endif //IFFT_INCLUDED
