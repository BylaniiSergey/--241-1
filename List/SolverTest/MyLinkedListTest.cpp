#include "CppUnitTest.h"
#include "..//Solver/MyLinkedList.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RealAnswerTest
{
	TEST_CLASS(RealAnswerTest)
	{
	public:
        TEST_METHOD(EmptyListTest)
        {
            // Arrange
            MyLinkedList<int> list;
            // Act
            bool isEmpty = list.isEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(PushBackTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            std::string expected = "1 2 3 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PushFrontTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_front(1);
            list.push_front(2);
            list.push_front(3);
            std::string expected = "3 2 1 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PopBackTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            list.pop_back();
            std::string expected = "1 2 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PopFrontTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_front(1);
            list.push_front(2);
            list.push_front(3);
            list.pop_front();
            std::string expected = "2 1 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(InsertTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            list.insert(1, 4);
            std::string expected = "1 4 2 3 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(RemoveTest)
        {
            // Arrange
            MyLinkedList<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            list.remove(1);
            std::string expected = "1 3 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(CopyConstructorTest)
        {
            // Arrange
            MyLinkedList<int> list1;
            list1.push_back(1);
            list1.push_back(2);
            list1.push_back(3);
            MyLinkedList<int> list2 = list1;
            std::string expected = "1 2 3 ";
            // Act
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(MoveConstructorTest)
        {
            // Arrange
            MyLinkedList<int> list1;
            list1.push_back(1);
            list1.push_back(2);
            list1.push_back(3);
            MyLinkedList<int> list2 = std::move(list1);
            std::string expected = "1 2 3 ";
            // Act
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
            Assert::IsTrue(list1.isEmpty());
        }
	};
}