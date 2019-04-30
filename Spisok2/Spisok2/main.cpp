#include <iostream>
#include <vector>

using namespace std;

class Node {

public:

    Node(int payL= 0, Node *p= nullptr) : payLoad(payL), pNext(p) {}

    Node *pNext;
    int payLoad;

};


Node * insert(Node* n, int val) {

    n->pNext = new Node(val);

    return n;

}



int main()
{

    vector<Node*> Vec;
    Node *p = new Node();


    Vec.push_back(insert(p, 100));
    Vec.push_back(insert(p, 200));
    Vec.push_back(insert(p, 300));
    Vec.push_back(insert(p, 400));
    Vec.push_back(insert(p, 500));
    cout << p->payLoad << endl;
    cout << Vec.size() << endl;



    cout << "Hello World!" << endl;
    return 0;
}
