#include <iostream>

// struct Student
// {
//     unsigned short int Age = 0;
//     std::string firstName = "";
//     std::string secondName = "";
// };

struct Product
{
    double productPrice = 0.0;
    std::string productName = "";
    int day = 0;
    int month = 0;
    int year = 0;
};

int main(int argc, char *argv[])
{
    // std::cout << "===================TABLE===================\n";
    // std::cout << "int:" << sizeof(int) << "\n";
    // std::cout << "short int:" << sizeof(short int) << "\n";
    // std::cout << "long int:" << sizeof(long int) << "\n";
    // std::cout << "long:" << sizeof(long) << "\n";
    // std::cout << "long long:" << sizeof(long long) << "\n";
    // std::cout << "float:" << sizeof(float) << "\n";
    // std::cout << "char:" << sizeof(char) << "\n";
    // std::cout << "bool:" << sizeof(bool) << "\n";

    // Student firstStudent;
    // firstStudent.firstName = "David";
    // firstStudent.secondName = "Gilmour";
    // firstStudent.Age = 79;


    // std::cout << "Enter your full name: ";
    // std::cin >> firstStudent.firstName;
    // std::cin >> firstStudent.secondName;

    // std::cout << "===================STUDENT=CARD===================\n";
    // std::cout << "Full Name: " << firstStudent.firstName << " " << firstStudent.secondName << "\n";
    // std::cout << "Age: " << firstStudent.Age << "\n";

    Product firstProduct;
    std::cout << "Enter product name: ";
    std::cin >> firstProduct.productName;
    std::cout << "Enter " << firstProduct.productName << "'s price: ";
    std::cin >> firstProduct.productPrice;
    std::cout << "Enter expiration date: ";
    std::cin >> firstProduct.day >> firstProduct.month >> firstProduct.year;

    std::cout << "Your product's name is: " << firstProduct.productName << "\n";
    std::cout << "Your product's price is: $" << firstProduct.productPrice << "\n";
    std::cout << "Your product's expiration date is: " << firstProduct.day << "/" << firstProduct.month << "/" << firstProduct.year << "\n";

    return 0;
}