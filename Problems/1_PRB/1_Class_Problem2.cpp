#include <iostream>

using namespace std;

//Ŭ���� ����
class MyArray
{
private:;
	   int* arrayLocation = 0;
	   int arraySize = 0;
public:
	MyArray() {};
	~MyArray() {};

	//�迭�� Ư�� ������ ä��ϴ�.
	void fillArray(int _input) {
		for (int i = 0; i < arraySize; i++) {
			arrayLocation[i] = _input;
		}
	}
	//�迭 �ȿ� �ִ°����� ����մϴ�.
	void PrintArray() {
		for (int i = 0; i < arraySize; i++) {
			cout << arrayLocation[i] << endl;
		}
	}
	//�Լ��� ���ؼ� �迭�� �����Ҵ��Ѵ�.
	void CreateArray(int _input) {
		arrayLocation = new int[_input];
		arraySize = _input;
	}
	//�Ҵ�� �迭�� �ּҰ��� ��ȯ��Ų��.
	int* PrintArrayLoc() {
		return arrayLocation;
	}
};

int main() {
	MyArray newArray;
	newArray.CreateArray(10);
	newArray.fillArray(10);
	newArray.PrintArray();
	int* array = newArray.PrintArrayLoc();
	cout << array << endl;;
	return 0;
}

