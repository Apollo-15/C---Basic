#include <iostream>

void Sum(const int& firstNumber, const int& secondNumber, int& result)
{
    result = firstNumber + secondNumber;
    return;
}

int MultiBy(int number, int multiple = 5, int multiple2 = 1, int multiple3 = 10) 
{ 
    return number * multiple; 
}


int main(int argc, char* argv[])
{
    int a = 10;
    int b = 10;
    int res = 0;

    Sum(a, b, res);

    std::cout << "Result: " << res << "\n";

    std::cout << "Result " << MultiBy(100, 5, 1, 100) << "\n";

    return 0;
}