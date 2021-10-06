#include <iostream>

using namespace std;

//함수에 배열을 전달하는 방법

//배열은 메모리 상에서도 연속적인 메모리 주소를 갖는다.
//그렇기 때문에 배열은 제일 처음의 메모리 주소만 안다면 다른 배열에도 접근이 가능하다.
//주소값을 넘기기 위해 함수의 인수에 주소값을 받아올 수 있게 "*"을 사용한다.
void PrintNumArray(int* _array, int _len) {
	for (int i = 0; i < _len; i++) {
		cout << *(_array + i) << endl; //배열 주소값은 연속적이기 때문에 주소값에 수를 더하면 그만큼의 다음 배열에 접근할 수있다.
	}
}

//이 함수는 _len을 사용하지 않는다.
//문자열 배열은 마지막에 NULL이 무조건 오기 때문에 
//자동으로 \0를 만날때까지 문자를 자동으로 출력하게 된다.
void PrintCharArray(char* _array) {
	cout << _array << endl;
}

int main() {
	//크기가 10인 배열을 선언해 (1~10)로 초기화 시킨다.
	int intArray[10] = { 1,2,3,4,5,6,7,8,9 ,10};
	//일반 함수의 주소값을 넘길때랑은 다르게 배열을 넘길때는 "&"을 사용하지 않는다.
	//그 이유는 배열의 이름은 첫번째 배열의 주소값을 가리키기 때문에 그렇다.
	PrintNumArray(intArray, 10); 

	//다음으로 문자열 배열을 선언하여 초기화 한다.
	char charArray[12] = { "Hello_World" };
	PrintCharArray(charArray);
}

