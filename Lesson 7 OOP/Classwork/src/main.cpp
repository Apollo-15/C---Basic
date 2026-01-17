#include <iostream>
#include <string>

class Student
{
private:
    std::string m_name;
    int m_age;

    // bool isValidScore(int value);
    // void sortMoney();

public:
//Setters
    void setName(std::string n);
    void setAge(int a);
//Getters
    std::string getName();
    int getAge();

    
    void printInfo();

    // void setA(int value);
    // int getB();

    // bool receiveMoney(int amount);
    // int endInteraction();
};

int main(int argc, char* argv[])
{
    // Matrix Array
    /*
    int* pArray = new int[10];
    delete[] pArray;
    pArray = nullptr;

    int** pMatrix = new int* [5];

    for (size_t i = 0; i < 5; ++i)
    {
        pMatrix[i] = new int[10];
    }

    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j = 10; ++j)
        {
            pMatrix[i][j] = i + j;
        }
    }

    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j  = 0; j < 10; ++j)
        {
            std::cout << pMatrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    for (size_t i = 0; i < 5; ++i)
    {
        delete[] pMatrix[i];
    }

    delete[] pMatrix;
    pMatrix = nullptr;
    */

    Student student;

    student.setAge(17);
    student.setName("Brian Johnson");

    student.printInfo();

    return 0;
}

void Student::setName(std::string n)
{
    m_name = n;
}

void Student::setAge(int a)
{
    m_age = a;
}

std::string Student::getName()
{
    return m_name;
}

int Student::getAge()
{
    return m_age;
}

void Student::printInfo()
{
    std::cout << "Student: " << m_name << "\n"
              << "Age: " << m_age << "\n";
}