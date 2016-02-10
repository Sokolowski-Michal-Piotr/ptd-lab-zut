#ifndef IDFT_INCLUDED
#define IDFT_INCLUDED

#include <vector>
#include <complex>

#include "Plotable.hpp"

class DFT;

class IDFT : public Plotable
{
public:
    IDFT(const DFT& input);

protected:
    void Update() override;

    const std::vector<std::complex<double>>& spectrum;
};

#endif //IDFT_INCLUDED
