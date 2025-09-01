#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(float const x, float const y);
        Point(const Point& other);
        Point& operator=(Point const &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
    private:
        Fixed const x;
        Fixed const y;
};