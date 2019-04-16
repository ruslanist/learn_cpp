#include <iostream>

using namespace std;
/*
class Base {

};


class Base2 {
public:

    Base2(int a) : _a(a) {

    }

private:

        int _a;
};

class Child : public Base {
public:
    Child() {

    }

};

class Child2 : Base2 {
public:

    Child2() : Base2(5) {

    }

    Child2(int a) : Base2(a) {

    }

};

class Child3 : public Child2 {

public:

    Child3() {

    }

    Child3(int a) : Child2(a) {

    }

};
*/

class Base {
public:

    Base(int param) {

        cout << "Base (" << param << ")" << endl;
    }
};

class Child : public Base {
public:

    Child() : Base(10)  {

        cout << "Child()" << endl;
    }

    Child(int child_param) : Base(child_param) {

        cout << "Child(" << child_param << ")" << endl;
    }


};

int main()
{
    Child obj;

    Child obj1(100);

    cout << "Hello World!" << endl;
    return 0;
}
