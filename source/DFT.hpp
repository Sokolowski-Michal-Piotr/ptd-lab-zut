#ifndef DFT_INCLUDED
#define DFT_INCLUDED

#include <vector>
#include <complex>

#include "Plotable.hpp"

class DFT : public Plotable
{
public:
    DFT(const Plotable& input);
    
    const std::vector<std::complex<double>>& GetSpectrum() const;

protected:
    void Update() override;

    const Plotable& input;
    std::vector<std::complex<double>> spectrum;
};

#endif //DFT_INCLUDED
