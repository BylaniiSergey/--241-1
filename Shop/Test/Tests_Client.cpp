#include "pch.h"
#include "CppUnitTest.h"
#include "..//Solver/Client.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace bakery::client;

namespace ClientTests
{
    TEST_CLASS(ClientTest)
    {
    public:

        TEST_METHOD(Constructor_InitializesNameAndDiscount)
        {
            // Arrange
            std::string expectedName = "Алиса";
            double expectedDiscount = 10.0;

            // Act
            bakery::client::Client client(expectedName, expectedDiscount);

            // Assert
            Assert::AreEqual(expectedName, client.GetName());
            Assert::AreEqual(expectedDiscount, client.GetDiscount());
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            bakery::client::Client client("Вова", 5.0);
            std::string expected = " Клиент: Вова; скидка: 5 %: ";

            // Act
            std::string actual = client.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualClients)
        {
            // Arrange
            bakery::client::Client client1("Charlie", 7.0);
            bakery::client::Client client2("Charlie", 8.0);

            // Act
            bool areEqual = (client1 == client2);


            // Assert
            Assert::IsTrue(areEqual);
        }

        TEST_METHOD(EqualityOperator_ReturnsFalseForDifferentClients)
        {
            // Arrange
            bakery::client::Client client1("Игорь", 10.0);
            bakery::client::Client client2("Иван", 10.0);

            // Act
            bool areEqual = (client1 == client2);

            // Assert
            Assert::IsFalse(areEqual);
        }

        TEST_METHOD(GetDiscount_ReturnsCorrectDiscount)
        {
            // Arrange
            bakery::client::Client client("Антон", 15.0);

            // Act
            double discount = client.GetDiscount();

            // Assert
            Assert::AreEqual(15.0, discount);
        }

        TEST_METHOD(GetName_ReturnsCorrectName)
        {
            // Arrange
            bakery::client::Client client("Пётр", 20.0);
            std::string expected = "Пётр, 20.0:";

            // Act
            std::string name = client.GetName();

            // Assert
            Assert::AreEqual(expected, name);
        }

        TEST_METHOD(ToString_HandleZeroDiscount)
        {
            // Arrange
            bakery::client::Client client("Аня", 1.0);
            std::string expected = " Клиент: Аня; скидка: 1 %: ";

            // Act
            std::string actual = client.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(ToString_HandleEmptyName)
        {
            // Arrange
            bakery::client::Client client("", 5.0);
            std::string expected = " Клиент: ; скидка: 5 %: ";

            // Act
            std::string actual = client.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }
    };
}