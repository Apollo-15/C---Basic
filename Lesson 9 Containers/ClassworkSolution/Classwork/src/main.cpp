#include <iostream>
#include <vector>

void VectorState(const std::vector<int>& v);

int main()
{
    std::vector<int> v;

    std::cout << "MAX SIZE: " << v.max_size() << "\n";
    std::cout << "MAX SIZE double: " << v.max_size() / 2 << "\n";

    v.reserve(10);
    VectorState(v);

    for (size_t i = 0; i < 10; ++i)
    {
        v.push_back(i);

        if (i == 9)
        {
	        std::cout << "Count #" << i << "\n";
	        VectorState(v);
        }
    }

    v.shrink_to_fit();
    VectorState(v);

    v.resize(15);

    for (size_t i = 0; i < v.size(); ++i)
    {
	    std::cout << "elem #" << v[i] << "\n";
    }

    /*for (size_t i = 0; i < v.size(); ++i)
    {
	    std::cout << v[i] << "\n";
    }*/

    return 0;
}

void VectorState(const std::vector<int>& v)
{
    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";
}