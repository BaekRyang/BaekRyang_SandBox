#include <iostream>
#include <string>
using namespace std;


//시작에 앞서 모든 클래스의 소멸자가 "LinkError 1120 : 확인할 수 없는 외부 참조입니다." 가 발생함
//소멸자에 함수가 선언되어있지 않기 때문에 생기는 오류로 확인하고 소멸자를 사용하지 않을 예정이기 떄문에
//모든 클래스의 소멸자를 제거함
class Person {
	string name;
	string address;
	string tel;
public:
	//우선 Person이 가지는 기본적인 정보를 초기화 리스트를 사용하여 넣어준다.
	Person(string nm, string addr, string t) : name(nm), address(addr), tel(t) {};
	//기본적인 신상을 출력하는 함수를 만들어준다.
	void Infomations() {
		cout << "Hello! My name is \"" << name << "\"" << endl
			<< "My Address is \"" << address << "\"" << endl
			<< "and My Telephone-Number is \"" << tel << "\"" << endl;
	};
	//순수 가상함수 생성
	//이 함수가 있음으로 인해 Person이라는 객체는 생성할 수 없다.
	virtual void meet() = 0;
};

class Professor : public Person
{
public:
	//기본적인 신상정보를 입력하기 위해 인수로 받은 정보들을 Person의 생성자에 넘겨줘서
	//멤버변수를 초기화 한다.
	Professor(string nm, string addr, string t) : Person(nm, addr, t) {};
	void teach() {
		cout << "Now teaching...";
		for (int i = 0; i < 3; i++) {
			cout << "..";
		}
		cout << endl << "Teaching Ended" << endl;
	};
	//가상함수로 선언된 meet()를 각 자식 클래스에 선언해준다.
	//만약 meet를 정의하지 않고 컴파일시 추상클래스를 인스턴스화 할 수 없다고 한다.
	void meet() {
		cout << "The professor is meeting another professor" << endl;
	};
};

class TennisPlayer : public Person
{
public:
	TennisPlayer(string nm, string addr, string t) : Person(nm, addr, t) {};
	void playTennis() {
		cout << "Now playing tennis...";
		for (int i = 0; i < 3; i++) {
			cout << "Tack!..";
		}
		cout << endl << "Play tenis Ended" << endl;
	};
	void meet() {
		cout << "The TennisPlayer is meeing Head Coach " << endl;
	};
};

class Businessman : public Person
{
public:
	Businessman(string nm, string addr, string t) : Person(nm, addr, t) {};
	void runBusiness() {
		cout << "Now Businessing...";
		for (int i = 0; i < 3; i++) {
			cout << "walk..";
		}
		cout << endl << "My Business Ended" << endl;
	};
	//함수 오버라이딩을 통해 이 클래스에서만 다른 역할을 하게 재 정의 할 수 있다.
	void Infomations() {
		cout << endl << "My Infomations is Secreat" << endl;
	};
	void meet() {
		cout << "The Businessman is meeting Family" << endl;
	};
};

int main() {
	//객체 생성
	Professor pfs("Gwon Yeji", "Afreeca", "010-aaaa-aaaa");
	TennisPlayer tnp("Kim Minwoo", "Korea", "010-bbbb-bbbb");
	Businessman bsm("Park Chungkyu", "China", "010-cccc-cccc");
	//신상 정보들을 입력해준다.

	//각 클래스마다 할 수 있는 작업들이 다르다.
	pfs.teach();
	cout << endl;
	tnp.playTennis();
	cout << endl;
	bsm.runBusiness();
	cout << endl;

	//가상함수로 선언된 함수를 사용
	pfs.meet();
	tnp.meet();
	bsm.meet();
	cout << endl;

	//부모에게 상속받은 함수 사용
	pfs.Infomations();
	tnp.Infomations();
	bsm.Infomations(); //재 정의되었기 때문에 다른 결과가 나온다.
}