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

	Character() { cout << "������ : Character ������" << endl; }
	~Character() { cout << "�Ҹ��� : Character �Ҹ��" << endl; }
};


int main() {
	Character* newCha = new Character;

	cout << newCha << endl;
	//�����Ҵ���� �ٸ��� ->�� ����ؼ� �Լ��� ������ �����Ѵ�.
	cout << newCha->Attack() << endl;
	newCha->afk = true;

	//newCha�� �����Ѵ�.
	delete(newCha);
	/*
	newCha�� �޸𸮸� �����Ͽ��� ������
	"�ʱ�ȭ �������� �޸� 'newCha'�� ����ϰ� �ֽ��ϴ�."
	��� ��� �߻��Ѵ�.
	*/
	cout << newCha << endl;


	return 0;
}
	

