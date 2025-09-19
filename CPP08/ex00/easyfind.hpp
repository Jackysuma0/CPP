#include <iostream>
#include <algorithm>

class notincontainer : public std::exception
{
    public:
        virtual const char* what () const throw()
        {
            return ("Value not found in the container");
        }
};

template <typename T>
int easyfind(const T& c, int i)
{
    if (std::find( c.begin(), c.end(), i ) != c.end() )
        return ( i );
    else
        throw notincontainer();
}