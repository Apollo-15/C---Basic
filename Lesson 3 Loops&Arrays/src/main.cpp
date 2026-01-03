#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Input any integer value in diapasone 0 - 10: ";
    unsigned short int valueFromPlayer = 0;
    // std::cin >> valueFromPlayer;

    // srand(time(NULL));
    unsigned short int PrizeValue = rand() % 11;

    // a == b - true if equal
    // a > b
    // a < b
    // a <= b
    // a >= b
    if (valueFromPlayer == PrizeValue)
    {
        std::cout << "You win!\n";
    }
    else if (valueFromPlayer > PrizeValue)
    {
        std::cout << "Your number is greater\n";
        std::cout << "You lose! Not guessed number was:" << PrizeValue <<
        "\n";
    }
    else
    {
        std::cout << "Your number is smaller\n";
        std::cout << " You lose! Not guessed number was: " << PrizeValue <<
        "\n";
    }

    // Switch cases

    switch (valueFromPlayer)
    {
        case 0:
        {
            std::cout << "Zero\n";
            break;
        }
        case 1:
        {
            std::cout << "One\n";
            break;
        }
        case 2:
        {
            std::cout << "Two\n";
            break;
        }
        case 3:
        {
            std::cout << "Three\n";
            break;
        }
        case 4:
        {
            std::cout << "Four\n";
            break;
        }
        case 5:
        {
            std::cout << "Five\n";
            break;
        }
        case 6:
        {
            std::cout << "Six\n";
            break;
        }
        case 7:
        {
            std::cout << "Seven\n";
            break;
        }
        case 8:
        {
            std::cout << "Eight\n";
            break;
        }
        case 9:
        {
            std::cout << "Nine\n";
            break;
        }
        default:
        {
            std::cout << "Default\n";
            break;
        }
    }

    // Loops

    unsigned short int MathsMarks[10];

    for (unsigned short int i = 0; i < 10; i++)
    {
        MathsMarks[i] = 0;
    }

    unsigned int index = 0;
    while (index < 10)
    {
        MathsMarks[index] = 0;
        ++index;
    }

    do  // dowhile - min 1 time
    {
        MathsMarks[index] = 0;
        ++index;
    } while (index < 10);

    // Arrays

    int arr[10];
    int matrix[3][10];

    for (unsigned int i = 0; i < 3; ++i)
    {
        for (unsigned int j = 0; j < 10; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    return 0;
}
