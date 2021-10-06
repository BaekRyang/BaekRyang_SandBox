#include <iostream>

using namespace std;

//������ �迭�� �����ִ� Ŭ����
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

//�Ǽ��� �迭�� �����ִ� Ŭ����
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

//������ �迭�� �����ִ� Ŭ����
class CharArr {
private:
	char value[10] = { 0 };
public:
	//���ڸ� �μ��� �޾Ƶ��̱� ���� "const char *"  ���
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

//������� Ŭ���� Ȯ��
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

