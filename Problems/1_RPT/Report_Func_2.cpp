#include <iostream>

using namespace std;

//객체를 함수의 매개변수로 전달하기

//기본적인 함수에 매개변수를 객체로 전달하게 된다면
//함수는 그것의 값을 복사하여 사용하기 때문에
//함수 안에서 그 값이 변하더라도 밖에서는 값이 변하지 않는다.
//이것을 Call by Value라고 한다.

//Call by Value는 원래 함수의 값에 접근할 수 없기 떄문에 매개변수의 값이 보존이 되지만
//복사를 하기 때문에 메모리의 사용량이 늘어난다는 단점이 있다.

//함수에 객체 자체를 전달하는 방법은 두가지가 있다.

//1. 포인터를 통해 Call by address를 사용
//Call by Address는 주소값 자체를 복사해서 넘겨주므로 Call by Value라고 볼 수있다.
//Call by Value는 복사하는 것이기 때문에 원래 변수의 값이 변하지 않는것으로 생각할 수 있지만,
//Call by Address는 결국 그 주소값을 참조하기 떄문에 값이 변하게 된다.
void EscalateNum(int* _input) {
	//_input자체는 주소값을 가리키기 때문에 "*_input"으로 _input의 값을 가리켜야한다.
	(*_input)++;
}

//CallbyReferance는 복사하지 않고 직접참조를 하기 때문에 실행속도가 빠르지만
//함수안에서 값이 변할 수 있기에 주의해야 한다.

int main() {
	int value = 10;
	cout << value << endl;
	//이 함수에는 주소값을 넘겨줘야 하기 때문에 "&"를 붙여준다.
	EscalateNum(&value);
	cout << value << endl;

	return 0;
}

