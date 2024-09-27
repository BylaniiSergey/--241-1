#include "Product.h"

class Item : public Product 
{
private:
    std::string name;
    double price;

public:
    Item(std::string name, double price);
    std::string getInfo() const override;
};