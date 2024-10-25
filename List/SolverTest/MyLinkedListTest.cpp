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
        TEST_METHOD(IsEmpty_WhenListIsEmpty_ReturnsTrue)
        {
            // Arrange
            MyLinkedList<int> list{};
            // Act
            bool isEmpty = list.isEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }

        TEST_METHOD(PushBack_WhenElementsAddedToEnd_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 1, 2, 3 };
            std::string expected = "1 2 3 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PushFront_WhenElementsAddedToFront_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 3, 2, 1 };
            std::string expected = "3 2 1 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PopBack_WhenLastElementRemoved_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 1, 2 };
            std::string expected = "1 2 ";
            // Act
            list.push_back(3);
            list.pop_back();
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PopFront_WhenFirstElementRemoved_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 2, 1 };
            std::string expected = "2 1 ";
            // Act
            list.push_front(3);
            list.pop_front();
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Insert_WhenElementInsertedAtIndex_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 1, 4, 2, 3 };
            std::string expected = "1 4 2 3 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Remove_WhenElementRemovedAtIndex_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list{ 1, 3 };
            std::string expected = "1 3 ";
            // Act
            list.push_back(3);
            list.remove(1);
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(CopyConstructor_WhenListCopied_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<int> list1{ 1, 2, 3 };
            MyLinkedList<int> list2 = list1;
            std::string expected = "1 2 3 ";
            // Act
            list1.push_back(1);
            list1.push_back(2);
            list1.push_back(3);
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(MoveConstructor_WhenListMoved_ReturnsCorrectStringAndEmptiesSource)
        {
            // Arrange
            MyLinkedList<int> list1{1, 2, 3 };
            std::string expected = "1 2 3 ";
            // Act
            MyLinkedList<int> list2 = std::move(list1);
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
            Assert::IsTrue(list1.isEmpty());
        }

        TEST_METHOD(IsEmpty_WhenAnotherListIsEmpty_ReturnsTrue)
        {
            // Arrange
            MyLinkedList<std::string> list{};
            // Act
            bool isEmpty = list.isEmpty();
            // Assert
            Assert::IsTrue(isEmpty);
        }

        TEST_METHOD(PushBack_WhenStringElementsAddedToEnd_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list{};
            std::string expected = "Hello World ";
            // Act
            list.push_back("Hello");
            list.push_back("World");
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PushFront_WhenElementAddedToFront_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list{};

            std::string expected = "Hello World ";
            // Act
            list.push_front("World");
            list.push_front("Hello");
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PopBack_WhenLastElementRemoved_ReturnsExpectedString)
        {
            // Arrange
            MyLinkedList<std::string> list{};

            std::string expected = "Hello ";
            // Act
            list.push_back("Hello");
            list.push_back("World");
            list.pop_back();
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PopFront_WhenFirstElementRemoved_ReturnsExpectedString)
        {
            // Arrange
            MyLinkedList<std::string> list{};

            std::string expected = "World ";
            // Act
            list.push_back("Hello");
            list.push_back("World");
            list.pop_front();
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Insert_WhenElementInsertedAtIndex_ReturnsExpectedString)
        {
            // Arrange
            MyLinkedList<std::string> list{};

            std::string expected = "Hello World ";
            // Act
            list.push_back("Hello");
            list.insert(1, "World");
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Remove_WhenElementRemovedAtIndex_ReturnsExpectedString)
        {
            // Arrange
            MyLinkedList<std::string> list{};

            std::string expected = "Hello World ";
            // Act
            list.push_back("Hello");
            list.push_back("and");
            list.push_back("World");
            list.remove(1);
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(CopyConstructor_WhenListCopied_ReturnsExpectedString)
        {
            // Arrange
            MyLinkedList<std::string> list1{};
            std::string expected = "Hello World ";
            list1.push_back("Hello");
            list1.push_back("World");
            MyLinkedList<std::string> list2(list1);
            // Act
            std::string actual = list2.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(AssignmentOperator_WhenListCopied_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<std::string> list1{};
            list1.push_back("Hello");
            list1.push_back("World");
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
            MyLinkedList<Point> list{};
            Point p1(1, 2);
            Point p2(3, 4);
            // Act 
            list.push_back(p2);
        }

        TEST_METHOD(PushBack_WhenPointAddedToEnd_ReturnsCorrectString)
        {
            MyLinkedList<Point> list{};
            Point p1(1, 2);
            Point p2(3, 4);

            std::string expected = "1 2 3 4 ";
            // Act
            list.push_back(p1);
            list.push_back(p2);
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(PushFront_WhenPointAddedToFront_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list{};
            Point p2(3, 4);

            std::string expected = "3 4 ";
            // Act
            list.push_front(p2);
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Insert_WhenPointInsertedAtIndex_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list({ Point(1, 2), Point(3, 4) });
            Point p3(5, 6);
            list.insert(1, p3);
            std::string expected = "1 2 5 6 3 4 "; 
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Remove_WhenPointRemovedAtIndex_ReturnsCorrectString)
        {
            // Arrange
            MyLinkedList<Point> list({ Point(1, 2), Point(3, 4), Point(5, 6) });
            list.remove(1);
            std::string expected = "1 2 5 6 ";
            // Act
            std::string actual = list.toString();
            // Assert
            Assert::AreEqual(actual, expected);
        }
	};
}