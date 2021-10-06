#include <iostream>

using namespace std;
//Animal�̶�� Ŭ������ �����Ѵ�
class Animal {
//�ڽ�Ŭ������ �������� �������� ������ �����.
private:
	float size = 1.0f;
	float speed = 3.0f;
	float loudness = 5.0f;
	char name[20] = {};

public:
	//���� ������ ������ �� �ְ� �Լ��� �������ش�.
	//������ �Ķ���ͷ� ������ ���� �ʰ� ���� ��ȯ�ϴ� �ɼǵ� �־���
	float ChangeTraits(int traits = 0, float value = 0, bool change = 0) {
		if (change) {
			switch (traits)
			{
			case 1:
				this->size = value;
				return this->size;
			case 2:
				this->speed = value;
				return this->speed;
			case 3:
				this->loudness = value;
				return this->loudness;
			default:
				cout << "1. Size" << endl << "2. Speed" << endl << "3. Loudness" << endl;
				return 0;
				break;
			}
		}
		else {
			switch (traits)
			{
			case 1:
				return this->size;
			case 2:
				return this->speed;
			case 3:
				return this->loudness;
			default:
				cout << "1. Size" << endl << "2. Speed" << endl << "3. Loudness" << endl;
				return 0;
				break;
			}
		}
	}
	//�̸��� ���� �����ϰ� �Լ��� �����Ѵ�.
	const char* ChangeName(const char* _input) {
		//�μ��� ������ ������ �̸��� ��ȯ��Ų��.
		if (_input == NULL) {
			return this->name;
		}
		else {
			strcat_s(this->name, _input);
			return this->name;
		}
	}
	//������ �������� ǥ���ϴ� �Լ�
	void move(int direction) {
		cout << name << " " << "move to ";
		switch (direction)
		{
		case 1:
			cout << "forward" << endl;
			break;
		case 2:
			cout << "right" << endl;
			break;
		case 3:
			cout << "left" << endl;
			break;
		case 4:
			cout << "backward" << endl;
			break;
		default:
			cout << "forward" << endl;
			break;
		}
	}

	//������ ���븦 ǥ���ϴ� �Լ�
	void Eat() {
		cout << name << "ate something" << endl;
	}
	Animal() {

	};
	~Animal() {

	};
};

//DogŬ������ Animal���� ����� �޴´ٰ� ǥ�ø� �Ѵ�.
class Dog : public Animal {
private:
	//Animal���� ���þ��� �������� ����
	int furlength = 0;
	int race = 0;
public:
	//Animal���� ���þ��� �������� �Լ�
	float bark() {
		//���Ǹ� ���� Loud��� ������ �����Ͽ� �θ� Ŭ������ �ִ� Loudness�� ���Խ�Ų��. 
		float loud = Animal::ChangeTraits(3, 0, false);
		//Loud�� ����ؼ� ��� Ƚ�� ����
		for (float i = 0; i < loud; i++) {
			cout << "Bark!";
		}
		cout << endl;
		return loud;
	}
	Dog() {

	};
	~Dog() {

	};
};
class Chicken : public Animal {
private:
	int featherColor[3] = { 0, 0, 0 };
public:
	float crowing() {
		float loud = Animal::ChangeTraits(3, 0, false);
		for (float i = 0; i < loud; i+=3) {
			cout << "Cock-a-doodle-doo!";
		}
		cout << endl;
		return loud;
	}
	Chicken() {

	};
	~Chicken() {

	};
};
class Cat : public Animal {
private:
	int furPattern = 0;
public:
	float meow() {
		float loud = Animal::ChangeTraits(3, 0, false);
		for (float i = 0; i < loud; i+=0.6) {
			cout << "Meow";
		}
		cout << endl;
		return loud;
	}
	//move��� �Լ��� �̹� �θ�Ŭ������ ����Ǿ������� �Լ� �������̵����� �ٽ� �������ָ�
	//�� Ŭ���� �ȿ����� �ٸ��� �۵��ϰ� �� �� �ִ�.
	void move(short direction) {
		cout << Animal::ChangeName("") << " " << "Jumped to ";
		switch (direction)
		{
		case 1:
			cout << "forward" << endl;
			break;
		case 2:
			cout << "right" << endl;
			break;
		case 3:
			cout << "left" << endl;
			break;
		case 4:
			cout << "backward" << endl;
			break;
		default:
			cout << "forward" << endl;
			break;
		}
	}
	Cat() {

	};
	~Cat() {

	};
};
int main() {
	/*Animal TestAnimal;
	cout << TestAnimal.ChangeName("TestName") << endl;
	TestAnimal.ChangeTraits();
	cout << TestAnimal.ChangeTraits(2, 10.0f, true) << endl;*/

	Dog TestDog;
	TestDog.ChangeName("GoldenRetriever");
	TestDog.ChangeTraits(3, 8.5f, true);
	TestDog.bark();
	TestDog.move(1);
	cout << endl;
	Chicken TestChicken;
	TestChicken.crowing();
	cout << endl;
	Cat TestCat;
	TestCat.ChangeName("KoreanShortHair");
	TestCat.ChangeTraits(3, 2.0f, true);
	TestCat.meow();
	TestCat.move(1);
	return 0;
}