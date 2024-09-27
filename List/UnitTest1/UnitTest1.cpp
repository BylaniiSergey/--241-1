#include "pch.h"
#include "CppUnitTest.h"
#include "../Solver/MyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ToString)
		{
			//arrande
			MyLinkedList list{ 1, 2, 3, 4, 5 };
			std::string expected = "1 2 3 4 5 ";

			//act
			auto actual = list.toString();

			//assert
			Assert::AreEqual(actual, expected);
		}
	};
}
