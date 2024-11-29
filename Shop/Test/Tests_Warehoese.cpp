#include "pch.h"
#include <CppUnitTest.h>
#include "..//Solver/Warehouse.h"
#include "..//Solver/Product.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace bakery::warehouse;
using namespace bakery::product;

namespace WarehouseTests
{
    TEST_CLASS(WarehouseTest)
    {
    public:
        TEST_METHOD(PrintInventory_PrintsCorrectInventory)
        {
            // Arrange
            Warehouse warehouse;
            auto product1 = std::make_shared<Product>("P001", "Product1", 10.0);
            auto product2 = std::make_shared<Product>("P002", "Product2", 20.0);
            warehouse.AddProduct(product1);
            warehouse.AddProduct(product2);

            std::ostringstream oss;
            std::streambuf* cout_buf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());

            // Act
            warehouse.PrintInventory();

            // Restore original cout buffer
            std::cout.rdbuf(cout_buf);

            std::string expected = "»нвентарь склада:\nјртикул: P001; название: Product1; цена: 10 руб.\nјртикул: P002; название: Product2; цена: 20 руб.\n";
            std::string actual = oss.str();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(PrintInventory_EmptyWarehouse_PrintsEmptyInventory)
        {
            // Arrange
            Warehouse warehouse;

            std::ostringstream oss;
            std::streambuf* cout_buf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());

            // Act
            warehouse.PrintInventory();

            // Restore original cout buffer
            std::cout.rdbuf(cout_buf);

            std::string expected = "»нвентарь склада:\n";
            std::string actual = oss.str();

            // Assert
            Assert::AreEqual(expected, actual);
        }
    };
}