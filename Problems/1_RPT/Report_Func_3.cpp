#include <iostream>

using namespace std;

// ��ü�� �����ڸ� �Լ��� �Ű������� ������ �����Ѱ�

//�����͸� �̿����� �ʰ� �Ű������� ���� ������ ���� �ٲ� �� �ִ� ����� �� �ִ�.
//���������� �Լ��� �Ű������� �����ϴ� �� �ε�,

//�Լ��� ����� �Ϲ������� �������� "int&"ó�� ���������� ������ ǥ���Ѵ�.
//�̷��� �Ѵٸ� ���� �������� �����Ƿ� Call by Referance��� �Ѵ�.
void EscalateNum(int& _input) {
	cout << "Func : " << _input << endl;
	_input++;
	cout << "Func : " << _input << endl;
}

int main() {
	int value = 10;
	int& refValue = value;

	cout << value << endl;
	EscalateNum(refValue);
	//refValue�� �Ű������� �Ѱ��־� ���� ��½��ѵ� value���� �ٲ��.
	cout << value << endl;

	return 0;
}

