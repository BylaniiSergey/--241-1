#include "pch.h"
#include <CppUnitTest.h>
#include "..//Solver/Invoice.h"
#include "..//Solver/Store.h"
#include "..//Solver/Client.h"
#include "..//Solver/Product.h"
#include <sstream>
#include <iomanip>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace bakery::invoice;
using namespace bakery::shop;
using namespace bakery::client;
using namespace bakery::product;

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
    template<>
    static std::wstring ToString<std::chrono::system_clock::time_point>(const std::chrono::system_clock::time_point& tp)
    {
        std::time_t t = std::chrono::system_clock::to_time_t(tp);
        std::tm tm;
        localtime_s(&tm, &t);
        std::wstringstream ss;
        ss << std::put_time(&tm, L"%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
}

namespace InvoiceTests
{
    TEST_CLASS(InvoiceTest)
    {
    public:

        TEST_METHOD(Constructor_ValidInput)
        {
            // Arrange
            auto store = std::make_shared<Store>("StoreName");
            auto client = std::make_shared<Client>("ClientName", 10.0);
            std::string invoice_id = "INV001";
            std::string issue_date_str = "2023-10-01";

            // Convert the issue date string to a std::chrono::system_clock::time_point
            std::tm tm = {};
            std::istringstream ss(issue_date_str);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            // Act
            Invoice invoice(store, client, invoice_id, issue_date);

            // Assert
            Assert::AreEqual(invoice_id, invoice.GetInvoiceId());
            Assert::AreEqual(issue_date, invoice.GetIssueDate());
            Assert::IsTrue(invoice.GetStore() != nullptr);
            Assert::IsTrue(invoice.GetClient() != nullptr);
        }

        TEST_METHOD(Constructor_InvalidStore_ThrowsException)
        {
            // Arrange
            auto store = std::shared_ptr<Store>(nullptr);
            auto client = std::make_shared<Client>("ClientName", 10.0);
            std::string invoice_id = "INV001";
            std::string issue_date_str = "2023-10-01";

            // Convert the issue date string to a std::chrono::system_clock::time_point
            std::tm tm = {};
            std::istringstream ss(issue_date_str);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            // Act & Assert
            try
            {
                Invoice invoice(store, client, invoice_id, issue_date);
                Assert::Fail(L"Expected std::invalid_argument exception was not thrown.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Unexpected exception type was thrown.");
            }
        }

        TEST_METHOD(Constructor_InvalidClient_ThrowsException)
        {
            // Arrange
            auto store = std::make_shared<Store>("StoreName");
            auto client = std::shared_ptr<Client>(nullptr);
            std::string invoice_id = "INV001";
            std::string issue_date_str = "2023-10-01";

            // Convert the issue date string to a std::chrono::system_clock::time_point
            std::tm tm = {};
            std::istringstream ss(issue_date_str);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            // Act & Assert
            try
            {
                Invoice invoice(store, client, invoice_id, issue_date);
                Assert::Fail(L"Expected std::invalid_argument exception was not thrown.");
            }
            catch (const std::invalid_argument&)
            {
                // Expected exception
            }
            catch (...)
            {
                Assert::Fail(L"Unexpected exception type was thrown.");
            }
        }

        TEST_METHOD(ToString_ReturnsCorrectString)
        {
            // Arrange
            auto store = std::make_shared<Store>("StoreName");
            auto client = std::make_shared<Client>("ClientName", 10.0);
            std::string invoice_id = "INV001";
            std::string issue_date_str = "2023-10-01";

            // Convert the issue date string to a std::chrono::system_clock::time_point
            std::tm tm = {};
            std::istringstream ss(issue_date_str);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            Invoice invoice(store, client, invoice_id, issue_date);
            auto product1 = std::make_shared<Product>("P001", "Product1", 10.0);
            auto product2 = std::make_shared<Product>("P002", "Product2", 20.0);
            invoice.addProduct(product1);
            invoice.addProduct(product2);

            std::string expected = "Накладная ID: INV001 от 2023-10-01\n"
                "Магазин: StoreName\n"
                "Клиент: ClientName\n"
                "Список товаров:\n"
                "- Артикул: P001; название: Product1; цена: 10 руб.\n"
                "- Артикул: P002; название: Product2; цена: 20 руб.\n"
                "Общая стоимость: 27 руб.\n";

            // Act
            std::string actual = invoice.toString();

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetTotalCost_ReturnsCorrectTotalCost)
        {
            // Arrange
            auto store = std::make_shared<Store>("StoreName");
            auto client = std::make_shared<Client>("ClientName", 10.0);
            std::string invoice_id = "INV001";
            std::string issue_date_str = "2023-10-01";

            // Convert the issue date string to a std::chrono::system_clock::time_point
            std::tm tm = {};
            std::istringstream ss(issue_date_str);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            auto issue_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));

            Invoice invoice(store, client, invoice_id, issue_date);
            auto product1 = std::make_shared<Product>("P001", "Product1", 10.0);
            auto product2 = std::make_shared<Product>("P002", "Product2", 20.0);
            invoice.addProduct(product1);
            invoice.addProduct(product2);

            // Act
            double totalCost = invoice.GetTotalCost();

            // Assert
            Assert::AreEqual(27.0, totalCost);
        }
    };
}