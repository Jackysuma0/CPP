#include "Point.hpp"
#include "Fixed.hpp"

Fixed absFixed(Fixed value)
{
    if (value < Fixed(0))
    {
        return value * Fixed(-1);
    }
    else
    {
        return value;
    }
}

Fixed triangleArea(Point const p1, Point const p2, Point const p3)//determinant formula
{
    return absFixed(
        (p1.getX() * (p2.getY() - p3.getY()) +
         p2.getX() * (p3.getY() - p1.getY()) +
         p3.getX() * (p1.getY() - p2.getY())) / Fixed(2)
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = triangleArea(a, b, c);
    Fixed areaPAB = triangleArea(point, a, b);
    Fixed areaPBC = triangleArea(point, b, c);
    Fixed areaPCA = triangleArea(point, c, a);
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;

    Fixed sumOfSubAreas = areaPAB + areaPBC + areaPCA;

    return (sumOfSubAreas == areaABC);
}