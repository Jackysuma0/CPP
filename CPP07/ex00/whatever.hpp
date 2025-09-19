#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename A>
A min(A a, A b)
{
    return (a < b) ? a : b;
}

template <typename B>
B max(B a, B b)
{
    return (a > b) ? a : b;
}