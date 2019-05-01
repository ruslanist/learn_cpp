#include <iostream>
#include <vector>

using namespace std;

class Node {

public:

    Node(int payL= 100, Node *pNext1=nullptr) : payLoad(payL), pNext(pNext1) {}

    Node *pNext;
    int payLoad;  
};

vector<Node*> Vec;

Node * insert(Node* n, int val) {

    n->pNext = new Node(val);

    Vec.push_back(n->pNext);

    return n->pNext;

}



int main()
{


    Node *head = new Node();
    Node *str_n = new Node();

    str_n = insert(head, 100);

    str_n = insert(str_n, 200);

    str_n = insert(str_n, 300);

    str_n = insert(str_n, 400);

    str_n = insert(str_n, 500);


    for (auto it : Vec) {

        cout << it->payLoad << endl;
    }
    cout << head->pNext << endl;

    Node* cur = head;
   while (cur->pNext != nullptr) {

        cout << cur->payLoad << endl;

        cur = cur->pNext;
    }

    cout << "Hello World!" << endl;
    return 0;
}
