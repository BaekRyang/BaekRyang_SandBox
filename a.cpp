#include <iostream>

using namespace std;

class Base {
public:
    Base() {cout << "base con" << endl;}
    ~Base() {cout << "base des" << endl;}
    virtual void func() {cout << "base func" << endl;}
};

class Derived : public Base {
public:
    Derived() {cout << "deri con" << endl;}
    ~Derived() {cout << "deri des" << endl;}
    void func() {cout << "deri func" << endl;}
};

int main() {
    Base *a = new Derived();
}