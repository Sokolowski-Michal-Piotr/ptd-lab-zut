#ifndef APP_INCLUDED
#define APP_INCLUDED

#include <matplotpp.h>

#include "Plotable.hpp"

class Application : protected MatPlot
{
public:
    enum class Style { Square, Rows, Cols, TwoCols, Manual };

    static Application& GetInstance();

    void Add(Plotable& item);
    void SetStyle(Style style);
    void SetOffset(float offset);

    void Run(int fps);
    void Setup(int& argc, char** argv, 
               int width, int height, const std::string& title);

private:
    Application() {}
    Application(const Application&) {}
    Application& operator=(const Application&) {}
    ~Application() {}

    void ApplyStyle();

    void Display() override;
    void Keyboard(unsigned char key, int x, int y) override;

    static void DisplayFunc();
    static void UpdateFunc(int interval);
    static void ReshapeFunc(int w, int h);
    static void KeyboardFunc(unsigned char key, int x, int y);

    Style style;
    Plotable *current;
    std::vector<Plotable*> plots;
};

#endif //APP_INCLUDED
