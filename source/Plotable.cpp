#include "Plotable.hpp"

Plotable::Plotable(int size)
    : x(size)
    , y(size)
{

}

const std::vector<double>& Plotable::GetX() const
{ 
    return x; 
}

const std::vector<double>& Plotable::GetY() const
{ 
    return y;
}

const size_t Plotable::GetSize() const
{
    return x.size();
}

const Plotable::Layout& Plotable::GetLayout() const
{
    return layout;
}

void Plotable::SetLayout(int rows, int cols, int index)
{
    layout.rows = rows;
    layout.cols = cols;
    layout.index = index;
}

const std::string& Plotable::GetTitle() const
{ 
    return title; 
}

void Plotable::SetTitle(const std::string& title)
{ 
    this->title = title; 
}

void Plotable::SetColor(Color color)
{
    Rgb rgb(color);
    SetColor(rgb.r, rgb.g, rgb.b);
}

void Plotable::SetColor(std::string color)
{
    this->color = color;
}

void Plotable::SetColor(float r, float g, float b)
{
    char c[100];
    sprintf(c, "[%f %f %f]", r, g, b);
    color = c;
}

double Plotable::operator[](int index) const
{
    return y[index];
}
