#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t lengh, F func)
{
    size_t   i = 0;

    while (i < lengh)
    {
        func(array[i]);
        i++;
    }
}

template <typename T>
void    print(const T& value)
{
    std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
    ++value;
}