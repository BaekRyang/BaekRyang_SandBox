#include <iostream>

using namespace std;

//클래스 선언
class GameCharacter {
public:
	//기본생성자의 인수로 bool값이 들어왔을때
	GameCharacter(bool defValue) {
		if (defValue) {
			//true면 default값을 넣어준다.
			changeStatus(100, 10, 10, 0);
		}
			//false이면 특수한 값이 넣어준다.
		else {
			changeStatus(1, 1, 1, 0);
		}

	};
	//함수 오버로드
	//인수로 int값이 들어왔을때
	GameCharacter(int clsCode) {
		//Switch문으로 파라매터에 따라 다른 값을 설정한다.
		switch (clsCode)
		{
		case 1:
			changeStatus(200, 20, 5, 1);
			break;

		case 2:
			changeStatus(80, 8, 20, 2);
			break;

		case 3:
			changeStatus(150, 15, 7, 3);
			break;

		default:
			changeStatus(100, 10, 10, 0);
			break;
		}
	};
	~GameCharacter() {

	}

	//현재의 값을 반환시켜주는 함수
	int returnStatus(int type) {
		switch (type)
		{
		case 1:
			return this->health;
			break;

		case 2:
			return this->def;
			break;

		case 3:
			return this->pow;
			break;

		default:
			return this->clsCode;
			break;
		}
	};

	//캡슐화를 위해 private공간에 선언한다.
private:
	int clsCode, health, def, pow;
	void changeStatus(int health, int def, int pow, int clsCode) {
		this->health = health;
		this->def = def;
		this->pow = pow;
		this->clsCode = clsCode;
	}
};

int main() {
	//완료된 결과 확인
	GameCharacter Player1(true);
	cout << "Player1 HP : " << Player1.returnStatus(1) << endl;
	cout << "Player1 DEF : " << Player1.returnStatus(2) << endl;
	cout << "Player1 POW : " << Player1.returnStatus(3) << endl;
	cout << endl;

	GameCharacter Player2(2);
	cout << "Player2 HP : " << Player2.returnStatus(1) << endl;
	cout << "Player2 DEF : " << Player2.returnStatus(2) << endl;
	cout << "Player2 POW : " << Player2.returnStatus(3) << endl;

	return 0;
}