#include <iostream>

using namespace std;

//�Ķ���ͷ� ����ü�� ����Ϸ��� �ϴµ�
//�پ��� Ư���� �ϳ��� ���� ���� ����ü�� ����Ѵ�.
struct Creture
{
	char name[10];
	int hp = 100;
	int def = 10;
};

//�������� ���ϴ� �Լ��� �����Ѵ�.
//�� �Լ������� ���� ����� �Ѵ�.
int Damage(Creture *target, int _damage) {
	target->hp -= _damage - target->def;
	cout << target->name << "���� " << _damage << "�� ���ظ� ��������" << endl;
	cout << target->def << "��ŭ ����߽��ϴ�." << endl;
	return target->hp;
}

//�Լ� �����ε����� ���� �̸��� �Լ��� �� �ϳ������.
//�̹� �Լ������� bool�Ķ���͸� �޾� ���� ����� ���� �ʵ��� �Ѵ�.
int Damage(Creture *target, int _damage, bool _isTrue) {
	target->hp -= _damage;
	cout << target->name << "���� " << _damage << "�� ���ظ� �������ϴ�." << endl;
	cout << "������" << target->def << "������, ������� ���߽��ϴ�." << endl;
	return target->hp;
}

int main() {
	Creture Player;
	strcpy_s(Player.name, "Player");
	cout << "���� HP : " << Player.hp << " -> " << Damage(&Player, 15) << endl;
	cout << "���� HP : " << Player.hp << " -> " << Damage(&Player, 15, true) << endl;
}

