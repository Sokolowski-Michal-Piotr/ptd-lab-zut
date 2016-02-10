#include <cstdlib>

#include "AM.hpp"
#include "PM.hpp"
#include "FM.hpp"
#include "ASK.hpp"
#include "FSK.hpp"
#include "PSK.hpp"
#include "DFT.hpp"
#include "FFT.hpp"
#include "IDFT.hpp"
#include "IFFT.hpp"
#include "IASK.hpp"
#include "IFSK.hpp"
#include "IPSK.hpp"
#include "Sinus.hpp"
#include "Binary.hpp"
#include "Hamming.hpp"
#include "Application.hpp"

int main(int argc, char* argv[])
{
    srand(time(0));
    typedef Application::Style Style;

    Application &app = Application::GetInstance();

    Hamming hamming(7, 4);
    
    uint64_t message = 0b0110;
    uint64_t encoded = hamming.Encode(message);
    
    uint64_t errorMask = 1 << rand() % hamming.GetN();
    uint64_t transmitted = encoded ^ errorMask;

    uint64_t corrected = hamming.Correct(transmitted);

    uint64_t decoded = hamming.Decode(transmitted);

    Binary p1(512, message, hamming.GetK());
    Binary p2(512, encoded, hamming.GetN());
    Binary p3(512, transmitted, hamming.GetN());
    Binary p4(512, corrected, hamming.GetN());
    Binary p5(512, decoded, hamming.GetK());

    p1.SetTitle("Message to send");
    p2.SetTitle("Encoded message");
    p3.SetTitle("Transmitted message");
    p4.SetTitle("Corrected message");
    p5.SetTitle("Decoded message");

    app.SetStyle(Style::Manual);
    p1.SetLayout(2, 2, 1);
    p5.SetLayout(2, 2, 3);
    p2.SetLayout(3, 2, 2);
    p3.SetLayout(3, 2, 4);
    p4.SetLayout(3, 2, 6);

    p1.SetColor(Color::Black);
    p2.SetColor(Color::Green);
    p3.SetColor(Color::Red);
    p4.SetColor(Color::Green);
    p5.SetColor(Color::Black);

    app.Add(p1);
    app.Add(p2);
    app.Add(p3);
    app.Add(p4);
    app.Add(p5);

    app.Setup(argc, argv, 900, 600, "PTD");
    app.Run(60);

    return EXIT_SUCCESS;
}
