#include <iostream>

using namespace std;

//클래스를 정의하는 방법
class SampleClass //클래스이름

{
//외부에서 접근이 불가능한 영역, "캡슐화"를 위해서 필요함.
//클래스의 캡슐화는 데이터를 보호하거나 잘못 사용하는 것을 막을 수 있다. (너무 많은 정보를 제공하여 혼란이 생기는 것을 막음)
private: 
	int privateValue = 0;

//외부에서 접근이 가능한 영역
public:
	int publicValue = 0;
	//생성자 : 객체가 생성될 때 발동하는 함수
	//객체가 생성될때 인수를 받을 수 있으므로 생성자도 인수를 받을 수 있다.
	//만약 생성자를 따로 구현하지 않으면 기본 생성자가 사용되며, 기본생성자는 매개변수가 없으며 멤버변수는 0, NULL 로 초기화 된다.
	SampleClass() {
		cout << "객체가 생성되었습니다." << endl;
	};
	//인수를 받을수 있기 때문에 Overloading도 가능하다. (여러개의 생성자가 존재가능)
	SampleClass(int _input) {
		cout << _input << "객체가 생성되었습니다." << endl;
	};

	//소멸자 : 객체가 소멸할 때 발동하는 함수
	//생성자와는 다르게 인수를 받을 수 없으며 그렇기 때문에 소멸자는 단 하나만 존재 가능하다.
	~SampleClass() {
		cout << "객체가 소멸하였습니다." << endl;
	};

};


//2. 클래스로 객체를 생성하는 방법
int main() {
	//클래스는 구조체와 같이 자료형 처럼 사용할 수 있다.
	//"클래스이름 인스턴스이름"
	SampleClass SampleInstance_1;
	//필요에 의해서 인수를 추가 할 수 도 있다.
	SampleClass SampleInstance_2(20);

	//소멸자는 클래스가 사용된 인스턴스가 소멸할 때 호출되기 때문에 이번 경우에는
	//main함수가 끝날때 인스턴스가 선언된 순서로 소멸자가 호출된다.
	return 0;
}