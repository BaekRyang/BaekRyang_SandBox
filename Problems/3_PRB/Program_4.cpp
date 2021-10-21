#include <iostream>
using namespace std;

class Animal {
public:
	//몸체가 없는 순수 가상함수가 부모 클래스에 선언되어있음
	virtual void bark() = 0;
};

class Dog : public Animal {
public:
	//가상함수의 몸체를 자식 클래스에서 오버라이딩 하여 정의함
	void bark() { cout << "Woof!" << endl; };
};

class Cat : public Animal {
public:
	//가상함수의 몸체를 자식 클래스에서 오버라이딩 하여 정의함
	//Dog과는 다른 결과를 출력함
	void bark() { cout << "Meaw~" << endl; };
};

int main(int argc, char const* argv[])
{
	//각 클래스의 객체를 동적 할당해준다.
	//Animal은 순수 가상 함수가 있으므로 객체를 생성할 수 없다.
	Dog* myDog = new Dog;
	Cat* myCat = new Cat;

	//포인터를 이용한 함수 호출을 해준다.
	//가상함수를 사용하였기 때문에 각 클래스의 함수가 정상적으로 출력된다.
	myDog->bark();
	myCat->bark();
	return 0;
}