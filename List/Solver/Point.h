#include <iostream>
#include <string>

class Point 
{
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const 
    {
        return x == other.x && y == other.y;
    }

    std::string toString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};