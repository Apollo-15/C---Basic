#include <iostream>
#include <string>


struct Grades
{
    unsigned int gMath = 0;
    unsigned int gChemistry = 0;
    unsigned int gPhysics = 0;
};

struct Student
{
    std::string firstName;
    std::string birthdayDate;
    Grades* pGrades = nullptr;
};

int main(int argc, char *argv[])
{
    // int x;
    // int* p = &x;

    // std::cout << "Enter a number: ";
    // std::cin >> *p;

    // std::cout << "Through the pointer: " << *p << "\n";



    /*Student max;  
    max.firstName = "Max";
    max.birthdayDate = "6/27/2008";

    Grades grades;
    grades.gMath = 97;
    grades.gChemistry = 74;
    grades.gPhysics = 83;

    max.pGrades = &grades;*/

    Student* pMax = new Student;
    pMax->pGrades = new Grades;

    pMax->firstName = "Max";
    pMax->birthdayDate = "6/27/2008";
    pMax->pGrades->gMath = 5;
    pMax->pGrades->gChemistry = 4;
    pMax->pGrades->gPhysics = 4;

    return 0;
}