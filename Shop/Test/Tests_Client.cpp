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

        TEST_METHOD(EqualityOperator_ReturnsTrueForEqualClients)
        {
            // Arrange
            bakery::client::Client client1("Катя", 7.0);
            bakery::client::Client client2("Катя", 8.0);

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
            std::string expected = "Пётр";

            // Act
            std::string name = client.GetName();

            // Assert
            Assert::AreEqual(expected, name);
        }
        TEST_METHOD(ConstructorTest)
        {
            Client client1("John Doe", 10.0);
            Assert::AreEqual(std::string("John Doe"), client1.GetName());
            Assert::AreEqual(10.0, client1.GetDiscount());

            Client client2("Jane Doe", 0.0);
            Assert::AreEqual(std::string("Jane Doe"), client2.GetName());
            Assert::AreEqual(0.0, client2.GetDiscount());

            Client client3("", 25.0); // Test empty name
            Assert::AreEqual(std::string(""), client3.GetName());
            Assert::AreEqual(25.0, client3.GetDiscount());
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            bakery::client::Client client("Bob", 5.5);
            std::string expected = "Client: Bob; Skid: 5.5 %: ";

            // Act
            std::string actual = client.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(EqualityOperatorTest)
        {
            Client client1("John Doe", 10.0);
            Client client2("John Doe", 5.0);
            Client client3("Jane Doe", 10.0);

            Assert::IsTrue(client1 == client2);
            Assert::IsFalse(client1 == client3);

            //test with empty names
            Client client4("", 10.0);
            Client client5("", 5.0);
            Assert::IsTrue(client4 == client5);
        }


        TEST_METHOD(GetDiscountTest) {
            Client client1("John Doe", 15.0);
            Assert::AreEqual(15.0, client1.GetDiscount());

            Client client2("Jane Doe", 0.0);
            Assert::AreEqual(0.0, client2.GetDiscount());
        }

        TEST_METHOD(GetNameTest) 
        {
            Client client1("John Doe", 10.0);
            Assert::AreEqual(std::string("John Doe"), client1.GetName());

            Client client2("Jane Doe", 5.0);
            Assert::AreEqual(std::string("Jane Doe"), client2.GetName());

            Client client3("", 0.0); //Test empty name
            Assert::AreEqual(std::string(""), client3.GetName());
        }
    };
}