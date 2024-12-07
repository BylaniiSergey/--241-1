#include "pch.h"
#include <CppUnitTest.h>
#include "..//Solver/Product.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace bakery::product;

namespace ProductTests
{
    TEST_CLASS(ProductTest)
    {
    public:

        TEST_METHOD(Constructor_ValidInput)
        {
            // Arrange
            std::string item_number = "P001";
            std::string product_name = "Ѕулка";
            double price = 10.0;

            // Act
            Product product(item_number, product_name, price);

            // Assert
            Assert::AreEqual(item_number, product.GetItemNumber());
            Assert::AreEqual(product_name, product.GetProductName());
            Assert::AreEqual(price, product.GetPrice());
        }

        TEST_METHOD(Constructor_InvalidItemNumber_ThrowsException)
        {
            // Arrange
            std::string item_number = "";
            std::string product_name = "Ѕулка";
            double price = 10.0;

            // Act & Assert
            try
            {
                Product product(item_number, product_name, price);
                Assert::Fail(L"ќжидаемое исключение std::invalid_argument не было выдано.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Ѕыл выдан неожиданный тип исключени¤.");
            }
        }

        TEST_METHOD(Constructor_InvalidProductName_ThrowsException)
        {
            // Arrange
            std::string item_number = "P001";
            std::string product_name = "";
            double price = 10.0;

            /// Act & Assert
            try
            {
                Product product(item_number, product_name, price);
                Assert::Fail(L"ќжидаемое исключение std::invalid_argument не было выдано.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Ѕыл выдан неожиданный тип исключени¤.");
            }
        }

        TEST_METHOD(GetProduct_ReturnsValidSharedPtr)
        {
            // Arrange
            std::string item_number = "P001";
            std::string product_name = "Ѕулка";
            double price = 10.0;

            // Act
            std::shared_ptr<Product> product = Product::GetProduct(item_number, product_name, price);

            // Assert
            Assert::IsNotNull(product.get());
            Assert::AreEqual(item_number, product->GetItemNumber());
            Assert::AreEqual(product_name, product->GetProductName());
            Assert::AreEqual(price, product->GetPrice());
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            Product product("P001", "Ѕулка", 10.0);
            std::string expected = "јртикул: P001; название: Ѕулка; цена: 10 руб.";

            // Act
            std::string actual = product.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetPrice_ReturnsCorrectPrice)
        {
            // Arrange
            Product product("P001", "Ѕулка", 10.0);

            // Act
            double price = product.GetPrice();

            // Assert
            Assert::AreEqual(10.0, price);
        }

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualProducts)
        {
            // Arrange
            Product product1("P001", "Ѕулка", 10.0);
            Product product2("P001", "’леб", 15.0);

            // Act
            bool areEqual = (product1 == product2);

            // Assert
            Assert::IsTrue(areEqual);
        }

        TEST_METHOD(EqualityOperator_ReturnsFalseForDifferentProducts)
        {
            // Arrange
            Product product1("P001", "Ѕулка", 10.0);
            Product product2("P002", "’леб", 15.0);

            // Act
            bool areEqual = (product1 == product2);

            // Assert
            Assert::IsFalse(areEqual);
        }

        TEST_METHOD(OperatorLessThanLess_ReturnsCorrectString)
        {
            // Arrange
            Product product("P001", "Ѕулка", 10.0);
            std::ostringstream oss;
            std::string expected = "јртикул: P001; название: Ѕулка; цена: 10 руб.";

            // Act
            oss << product;
            std::string actual = oss.str();

            // Assert
            Assert::AreEqual(expected, actual);
        }
    };
}