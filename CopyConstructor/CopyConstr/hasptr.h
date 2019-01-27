#ifndef HASPTR_H
#define HASPTR_H
#include <string>

using std::string;

class HasPtr
{

public:
    HasPtr(const string &s = string());

    HasPtr(const HasPtr&);

private:
    string *ps;
    int i;

};

#endif // HASPTR_H
