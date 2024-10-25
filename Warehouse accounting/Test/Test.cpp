#include "pch.h"
#include "CppUnitTest.h"
#include "..//Solver/Product.h"
#include "..//Solver/Store.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(ProductTest)
		{
			Product product("Test Product", 15.0);
			Assert::AreEqual(std::string("Test Product"), product.getName());
			Assert::AreEqual(15.0, product.getPrice());
		}

		TEST_METHOD(StoreTest)
		{
			Store store("Test Store", 10.0);
			Assert::AreEqual(std::string("Test Store"), store.getName());
			Assert::AreEqual(10.0, store.getDiscount());
		}
	};
}