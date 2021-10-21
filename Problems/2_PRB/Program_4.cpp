#include <iostream>

using namespace std;

class Character {
private:
	int hp = 100;
	int str = 10;
	int exp = 25;

public:
	bool afk = false;

	bool Attack() {
		cout << "SWING!"<< endl;
		cout << "You Attacked and dealt " << str << " Damage" << endl;
		return true;
	}

	Character() { cout << "생성자 : Character 생성됨" << endl; }
	~Character() { cout << "소멸자 : Character 소멸됨" << endl; }
};


int main() {
	Character* newCha = new Character;

	cout << newCha << endl;
	//정적할당과는 다르게 ->를 사용해서 함수와 변수에 접근한다.
	cout << newCha->Attack() << endl;
	newCha->afk = true;

	//newCha를 해제한다.
	delete(newCha);
	/*
	newCha의 메모리를 해제하였기 때문에
	"초기화 되지않은 메모리 'newCha'를 사용하고 있습니다."
	라는 경고가 발생한다.
	*/
	cout << newCha << endl;


	return 0;
}
	

