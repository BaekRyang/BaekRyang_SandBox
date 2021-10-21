#include <iostream>

using namespace std;

//생성자를 이용하여 멤버변수를 초기화하는 방법
class SampleClass 

{
private:
	//이 클래스에는 객체가 
	int firstValue = 0;
	int secondValue = 0;
	int thirdValue = 0;


public:
	SampleClass() {
	};
	//생성자를 통해서 멤버변수를 초기화 하는 방법도 있다.
	//생성자를 통해서 초기화 하는 경우에는 인수를 받아서 하는 경우가 많다.
	//초기화 방법은 생성자 뒤에 콜론(:)을 표기한 뒤 "초기화할변수(설정할값)" 처럼 초기화 할 수 있다.
	SampleClass(int _input1, int _input2, int _input3) : firstValue(_input1), secondValue(_input2), thirdValue(_input3) {
		cout << firstValue << endl << secondValue << endl << thirdValue << endl;
	};

	~SampleClass() {
	};

};

int main() {
	//클래스안 변수는 기본적으로 0으로 설정되어있지만 인수를 입력함으로 (10, 20, 30)으로 초기화 할 수 있다.
	SampleClass SampleInstance(10, 20, 30);
}

