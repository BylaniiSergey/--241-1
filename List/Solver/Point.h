#include <iostream>
#include <string>

class Point 
{
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const 
    {
        return x == other.x && y == other.y;
    }

    std::string toString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) 
    {
        os << point.x << " " << point.y;
        return os;
    }
};