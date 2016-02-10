#ifndef PLOTABLE_INCLUDED
#define PLOTABLE_INCLUDED

#include <vector>
#include <unordered_map>

#include "Color.hpp"

class Plotable
{
public:
    struct Layout { int rows, cols, index; };

    const std::vector<double>& GetX() const;
    const std::vector<double>& GetY() const;

    const size_t GetSize() const;

    void SetLayout(int rows, int cols, int index);

    const std::string& GetTitle() const;
    void SetTitle(const std::string& title);

    void SetColor(Color color);
    void SetColor(std::string color);
    void SetColor(float r, float g, float b);

    double operator[](int index) const;

protected:
    Plotable(int size);

    virtual void Update() = 0;

    const Layout& GetLayout() const;

    const std::string& GetColor() const
    {
        return color;
    }

    std::vector<double> x;
    std::vector<double> y;
    std::unordered_map<char, double> args;

private:
    Layout layout;
    std::string title;
    std::string color;

    friend class Application;
};

#endif // PLOTABLE_INCLUDED
