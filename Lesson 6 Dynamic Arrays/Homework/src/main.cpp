#include <iostream>

void function(int*& ptr)
{
    if (ptr == nullptr)
    {
        ptr = new int(17);
    } 
    else
    {
        delete ptr;
        ptr = new int(24);
    }
}

int main(int argc, char* argv[])
{
    int* myPtr = nullptr;
    function(myPtr);

    int* anotherMyPtr = new int(15);
    function(anotherMyPtr); 

    delete myPtr;
    delete anotherMyPtr;

    return 0;
}
