#include <iostream>
#include <vector>
#include <string>

// A
/*
class A
{
private:
    int m_a;
    int m_b;
    int m_c;

public:
    A();
    A(int a, int b, int c);
    A(const A& other);
    A& operator=(const A&) = delete;
    ~A();
};

A::A() : m_a(0), m_b(0), m_c(0)
{
}

A::A(int a, int b, int c)
    : m_a(a), m_b(b), m_c(c)
{
    std::cout << "m_a: " << m_a << "\n";
    std::cout << "m_b: " << m_b << "\n";
    std::cout << "m_c: " << m_c << "\n";
}

A::A(const A& other)
    : m_a(other.m_a), m_b(other.m_b), m_c(other.m_c)
{
}

A::~A()
{
}

// SqlServer

struct Table
{
    long ID = 0;
    std::string strData;
};

enum class EOperation { SELECT = 0,  UPDATE, DELETE, INSERT};

class SqlServer
{
private:
public:
    SqlServer();
    SqlServer(std::string strDatabase);
		
    bool isConnected(std::string strDatabase);
    bool isConnected();
    bool isConnected(std::string, std::string strLogin, std::string strPass);

    bool isQueryExecuted(std::string query);
    bool isQueryExecuted(Table t, EOperation operation);

    void Disconnect();

};

bool isQueryExecuted(Table t, EOperation operation)
{
	{
		switch (operation)
		{
		case EOperation::SELECT:
			{
				
			}
        break;
		case EOperation::UPDATE:
            break;
		case EOperation::INSERT:
            break;
		case EOperation::DELETE:
            break;
        default:
            break;
		}
	}
}
*/

//Task

class Student;

class UniversityProgram {
private:
    std::string yearOfStudy;
    std::string programName;
    std::vector<Student*> students;

public:
    UniversityProgram(const std::string& yearOfStudy, const std::string& programName)
        : yearOfStudy(yearOfStudy), programName(programName) {
    }

    void addStudent(Student* student) { students.push_back(student); }
    std::string getProgramName() const { return programName; }

    void printAllStudents() const;
};

class Student {
private:
    std::string fullName;
    std::string gender;
    std::string dateOfBirth;
    int age;
    UniversityProgram* program = nullptr;

public:
    Student(const std::string& fullName,
        const std::string& gender,
        const std::string& dateOfBirth,
        int age,
        UniversityProgram* program)
        : fullName(fullName), gender(gender), dateOfBirth(dateOfBirth), age(age), program(program) {
    }

    void printStudentInfo() const {
        std::cout << "Student's name: " << fullName << "\n"
            << "Student's gender: " << gender << "\n"
            << "Student's date of birth: " << dateOfBirth << "\n"
            << "Student's age: " << age << "\n";

        if (program != nullptr) {
            std::cout << "Program: " << program->getProgramName() << "\n";
        }
        else {
            std::cout << "Program: None\n";
        }

        std::cout << "\n";
    }
};

void UniversityProgram::printAllStudents() const {
    std::cout << "Program: " << programName << "\n"
        << "Year of study: " << yearOfStudy << "\n"
        << "\n";

    for (auto student : students) {
        student->printStudentInfo();
    }
}

int main() {
    UniversityProgram physicsProgram("1st Year", "Physics");

    Student s1("Kirk Smith", "Male", "07/23/2007", 18, &physicsProgram);
    Student s2("Bob Moore", "Male", "04/16/2008", 19, &physicsProgram);

    physicsProgram.addStudent(&s1);
    physicsProgram.addStudent(&s2);

    physicsProgram.printAllStudents();

    return 0;
}