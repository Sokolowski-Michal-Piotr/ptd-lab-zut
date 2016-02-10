#ifndef FFT_INCLUDED
#define FFT_INCLUDED

#include <vector>
#include <complex>

#include "DFT.hpp"

class FFT : public DFT
{
public:
    FFT(const Plotable& input);

protected:
    void Update() override;

private:
    void Recursion(std::vector<std::complex<double>>& data);
};

#endif //FFT_INCLUDED
