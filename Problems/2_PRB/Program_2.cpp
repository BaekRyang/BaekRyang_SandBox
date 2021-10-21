#include <iostream>

using namespace std;

//정수형 배열을 갖고있는 클래스
class IntegerArr {
private:
	int value[10] = { 0 };

public:
	void SetValue(int _value, int _order) {
		this->value[_order] = _value;
	}
	void PrintValue() {
		for (int i = 0; i < 10; i++) {
			cout << this->value[i] << ", ";
		}
		cout << endl;
	}
	IntegerArr() {}
	~IntegerArr() {}
};

//실수형 배열을 갖고있는 클래스
class RealArr {
private:
	float value[10] = { 0 };

public:
	void SetValue(float _value, int _order) {
		this->value[_order] = _value;
	}
	void PrintValue() {
		for (int i = 0; i < 10; i++) {
			cout << this->value[i] << ", ";
		}
		cout << endl;
	}
	RealArr() {}
	~RealArr() {}
};

//문자형 배열을 갖고있는 클래스
class CharArr {
private:
	char value[10] = { 0 };
public:
	//문자를 인수로 받아들이기 위해 "const char *"  사용
	void SetValue(const char *_value, int _order) {
		this->value[_order] = *_value;
	}
	void PrintValue() {
		for (int i = 0; i < 10; i++) {
			cout << this->value[i] << ", ";
		}
		cout << endl;
	}
	CharArr() {}
	~CharArr() {}
};

//만들어진 클래스 확인
int main() {
	IntegerArr IA;
	IA.SetValue(10, 1);
	IA.PrintValue();
	RealArr RA;
	RA.SetValue(10.1, 1);
	RA.PrintValue();
	CharArr CA;
	CA.SetValue("A", 1);
	CA.PrintValue();
	return 0;
}

