#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    // std::cout << "Default constructor called" << "\n";
}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    // std::cout << "Copy constructor called" << "\n";
}

Point::~Point()
{
    // std::cout << "Destructor called" << "\n";
}

Point& Point::operator=(Point const &other)
{
    // std::cout << "Copy assignment operator called" << "\n";
    if (this != &other)
    {
        new (this)Point(other.getX().toFloat(), other.getY().toFloat());
    }
    return (*this);
}

Fixed   Point::getX() const
{
    return (this->x);
}

Fixed   Point::getY() const
{
    return (this->y);
}