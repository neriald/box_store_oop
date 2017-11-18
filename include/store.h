#ifndef STORE_H
#define STORE_H
#include "Box.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class store
{
    string description;
    double capacity, sumVol;
    vector<Box*> boxes;

public:

    class CapacityError:public logic_error
    {
    public:
        CapacityError(string msg): logic_error(msg) {}
    };

    class NameError: public logic_error
    {
    public:
        NameError(string msg): logic_error(msg) {}
    };

    class IndexError: public logic_error
    {
    public:
        IndexError(string msg): logic_error(msg) {}
    };

    store(string _desc, double _cap);
    string getDesc() const {return description;}
    double getCapacity() const {return capacity;}
    virtual ~store() {}
    void add(Box* b);
    void remove(string name);
    void clear();

    friend ostream& operator<<(ostream& out, const store &s);
    Box& operator[](unsigned i);

};

#endif // STORE_H
