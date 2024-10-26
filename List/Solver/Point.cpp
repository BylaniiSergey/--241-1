#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const 
{
    return x == other.x && y == other.y;
}

std::string Point::toString() const 
{
    std::stringstream result;
    result << "(" << x << ", " << y << ")";
    return result.str();
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << point.x << " " << point.y;
    return os;
}
