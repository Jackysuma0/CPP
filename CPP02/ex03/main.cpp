#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);

    Point inside(2, 2);       // Inside the triangle
    Point onEdge(2, 0);       // On base edge
    Point vertex(0, 0);       // At a vertex
    Point outside(5, 5);      // Clearly outside

    std::cout << "inside: " << bsp(a, b, c, inside) << "\n";     // Expected: 1
    std::cout << "onEdge: " << bsp(a, b, c, onEdge) << "\n";     // Expected: 0
    std::cout << "vertex: " << bsp(a, b, c, vertex) << "\n";     // Expected: 0
    std::cout << "outside: " << bsp(a, b, c, outside) << "\n";   // Expected: 0

    return 0;
}