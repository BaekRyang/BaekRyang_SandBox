#include <iostream>

using namespace std;

//�����ڸ� �̿��Ͽ� ��������� �ʱ�ȭ�ϴ� ���
class SampleClass 

{
private:
	//�� Ŭ�������� ��ü�� 
	int firstValue = 0;
	int secondValue = 0;
	int thirdValue = 0;


public:
	SampleClass() {
	};
	//�����ڸ� ���ؼ� ��������� �ʱ�ȭ �ϴ� ����� �ִ�.
	//�����ڸ� ���ؼ� �ʱ�ȭ �ϴ� ��쿡�� �μ��� �޾Ƽ� �ϴ� ��찡 ����.
	//�ʱ�ȭ ����� ������ �ڿ� �ݷ�(:)�� ǥ���� �� "�ʱ�ȭ�Һ���(�����Ұ�)" ó�� �ʱ�ȭ �� �� �ִ�.
	SampleClass(int _input1, int _input2, int _input3) : firstValue(_input1), secondValue(_input2), thirdValue(_input3) {
		cout << firstValue << endl << secondValue << endl << thirdValue << endl;
	};

	~SampleClass() {
	};

};

int main() {
	//Ŭ������ ������ �⺻������ 0���� �����Ǿ������� �μ��� �Է������� (10, 20, 30)���� �ʱ�ȭ �� �� �ִ�.
	SampleClass SampleInstance(10, 20, 30);
}

