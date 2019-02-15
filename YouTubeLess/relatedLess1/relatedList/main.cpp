#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    int GetSize() { return Size; }

    T& operator[](const int index);

private:

    template<typename T>
    class Node {      //Вложенный класс Node - Узел

    public:

        Node *pNext;   // Адресс, Указатель на следующий элемент
        T date = nullptr; // Данные хранящие данные

        Node::Node(T date=T(), Node *pNext = nullptr) {

            this->date = date;
            this->pNext = pNext;
        }

    };

    int Size;
    Node<T> *head; // Начало Списка    должен бть указателем и указывать на начало списка

};

template<typename T>
List<T>::List() {

    Size =0;
    head = nullptr;

}

template<typename T>
List<T>::~List() {


}

template<typename T>
void List<T>::push_back(T data) {

    if(head == nullptr) {

        head = new Node<T>(data);

    } else {

        Node<T> *current = this->head;
        while (current->pNext != nullptr) {

            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
T& List::operator [](const int index) {

    int counter =0; // Счетчик для подсчета в каком конкретно элементе списка мы находимся
    Node<T> *current = this->head;

    while (current != nulptr) {

        if(current == index) {

            return current->date;
        } else {

            current = current->pNext;
            counter++;
        }
    }
}



int main()
{
/*
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
*/

/*
    cout << lst[2] << endl; // Логтка для выводазначения поля списка по индексу 2

    for(size_t i = 0; i < lst.GetSize(); i++) {   // Цикл который выводит все элементы односвязанного списка

        cout << lst[i] << endl;
    }
*/

    int numberCount; // Переменная отвечающая за то, сколько будет случайных чисел
    cin >> numberCount;

    for(int i =0; i < numberCount; i++) {

        lst.push_back(rand()%10);
    }

    for(size_t i = 0; i < lst.GetSize(); i++) {

        cout << lst[i] << endl;
    }


    cout << lst.GetSize() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
