#include "CppUnitTest.h"
#include "..//Solver/MyLinkedList.h"
#include "..//Solver/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mynamespace;

namespace MyLinkedListTest
{
	TEST_CLASS(MyLinkedListTest)
	{
	public:
        TEST_METHOD(IsEmpty_ReturnsTrue_WhenListIsEmpty)
        {
            // Arrange
            MyLinkedList<int> list;
            // Act
            bool isEmpty = list.isEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(PushBack_AddsElementsToEnd_ReturnsCorrectString)
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
        TEST_METHOD(PushFront_AddsElementsToFront_ReturnsCorrectString)
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
        TEST_METHOD(PopBack_RemovesLastElement_ReturnsCorrectString)
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
        TEST_METHOD(PopFront_RemovesFirstElement_ReturnsCorrectString)
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
        TEST_METHOD(Insert_InsertsElementAtIndex_ReturnsCorrectString)
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
        TEST_METHOD(Remove_RemovesElementAtIndex_ReturnsCorrectString)
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
        TEST_METHOD(CopyConstructor_CreatesCopyOfList_ReturnsCorrectString)
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
        TEST_METHOD(MoveConstructor_MovesList_ReturnsCorrectStringAndEmptiesSource)
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
        TEST_METHOD(EmptyList_ChecksIfListIsEmpty_ReturnsTrue)
        {
            // Arrange
            MyLinkedList<std::string> list;
            // Act
            bool isEmpty = list.isEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }
        TEST_METHOD(PushBack_AddsStringElementsToEnd_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_back("Hello");
            list.push_back("World");
            std::string expected = "Hello World ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PushFront_AddsElementToFront_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_front("World");
            list.push_front("Hello");
            std::string expected = "Hello World ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PopBack_RemovesLastElement_ExpectedStringReturned)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_back("Hello");
            list.push_back("World");
            list.pop_back();
            std::string expected = "Hello ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PopFront_RemovesFirstElement_ExpectedStringReturned)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_back("Hello");
            list.push_back("World");
            list.pop_front();
            std::string expected = "World ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(Insert_AtIndexInsertsElement_ExpectedStringReturned)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_back("Hello");
            list.insert(1, "World");
            std::string expected = "Hello World ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(Remove_AtIndexRemovesElement_ExpectedStringReturned)
        {
            // Arrange
            MyLinkedList<std::string> list;
            list.push_back("Hello");
            list.push_back("and");
            list.push_back("World");
            list.remove(1);
            std::string expected = "Hello World ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(Constructor_CopiesList_ExpectedStringReturned)
        {
            // Arrange
            MyLinkedList<std::string> list1;
            list1.push_back("Hello");
            list1.push_back("World");
            std::string expected = "Hello World ";
            MyLinkedList<std::string> list2(list1);
            // Act
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(AssignmentOperator_CopiesList_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list1;
            list1.push_back("Hello World");
            std::string expected = "Hello World ";
            MyLinkedList<std::string> list2;
            list2 = list1;
            // Act
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
        TEST_METHOD(PushBack_AddsPointToEnd_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list;
            Point p1(1, 2);
            Point p2(3, 4);
            // Act 
            list.push_back(p2);
        }
        TEST_METHOD(PushFront_AddsPointToFront_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list;
            Point p2(3, 4);
            // Act
            list.push_front(p2);
        }
        TEST_METHOD(Insert_InsertsPointAtIndex_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list({ Point(1, 2), Point(3, 4) });
        }
        TEST_METHOD(RemoveRemove_RemovesPointAtIndex_ReturnsCorrectStringTest2)
        {
            // Arrange
            MyLinkedList<Point> list({ Point(1, 2), Point(3, 4), Point(5, 6) });
        }
	};
}