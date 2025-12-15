#include <iostream>

int main(int argc, char *argv[])
{
    int age;
    int zipcode;

    std::cout << "Please input your age: " << std::endl;
    std::cin >> age;
    std::cout << "Please input your zipcode: " << std::endl;
    std::cin >> zipcode;
    std::cout << "Your age is " << age << " and your zipcode is " << zipcode << "." << std::endl;

    return 0;
}
