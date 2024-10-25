#include <vector>
#include "Product.h"

class Invoice 
{
public:
    void addProduct(Product* product);
    void showInvoice() const;

private:
    std::vector<Product*> products;
};