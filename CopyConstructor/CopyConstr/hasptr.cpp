#include "hasptr.h"
#include <string>
#include <iostream>

HasPtr::HasPtr(const string &s = string()) : ps(new string(s), i(0))

{
    cout << s << endl;
    cout << i << endl;
}

HasPtr::HasPtr(const HasPtr &) {

    obj1.i = obj2.i;

    obj1.ps = obj2.*(ps);
}
