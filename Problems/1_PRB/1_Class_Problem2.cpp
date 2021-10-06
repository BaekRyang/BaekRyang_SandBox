#include <iostream>

using namespace std;

//클래스 선언
class MyArray
{
private:;
	   int* arrayLocation = 0;
	   int arraySize = 0;
public:
	MyArray() {};
	~MyArray() {};

	//배열을 특정 값으로 채웁니다.
	void fillArray(int _input) {
		for (int i = 0; i < arraySize; i++) {
			arrayLocation[i] = _input;
		}
	}
	//배열 안에 있는값들을 출력합니다.
	void PrintArray() {
		for (int i = 0; i < arraySize; i++) {
			cout << arrayLocation[i] << endl;
		}
	}
	//함수를 통해서 배열을 동적할당한다.
	void CreateArray(int _input) {
		arrayLocation = new int[_input];
		arraySize = _input;
	}
	//할당된 배열의 주소값을 반환시킨다.
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

