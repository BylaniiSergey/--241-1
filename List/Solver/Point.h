#include <iostream>
#include <string>
#include <sstream>

class Point 
{
public:
    int x, y;

    Point(int x, int y);

    bool operator==(const Point& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};