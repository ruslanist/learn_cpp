#include <iostream>

using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();

    void push_back(T data);
    int GetSize() {return  Size;}

private:

    template<typename T2>
    class Node {
    public:
        Node *pNext; // Указатель на следующий элемент в списке
        T data;  // Данные для каждого элемента списка

        // nulptr - Указывает на ноль, когда не прилетит указатель он будет == Нулю, а значит конец списка
        // T() - Чтобы в data небыло мусора это конструкция позволяет дифолтно инциализировать типом шаблона, т.е. компилятор сам решит как инциализировать
        Node(T2 data = T2(), Node *pNext=nullptr) { // Передают данные и указатель на следующий элемент
        cout << "Constructor Node" << endl;
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size; // Хранит кол-во элиментов списке
    Node<T> *head; // Указатель указывающий на начало списка

};

template<typename T>
List<T>::List() {

    cout << "Constructor List" << endl;
    Size =0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    cout << "Destructor List" << endl;
}

template<typename T>
void List<T>::push_back(T data) {

    cout << "Push_Back List" << endl;
    if(head == nullptr) {
        cout << "IF Push_Back List" << endl;
        head = new Node<T>(data);
    } else {

        cout << "ELSE Push_Back List" << endl;
        Node<T> *current = this->head;
        while(current->pNext != nullptr) {

            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }

    Size++;
}






int main()
{
    List<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    cout << lst.GetSize() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
