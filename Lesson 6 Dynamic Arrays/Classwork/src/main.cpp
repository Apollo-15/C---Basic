#include <iostream>

void MultiX(int a, int b, int c);

void PointerSwap(int** a, int** b)
{
    int* originalValue = *a;
    *a = *b;
    *b = originalValue;
}

int main(int argc, char* argv[])
{
    int valueA = 10;
    int valueB = 20;
    int valueC = 3;

    int valueA = 10;
    int valueB = 20;
    int* pValueA = &valueA;
    int* pValueB = &valueB;


    PointerSwap(&pValueA, &pValueB);

    std::cout << "Value A: " << pValueA << "\n";
    std::cout << "Value B: " << pValueB << "\n";

    MultiX(valueA, valueB, valueC);

    std::cout << "Value A: " << valueA << "\n";
    std::cout << "Value B: " << valueB << "\n";

    int* pPointer = nullptr;
    FuncForNew(pPointer);

    std::cout << "pPointer" << pPointer << "\n";

    return 0;
}

void MultiX(int* a, int* b, int c)
{
    *a = (*a) * c;
    *b = (*b) * c;
}

void FuncForNew(int* pointer)
{
    if (pointer != nullptr)
        delete pointer;
    pointer = new int;
}