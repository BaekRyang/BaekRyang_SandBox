#include <iostream>

using namespace std;

// 객체의 참조자를 함수의 매개변수로 전달이 가능한가

//포인터를 이용하지 않고도 매개변수로 받은 변수의 값을 바꿀 수 있는 방법이 또 있다.
//참조변수를 함수에 매개변수로 전달하는 것 인데,

//함수의 모양은 일반적으로 만들지만 "int&"처럼 참조변수를 받음을 표시한다.
//이렇게 한다면 값을 복사하지 않으므로 Call by Referance라고 한다.
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
	//refValue를 매개변수로 넘겨주어 값을 상승시켜도 value값이 바뀐다.
	cout << value << endl;

	return 0;
}

