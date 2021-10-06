#include <iostream>

using namespace std;
//Animal이라는 클래스를 선언한다
class Animal {
//자식클래스도 공통으로 가질만한 변수를 만든다.
private:
	float size = 1.0f;
	float speed = 3.0f;
	float loudness = 5.0f;
	char name[20] = {};

public:
	//내부 변수를 수정할 수 있게 함수를 생성해준다.
	//마지막 파라메터로 변경을 하지 않고 값만 반환하는 옵션도 넣어줌
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
	//이름도 변경 가능하게 함수를 생성한다.
	const char* ChangeName(const char* _input) {
		//인수로 공백이 들어오면 이름을 반환시킨다.
		if (_input == NULL) {
			return this->name;
		}
		else {
			strcat_s(this->name, _input);
			return this->name;
		}
	}
	//동물의 움직임을 표현하는 함수
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

	//동물의 섭취를 표현하는 함수
	void Eat() {
		cout << name << "ate something" << endl;
	}
	Animal() {

	};
	~Animal() {

	};
};

//Dog클래스는 Animal에게 상속을 받는다고 표시를 한다.
class Dog : public Animal {
private:
	//Animal과는 관련없는 독자적인 변수
	int furlength = 0;
	int race = 0;
public:
	//Animal과는 관련없는 독자적인 함수
	float bark() {
		//편의를 위해 Loud라는 변수를 생성하여 부모 클래스에 있는 Loudness를 대입시킨다. 
		float loud = Animal::ChangeTraits(3, 0, false);
		//Loud에 비례해서 출력 횟수 조정
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
	//move라는 함수는 이미 부모클래스에 선언되어있지만 함수 오버라이딩으로 다시 선언해주면
	//이 클래스 안에서는 다르게 작동하게 할 수 있다.
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