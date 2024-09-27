#include "CppUnitTest.h"
#include "../Solver/MyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyLinkedListTest
{
	TEST_CLASS(MyLinkedList)
	{
	public:
		
        TEST_METHOD(MyLinkedList_Constructor_Success) 
        {
            MyLinkedList linkedList;
            Assert::IsTrue(linkedList.isEmpty());
        }

        TEST_METHOD(InitializerListConstructor_ValidData_Success) 
        {
            MyLinkedList initList = { 1, 2, 3, 4, 5 };
            Assert::AreEqual(5, initList.size());
            Assert::AreEqual(1, initList.front());
            Assert::AreEqual(5, initList.back());
        }

        TEST_METHOD(CopyConstructor_ValidData_Success) 
        {
            MyLinkedList originalList = { 1, 2, 3, 4, 5 };
            MyLinkedList copiedList(originalList);
            Assert::AreEqual(5, copiedList.size());
            Assert::AreEqual(1, copiedList.front());
            Assert::AreEqual(5, copiedList.back());
        }

        TEST_METHOD(AssignmentOperator_ValidData_Success)
        {
            MyLinkedList originalList = { 1, 2, 3 };
            MyLinkedList assignedList;
            assignedList = originalList;
            Assert::AreEqual(3, assignedList.size());

        }
        TEST_METHOD(PushBack_ValidData_Success) {
            MyLinkedList linkedList;
            linkedList.push_back(10);
            linkedList.push_back(20);
            linkedList.push_back(30);

            Assert::AreEqual(3, linkedList.size());
            Assert::AreEqual(10, linkedList.front());
            Assert::AreEqual(30, linkedList.back());
        }
	};
}