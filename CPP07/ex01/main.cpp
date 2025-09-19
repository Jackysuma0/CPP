#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4};

    iter(arr, 4, print<int>);
    iter(arr, 4, increment<int>);

    iter(arr, 4, print<int>); 
}