#include "pch.h"
#include "CppUnitTest.h"
#include "../Solver/MyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyLinkedListTest
{
	TEST_CLASS(MyLinkedList)
	{
	public:
		TEST_METHOD(ToString_ValidData_Success)
		{
			//arrande
			MyLinkedList list { 1, 2, 3, 4, 5 };
			std::string expected = " 1, 2, 3, 4, 5 ";

			//act
			auto actual = list.ToString();

			//assert
			Assert::AreEqual(actual, expected);
		}
	};
}

