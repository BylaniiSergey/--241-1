#include "MyLinkedList.h"
#include <sstream>

MyLinkedList::MyLinkedList() : head(nullptr) {}

MyLinkedList::MyLinkedList(std::initializer_list<int> initList) : MyLinkedList()
{
    for (auto& value : initList)
    {
        push_back(value);
    }
}

MyLinkedList::MyLinkedList(const MyLinkedList& other) : MyLinkedList()
{
    Node* temp = other.head;
    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

MyLinkedList& MyLinkedList::operator=(const MyLinkedList& other)
{
    MyLinkedList temp(other);
    std::swap(this->head, temp.head);
    return *this;
}

MyLinkedList::~MyLinkedList()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool MyLinkedList::isEmpty() const
{
    return head == nullptr;
}

std::string MyLinkedList::toString() const
{
    //std::string result;
    std::stringstream result;
    Node* temp = head;
    while (temp != nullptr)
    {
        result << temp->data << " ";
        temp = temp->next;
    }
    return result.str();
}

void MyLinkedList::push_back(int value)
{
    Node* newNode = new Node{ value, nullptr };
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void MyLinkedList::push_front(int value)
{

    Node* newNode = new Node{ value, head };
    head = newNode;
}

void MyLinkedList::pop_back()
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void MyLinkedList::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

std::ostream& operator<<(std::ostream& os, const MyLinkedList& list)
{
    os << list.toString();
    return os;
}

void MyLinkedList::insert(int idx, int elem)
{
    if (idx < 0) throw;
    size_t index = idx;
    Node* current = head;
    size_t curr_index = 0;
    while (curr_index - 1 < index)
    {
        current = current->next;
        curr_index++;
    }
    Node* tmp = current->next;
    current->next = new Node();
    current = current->next;
    current->data = elem;
    current->next = tmp;
}

void MyLinkedList::remove(int idx)
{
    if (idx < 0) throw;
    size_t index = idx;
    Node* current = head;
    size_t curr_index = 0;
    while (curr_index - 1 < index)
    {
        current = current->next;
        curr_index++;
    }
    Node* tmp = current->next->next;
    delete current->next;
    current->next = tmp;
}

MyLinkedList::MyLinkedList(MyLinkedList&& other) noexcept
{
    head = other.head;
    other.head = nullptr;
}