#include <iostream>
using namespace std;

class Animal {
public:
	//��ü�� ���� ���� �����Լ��� �θ� Ŭ������ ����Ǿ�����
	virtual void bark() = 0;
};

class Dog : public Animal {
public:
	//�����Լ��� ��ü�� �ڽ� Ŭ�������� �������̵� �Ͽ� ������
	void bark() { cout << "Woof!" << endl; };
};

class Cat : public Animal {
public:
	//�����Լ��� ��ü�� �ڽ� Ŭ�������� �������̵� �Ͽ� ������
	//Dog���� �ٸ� ����� �����
	void bark() { cout << "Meaw~" << endl; };
};

int main(int argc, char const* argv[])
{
	//�� Ŭ������ ��ü�� ���� �Ҵ����ش�.
	//Animal�� ���� ���� �Լ��� �����Ƿ� ��ü�� ������ �� ����.
	Dog* myDog = new Dog;
	Cat* myCat = new Cat;

	//�����͸� �̿��� �Լ� ȣ���� ���ش�.
	//�����Լ��� ����Ͽ��� ������ �� Ŭ������ �Լ��� ���������� ��µȴ�.
	myDog->bark();
	myCat->bark();
	return 0;
}