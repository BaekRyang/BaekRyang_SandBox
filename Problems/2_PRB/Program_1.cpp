#include <iostream>

using namespace std;

//int형과 short형의 덧셈을 반환하는 함수
//int와 short를 더했을때 값이 short의 범위를 초과할 가능성이 많기 때문에
//데이터의 유실을 막기위해 더 큰 자료형인 int로 반환 자료형을 사용한다.
int add(int _inputI, short _inputS) {
	return _inputI + _inputS;
}

//위와 동일하게 다른 자료형끼리 더하는 함수다.
//이것도 더 큰 자료형인 double을 반환자료형으로 사용한다.
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
	//STRING끼리 더한다면 단순히 String안의 내용을 이어붙인 값이 나온다.
	cout << add(string1, string2) << endl;
}

