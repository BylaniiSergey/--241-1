#include <iostream>
#include <string>

/**
* @brief - Имя/название
*/
class MyLinkedList
{
private:

    struct Node
    {
        int data;
        Node* next = nullptr;
    };
    Node* head;

public:
    /**
    * @brief - Конструктор
    */
    MyLinkedList();
    MyLinkedList(std::initializer_list<int> initList);
    MyLinkedList(const MyLinkedList& other);
    ~MyLinkedList();
    /**
   * @brief - Конструктор перемещения
   */
    MyLinkedList(MyLinkedList&& other) noexcept;

    /**
    * @brief - Оператор перемещения
    */
    MyLinkedList& operator=(const MyLinkedList& other);

    /**
    * @brief - Проверка списка
    */
    bool isEmpty() const;
    std::string toString() const;

    /**
    * @brief - Функции
    */
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void insert(int idx, int elem);
    void remove(int idx);
    /**
    * @brief - Оператор сдвига
    */
    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList& list);
};