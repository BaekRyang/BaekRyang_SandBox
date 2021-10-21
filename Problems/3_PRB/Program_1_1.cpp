#include <iostream>
using namespace std;
//초기화 리스트 사용
class Car
{
	int speed;

public:
	//초기화 리스트를 사용하여 멤버 변수를 초기화 한다.
	Car(int s) : speed(s) {};
	//speed는 private이기 때문에 현재 속도를 반환해 주는 함수 생성
	int NowSpeed() {
		return speed;
	}
	//속도를 1씩 증가시켜주는 함수
	void Accelerate() {
		speed++;
	}
};

class SportCar : public Car
{
	bool turbo;
public:
	//Car가 초기화 리스트를 사용중이기 때문에
	//SportCar가 Car의 생성자를 이용하여 부모클래스의 멤버변수인 speed를 초기화 할 수있다.
	//이후 turbo는 마찬가지로 초기화 리스트를 사용하여 초기화 해 준다.
	SportCar(int s, bool t) : Car(s), turbo(t) {};
	//Car에서 Acceleate()가 이미 정의 되어있지만,
	//자식 클래스에서 다른 기능을 할 수 있도록, 함수를 재 정의 해준다.
	void Accelerate() {
		Car::Accelerate();
		if (turbo)Car::Accelerate();
	}
};

int main(int argc, char const* argv[])
{
	//Car는 Acclerate()시 speed가 1씩 증가한다.
	Car DefaultCar(0);
	DefaultCar.Accelerate();
	cout << "NOW SPEED : " << DefaultCar.NowSpeed() << endl;
	DefaultCar.Accelerate();
	cout << "NOW SPEED : " << DefaultCar.NowSpeed() << endl;
	
	cout << endl;

	//SportCar는 Acclerate()시 turbo가 1일경우 speed가 2씩 증가하게
	//다른 기능을 갖게 되었다.
	SportCar MyCar(0, 1);
	MyCar.Accelerate();
	cout << "NOW SPEED : " << MyCar.NowSpeed() << endl;
	MyCar.Accelerate();
	cout << "NOW SPEED : " << MyCar.NowSpeed() << endl;

	return 0;
}