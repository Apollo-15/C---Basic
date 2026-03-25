#include <iostream>
#include "../include/Vector.hpp"

int main() {
    FinalVector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Vector: " << v << "\n";
    std::cout << "Size: " << v.size() << "\n";

    try {
        std::cout << "v[5] = " << v[5] << "\n";
    }
    catch (std::exception& e) {
        std::cout << "Error: index out of range\n";
    }

    v.pop_back();
    std::cout << "After pop_back: " << v << "\n";

    v.erase(0);
    std::cout << "After erase(0): " << v << "\n";

    FinalVector<int> v2 = v;
    std::cout << "Copy: " << v2 << "\n";

    v.clear();
    std::cout << "After clear: " << v << "\n";

    std::cin.get();

    return 0;
}