#include <iostream>

using namespace std;

//파라미터로 생물체를 사용하려고 하는데
//다양한 특성을 하나로 묶기 위해 구조체를 사용한다.
struct Creture
{
	char name[10];
	int hp = 100;
	int def = 10;
};

//데미지를 가하는 함수를 생성한다.
//이 함수에서는 방어력 계산을 한다.
int Damage(Creture *target, int _damage) {
	target->hp -= _damage - target->def;
	cout << target->name << "에게 " << _damage << "의 피해를 입혔지만" << endl;
	cout << target->def << "만큼 방어했습니다." << endl;
	return target->hp;
}

//함수 오버로딩으로 같은 이름의 함수를 또 하나만든다.
//이번 함수에서는 bool파라미터를 받아 방어력 계산을 하지 않도록 한다.
int Damage(Creture *target, int _damage, bool _isTrue) {
	target->hp -= _damage;
	cout << target->name << "에게 " << _damage << "의 피해를 입혔습니다." << endl;
	cout << "방어력이" << target->def << "이지만, 방어하지 못했습니다." << endl;
	return target->hp;
}

int main() {
	Creture Player;
	strcpy_s(Player.name, "Player");
	cout << "남은 HP : " << Player.hp << " -> " << Damage(&Player, 15) << endl;
	cout << "남은 HP : " << Player.hp << " -> " << Damage(&Player, 15, true) << endl;
}

