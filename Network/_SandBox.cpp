#include <iostream>

using std::cout;
using std::endl;

typedef struct A {
	int a;
	int b;
	struct A* ptr;
} AA;
int main() {
	A a;
	A b;
	A c;
	A d;
	a.ptr = &b;
	a.a = 10;
	a.b = 20;

	b.ptr = &c;
	b.a = 30;
	b.b = 40;

	c.ptr = &d;
	c.a = 50;
	c.b = 60;

	d.a = 70;
	d.b = 80;

	cout << a.ptr->ptr->ptr->b << endl;
	cout << sizeof(a.ptr);
	return 0;
}