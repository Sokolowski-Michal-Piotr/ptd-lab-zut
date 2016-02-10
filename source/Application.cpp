#include "Application.hpp"

Application& Application::GetInstance()
{
    static Application instance;
    return instance;
}

void Application::Add(Plotable& item)
{
    plots.push_back(&item);
    ApplyStyle();
}

void Application::SetStyle(Style style)
{
    this->style = style;
    ApplyStyle();
}

void Application::SetOffset(float offset)
{
    this->offset = offset;
}

void Application::Run(int fps)
{
    int interval = 1.0 / fps * 1000;
    glutTimerFunc(interval, UpdateFunc, interval);
    glutMainLoop();
}

void Application::Setup(int& argc, char** argv, 
                        int width, int height, const std::string& title)
{
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutCreateWindow(title.c_str());
    glutDisplayFunc(DisplayFunc);
    glutReshapeFunc(ReshapeFunc);
    glutKeyboardFunc(KeyboardFunc);
}

void Application::ApplyStyle()
{
    int rows, cols;

    switch (style)
    {
    case Style::Square:
        cols = (int)ceil(sqrt(plots.size()));
        rows = (int)ceil(plots.size() / (float)cols);
        break;
    case Style::Rows:
        cols = 1;
        rows = plots.size();
        break;
    case Style::Cols:
        cols = plots.size();
        rows = 1;
        break;
    case Style::TwoCols:
        cols = 2;
        rows = (int)ceil(plots.size() / 2.0f);
        break;
    case Style::Manual:
        return;
    }

    for (size_t i = 0; i < plots.size(); i++)
        plots[i]->SetLayout(rows, cols, i + 1);
}

void Application::Display()
{
    for (auto p : plots)
    {
        p->Update();
        auto l = p->GetLayout();
        subplot(l.rows, l.cols, l.index);
        plot(p->GetX(), p->GetY());
        color(p->GetColor());
        title(p->GetTitle());
    }
}

void Application::Keyboard(unsigned char key, int x, int y)
{
    static char state = 0;
    static double value = 0.1;

    if (key >= '1' && key <= '9' && key - '0' <= plots.size())
        current = plots[key - '0' - 1];
    else if (state == 'i')
        if (key == '=')
            value += 0.01;
        else if (key == '-')
            value -= 0.01;
        else
            state = key;
    else if (key == '-')
        current->args[state] -= value;
    else if (key == '=')
        current->args[state] += value;
    else
        state = key;

    if (!current)
        current = plots[0];
    std::cout << "Key state: " << state << " " << (int)state << "\n"
              << "Increment value: " << value << "\n"
              << "Current index: "
              << std::find(plots.begin(), plots.end(), current) -
                 plots.begin() + 1 << "\n";
    for (auto &x : current->args)
        std::cout << x.first << " = " << x.second << "\n";
    std::cout << std::endl;
}

void Application::UpdateFunc(int interval)
{
    glutTimerFunc(interval, UpdateFunc, interval);
    glutPostRedisplay();
}

void Application::DisplayFunc()
{
    GetInstance().display();
}

void Application::ReshapeFunc(int w, int h)
{
    GetInstance().reshape(w, h);
}

void Application::KeyboardFunc(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(EXIT_SUCCESS);
    GetInstance().Keyboard(key, x, y);
}
