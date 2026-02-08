#include <iostream>
#include <string>

class Numbers
{
private:
    int m_firstInteger;
    int m_secondInteger;

public:
    void setIntegers(int firstInt, int secondInt)
    {
        m_firstInteger = firstInt;
        m_secondInteger = secondInt;
    }

    void printInfo()
    {
        std::cout << "First Integer: " << m_firstInteger << "\n"
            << "Second Integer: " << m_secondInteger << "\n";
    }
};

class Ball
{
private:
    std::string m_color = "Red";
    double m_radius = 20.0;

public:
    Ball() = default;

	Ball(const std::string& color) : m_color(color) {}

    Ball(double radius) : m_radius(radius) {}

    Ball(double radius, const std::string& color) : m_radius(radius), m_color(color) {}
};

int main()
{
    Numbers nums;

    nums.setIntegers(10, 20);
    nums.printInfo();

    Ball defaultBall;
    Ball blueBall("Blue");
    Ball smallBall(10.0);
    Ball customBall(15.0, "Pink");  
}