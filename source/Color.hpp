#ifndef COLOR_INCLUDED
#define COLOR_INCLUDED

enum class Color
{
    Black, White,
    Red, Vermilion, Orange, 
    Amber, Yellow, Chartreuse, 
    Green, Teal, Blue, 
    Violet, Purple, Magenta
};

struct Rgb
{
    Rgb(Color color)
    {
        typedef Color C;
        switch (color)
        {
        case C::Black:      *this = { 0.000f, 0.000f, 0.000f }; break;
        case C::White:      *this = { 1.000f, 1.000f, 1.000f }; break;
        case C::Red:        *this = { 0.949f, 0.121f, 0.094f }; break;
        case C::Vermilion:  *this = { 0.949f, 0.357f, 0.141f }; break;
        case C::Orange:     *this = { 0.949f, 0.553f, 0.094f }; break;
        case C::Amber:      *this = { 1.000f, 0.749f, 0.000f }; break;
        case C::Yellow:     *this = { 0.847f, 0.902f, 0.090f }; break;
        case C::Chartreuse: *this = { 0.573f, 0.749f, 0.075f }; break;
        case C::Green:      *this = { 0.086f, 0.851f, 0.173f }; break;
        case C::Teal:       *this = { 0.129f, 0.573f, 0.851f }; break;
        case C::Blue:       *this = { 0.129f, 0.129f, 0.851f }; break;
        case C::Violet:     *this = { 0.463f, 0.129f, 0.851f }; break;
        case C::Purple:     *this = { 0.608f, 0.129f, 0.851f }; break;
        case C::Magenta:    *this = { 0.851f, 0.129f, 0.561f }; break;
        }
    }

    Rgb(float r, float g, float b) : r(r), g(g), b(b) {}

    float r, g, b;
};

#endif //COLOR_INCLUDED
