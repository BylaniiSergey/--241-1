#include "pch.h"
#include <CppUnitTest.h>
#include "..//Solver/Store.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace bakery::shop;

namespace StoreTests
{
    TEST_CLASS(StoreTest)
    {
    public:
        TEST_METHOD(Constructor_ValidInput_SingleParameter)
        {
            // Arrange
            std::string shop_name = "StoreName";

            // Act
            Store store(shop_name);

            // Assert
            Assert::AreEqual(shop_name, store.GetName());
        }

        TEST_METHOD(Constructor_ValidInput_ThreeParameters)
        {
            // Arrange
            int taxpayer_id = 12345;
            std::string shop_name = "StoreName";
            std::string shop_address = "123 Main St";

            // Act
            Store store(taxpayer_id, shop_name, shop_address);

            // Assert
            Assert::AreEqual(taxpayer_id, store.GetTaxpayerId());
            Assert::AreEqual(shop_name, store.GetName());
            Assert::AreEqual(shop_address, store.GetAddress());
        }

        TEST_METHOD(Constructor_InvalidTaxpayerId_ThrowsException)
        {
            // Arrange
            int taxpayer_id = 1;
            std::string shop_name = "StoreName";
            std::string shop_address = "";

            // Act & Assert
            try
            {
                Store store(taxpayer_id, shop_name, shop_address);
                Assert::Fail(L"Ожидаемое исключение std::invalid_argument не было выдано.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Был выдан неожиданный тип исключения.");
            }
        }

        TEST_METHOD(Constructor_InvalidShopName_ThrowsException)
        {
            // Arrange
            int taxpayer_id = 12345;
            std::string shop_name = "";
            std::string shop_address = "123 Main St";

            // Act & Assert
            try
            {
                Store store(taxpayer_id, shop_name, shop_address);
                Assert::Fail(L"Ожидаемое исключение std::invalid_argument не было выдано.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Был выдан неожиданный тип исключения.");
            }
        }

        TEST_METHOD(Constructor_InvalidShopAddress_ThrowsException)
        {
            // Arrange
            int taxpayer_id = 12345;
            std::string shop_name = "StoreName";
            std::string shop_address = "";

            // Act & Assert
            try
            {
                Store store(taxpayer_id, shop_name, shop_address);
                Assert::Fail(L"Ожидаемое исключение std::invalid_argument не было выдано.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Был выдан неожиданный тип исключения.");
            }
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            Store store(12345, "StoreName", "123 Main St");
            std::string expected = "Магазин: StoreName; Адрес: 123 Main St; ИНН: 12345";

            // Act
            std::string actual = store.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualStores)
        {
            // Arrange
            Store store1(12345, "StoreName", "123 Main St");
            Store store2(12345, "StoreName", "123 Main St");

            // Act
            bool areEqual = (store1 == store2);

            // Assert
            Assert::IsTrue(areEqual);
        }

        TEST_METHOD(EqualityOperator_ReturnsFalseForDifferentStores)
        {
            // Arrange
            Store store1(12345, "StoreName", "123 Main St");
            Store store2(54321, "DifferentStore", "456 Other St");

            // Act
            bool areEqual = (store1 == store2);

            // Assert
            Assert::IsFalse(areEqual);
        }

        TEST_METHOD(GetName_ReturnsCorrectName)
        {
            // Arrange
            Store store(12345, "StoreName", "123 Main St");
            std::string expected = "StoreName";

            // Act
            std::string actual = store.GetName();

            // Assert
            Assert::AreEqual(expected, actual);
        }
    };
}