#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>

namespace mynamespace
{
    template<typename T>
    class MyLinkedList;

    /**
    * @brief Оператор ввода/вывода
    * Перегруженный оператор вывода (<<) для списка
    * @param os: Объект std::ostream, в который нужно вывести список, list: Ссылка на список, который нужно вывести
    * @return Ссылка на объект std::ostream
    */
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list);

    template<typename T>
    class MyLinkedList
    {
    private:
        size_t safe_cast_to_size_t(int idx) 
        {
            if (idx < 0) 
            {
                throw std::out_of_range("Индекс не может быть отрицательным");
            }
            return static_cast<size_t>(idx);
        }

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
        MyLinkedList();

        /**
        * @brief Конструктор инициализации
        * Создает список, инициализируя его элементами из initializer_list
        * @param initList: список инициализации, содержащий значения для заполнения списка
        */
        MyLinkedList(std::initializer_list<T> initList);

        /**
        * @brief Конструктор копирования
        * Создает копию списка other
        * @param other: ссылка на список, который нужно скопировать
        */
        MyLinkedList(const MyLinkedList<T>& other);

        /**
        * @brief Конструктор перемещения
        * Перемещает содержимое списка other в новый список, оставляя список other пустым
        * @param other: ссылка на список, который нужно переместить
        */
        MyLinkedList(MyLinkedList&& other) noexcept;

        /**
        * @brief Деструктор
        * Освобождает память, выделенную для узлов списка
        */
        ~MyLinkedList();

        /**
        * @brief Оператор присваивания
        * Присваивает списку other текущему списку
        * @param other: ссылка на список, который нужно присвоить
        * @return Ссылка на текущий список (*this)
        */
        MyLinkedList<T>& operator=(const MyLinkedList<T>& other);

        /**
        * @brief Метод isEmpty()
        * Проверяет, пуст ли список
        * @return true, если список пуст, иначе false
        */
        bool isEmpty() const;

        /**
        * @brief Метод toString()
        * Преобразует список в строковое представление
        * @return Строка, представляющая список в виде последовательности значений, разделенных пробелами
        */
        std::string toString() const;

        /**
        * @brief Метод push_back()
        * Добавляет новый элемент в конец списка
        * @param value: значение, которое нужно добавить
        */
        void push_back(T value);

        /**
        * @brief Метод push_front()
        * Добавляет новый элемент в начало списка
        * @param value: значение, которое нужно добавить
        */
        void push_front(T value);

        /**
        * @brief Метод pop_back()
        * Удаляет последний элемент из списка
        */
        void pop_back();

        /**
        * @brief Метод pop_front()
        * Удаляет первый элемент из списка
        */
        void pop_front();

        /**
        * @brief Метод insert()
        * Вставляет новый элемент в список по заданному индексу
        * @param idx: Индекс, по которому нужно вставить элемент, elem: Значение, которое нужно вставить
        */
        void insert(int idx, T elem);

        /**
        * @brief Метод remove()
        * Удаляет элемент из списка по заданному индексу
        * @param idx: Индекс элемента, который нужно удалить
        */
        void remove(int idx);

        /**
        * @brief Метод get_back()
        * Возвращает значение последнего элемента списка
        * @return Значение последнего элемента списка типа T
        */
        T get_back();

        /**
        * @brief Метод get_front()
        * Возвращает значение первого элемента списка
        * @return Значение первого элемента списка типа T
        */
        T get_front();
    };

    template<typename T>
    MyLinkedList<T>::MyLinkedList() : head{ nullptr }, size{ 0 } {}

    template<typename T>
    MyLinkedList<T>::MyLinkedList(std::initializer_list<T> initList) : MyLinkedList()
    {
        for (auto& value : initList)
        {
            push_back(value);
        }
    }

    template<typename T>
    MyLinkedList<T>::MyLinkedList(const MyLinkedList<T>& other) : MyLinkedList() 
    {
        Node* temp = other.head;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    template<typename T>
    MyLinkedList<T>::MyLinkedList(MyLinkedList&& other) noexcept
    {
        head = other.head;
        size = other.size;
        other.head = nullptr;
    }

    template<typename T>
    MyLinkedList<T>::~MyLinkedList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }

    template<typename T>
    MyLinkedList<T>& MyLinkedList<T>::operator=(const MyLinkedList<T>& other) 
    {
        MyLinkedList temp(other);
        std::swap(this->head, temp.head);
        std::swap(this->size, temp.size);
        return *this;
    }

    template<typename T>
    bool MyLinkedList<T>::isEmpty() const 
    {
        return head == nullptr;
    }

    template<typename T>
    std::string MyLinkedList<T>::toString() const 
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

    template<typename T>
    void MyLinkedList<T>::push_back(T value) 
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

    template<typename T>
    void MyLinkedList<T>::push_front(T value) 
    {
        Node* newNode = new Node{ value, head };
        head = newNode;
        ++size;
    }

    template<typename T>
    void MyLinkedList<T>::pop_back() 
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

    template<typename T>
    void MyLinkedList<T>::pop_front() 
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

    template<typename T>
    T MyLinkedList<T>::get_back()
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Список пуст");
        }

        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        return temp->data;
    }

    template<typename T>
    T MyLinkedList<T>::get_front()
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Список пуст");
        }
        return head->data;
    }

    template<typename T>
    void MyLinkedList<T>::insert(int idx, T elem) 
    {
        size_t index = safe_cast_to_size_t(idx);
        Node* current = head;
        size_t curr_index = 0;
        while (current != nullptr && curr_index - 1 < index)
        {
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

    template<typename T>
    void MyLinkedList<T>::remove(int idx) 
    {
        size_t index = safe_cast_to_size_t(idx);
        if (index > size) throw std::out_of_range(" Индекс вне диапазона");
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

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list)
    {
        os << list.toString();
        return os;
    }
}