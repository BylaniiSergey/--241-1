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
    /**
     * @brief Конструктор по умолчанию
     * Создает пустой список, инициализируя поле head значением nullptr
     */
    MyLinkedList() : head(nullptr) {};
    
    /**
    * @brief Конструктор инициализации
    * Создает список, инициализируя его элементами из initializer_list
    * @param initList: список инициализации, содержащий значения для заполнения списка
    */
    MyLinkedList(std::initializer_list<T> initList) : MyLinkedList()
    {
        for (auto& value : initList)
        {
            push_back(value);
        }
    }

    /**
    * @brief Конструктор копирования
    * Создает копию списка other
    * @param other: ссылка на список, который нужно скопировать
    */
    MyLinkedList(const MyLinkedList<T>& other) : MyLinkedList()
    {
        Node* temp = other.head;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    /**
    * @brief Деструктор
    * Освобождает память, выделенную для узлов списка
    */
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

    /**
    * @brief Конструктор перемещения
    * Перемещает содержимое списка other в новый список, оставляя список other пустым
    * @param other: ссылка на список, который нужно переместить
    */
    MyLinkedList(MyLinkedList&& other) noexcept
    {
        head = other.head;
        size = other.size;
        other.head = nullptr;
    }

    /**
    * @brief Оператор присваивания
    * Присваивает списку other текущему списку
    * @param other: ссылка на список, который нужно присвоить
    * @return Ссылка на текущий список (*this)
    */
    MyLinkedList<T>& operator=(const MyLinkedList<T>& other)
    {
        MyLinkedList temp(other);
        std::swap(this->head, temp.head);
        std::swap(this->size, temp.size);
        return *this;
    }

    /**
    * @brief Метод isEmpty()
    * Проверяет, пуст ли список
    * @return true, если список пуст, иначе false
    */
    bool isEmpty() const
    {
        return head == nullptr;
    }

    /**
    * @brief Метод toString()
    * Преобразует список в строковое представление
    * @return Строка, представляющая список в виде последовательности значений, разделенных пробелами
    */
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
    
    /**
    * @brief Метод push_back()
    * Добавляет новый элемент в конец списка
    * @param value: значение, которое нужно добавить
    */
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
    
    /**
    * @brief Метод push_front()
    * Добавляет новый элемент в начало списка
    * @param value: значение, которое нужно добавить
    */
    void push_front(T value)
    {
        Node* newNode = new Node{ value, head };
        head = newNode;
        ++size;
    }

    /**
    * @brief Метод pop_back()
    * Удаляет последний элемент из списка
    */
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

    /**
    * @brief Метод pop_front()
    * Удаляет первый элемент из списка
    */
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

    /**
    * @brief Метод insert()
    * Вставляет новый элемент в список по заданному индексу
    * @param idx: Индекс, по которому нужно вставить элемент, elem: Значение, которое нужно вставить
    */
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

    /**
    * @brief Метод remove()
    * Удаляет элемент из списка по заданному индексу
    * @param idx: Индекс элемента, который нужно удалить
    */
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

    /**
    * @brief Оператор ввода/вывода
    * Перегруженный оператор вывода (<<) для списка
    * @param os: Объект std::ostream, в который нужно вывести список, list: Ссылка на список, который нужно вывести
    * @return Ссылка на объект std::ostream
    */
    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList& list) 
    {
        os << list.toString();
        return os;
    }
};