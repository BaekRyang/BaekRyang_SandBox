#include <iostream>

using namespace std;

//int���� short���� ������ ��ȯ�ϴ� �Լ�
//int�� short�� �������� ���� short�� ������ �ʰ��� ���ɼ��� ���� ������
//�������� ������ �������� �� ū �ڷ����� int�� ��ȯ �ڷ����� ����Ѵ�.
int add(int _inputI, short _inputS) {
	return _inputI + _inputS;
}

//���� �����ϰ� �ٸ� �ڷ������� ���ϴ� �Լ���.
//�̰͵� �� ū �ڷ����� double�� ��ȯ�ڷ������� ����Ѵ�.
double add(float _inputF, double _inputD) {
	return _inputF + _inputD;
}

string add(string _input1, string _input2) {
	return _input1 + _input2;
}

int main() {
	short numberS = 10;
	int numberI = 100000;
	float numberF = 150.5;
	double numberD = 200.725;
	string string1 = "STR 1";
	string string2 = "STR 2";

	cout << add(numberI, numberS) << endl;
	cout << add(numberF, numberD) << endl;
	//STRING���� ���Ѵٸ� �ܼ��� String���� ������ �̾���� ���� ���´�.
	cout << add(string1, string2) << endl;
}

