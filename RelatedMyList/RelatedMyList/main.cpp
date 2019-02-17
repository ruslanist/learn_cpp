#include <iostream>

using namespace std;

template<typename allT>
class List
{
public:

    List *pNext;
    allT data;
    List *head = nullptr;
    int Size = 0;

    List(allT datA=allT(), List *pNexT = nullptr) {

        this->data = datA;
        this->pNext = pNexT;
    }

    //allT& operator[](const int index);

    void push_back(allT data) {

        if(head == nullptr) {

            head = new List<allT>(data);

        } else {

            List<allT> *current = this->head;
            while (current->pNext != nullptr) {

                current = current->pNext;
            }

            current->pNext = new List<allT>(data);
        }

        Size++;
    }

    int GetSize() { return Size; }

};


int main()
{

    List<int> lst;

    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);


    cout << lst.GetSize() << endl;
/*
   List *current;

        while (current != nulptr) {

            cout << current->data << endl;

            current->pNext;
        }
*/


    cout << "Hello World!" << endl;
    return 0;
}
