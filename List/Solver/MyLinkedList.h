#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>

template<typename T>
class MyLinkedList 
{
private:
    int size = 0;
    struct Node 
    {
        T data;
        Node* next = nullptr;
    };
    Node* head;

public:
    MyLinkedList() : head(nullptr) {};
    
    MyLinkedList(std::initializer_list<T> initList) : MyLinkedList()
    {
        for (auto& value : initList)
        {
            push_back(value);
        }
    }

    MyLinkedList(const MyLinkedList<T>& other) : MyLinkedList()
    {
        Node* temp = other.head;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    ~MyLinkedList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    MyLinkedList(MyLinkedList&& other) noexcept
    {
        head = other.head;
        size = other.size;
        other.head = nullptr;
    }

    MyLinkedList<T>& operator=(const MyLinkedList<T>& other)
    {
        MyLinkedList temp(other);
        std::swap(this->head, temp.head);
        std::swap(this->size, temp.size);
        return *this;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    std::string toString() const
    {
        std::stringstream result;
        Node* temp = head;
        while (temp != nullptr)
        {
            result << temp->data << " ";
            temp = temp->next;
        }
        return result.str();
    }
    
    void push_back(T value)
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
            ++size;
        }
    }
    
    void push_front(T value)
    {
        Node* newNode = new Node{ value, head };
        head = newNode;
        ++size;
    }

    void pop_back()
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
        --size;
        delete temp->next;
        temp->next = nullptr;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* temp = head;
        --size;
        head = head->next;
        delete temp;
    }

    void insert(int idx, T elem)
    {
        if (idx < 0) throw;
        size_t index = idx;
        Node* current = head;
        size_t curr_index = 0;
        while (current != nullptr && curr_index - 1 < index)
        {
            if (curr_index == index - 1)
            {
                break;
            }
            current = current->next;
            curr_index++;
        }
        Node* tmp = current->next;
        current->next = new Node();
        current = current->next;
        current->data = elem;
        current->next = tmp;
        ++size;
    }

    void remove(int idx)
    {
        if (idx < 0)
        {
            throw std::out_of_range("Индекс не может быть отрицательным");
        }

        size_t index = static_cast<size_t>(idx);

        if (index >= size)
        {
            throw std::out_of_range("Индекс вне диапазона");
        }

        Node* current = head;
        size_t curr_index = 0;
        while (current != nullptr && curr_index < index - 1)
        {
            current = current->next;
            curr_index++;
        }

        Node* tmp = current->next;
        current->next = tmp->next;
        delete tmp;
        --size;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList& list) 
    {
        os << list.toString();
        return os;
    }
};