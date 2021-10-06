#include <iostream>
using namespace std;

//초기화 리스트 미사용
class Car
{
	int speed;
public:
	Car() {};
	//이번에는 인수로 받은 값을 복사하여 speed에 할당을 해준다.
	Car(int s) { speed = s; };
	//이번 예시에는 없지만 이런 방식을 쓰면 안되는 경우가 있다.
	//바로 선언과 동시에 초기화를 해야하는 데이터들인데 const 및 참조변수가 있다.
	//이 두가지를 입력을 받아 초기화를 하기 위해서는 초기화 리스트를 사용해야한다.
	void Accelerate() {
		speed++;
	}
	//이번에는 초기화리스트로 멤버변수 초기화를 하지 않았으므로
	//speed를 수정, 반환하는 함수를 만들어준다.
	int SpeedValue(int amount = 0, bool isChange = false) {
		if (isChange) {
			speed = amount;
		}
		return speed;
	}
	
};

class SportCar : public Car
{
	bool turbo;
public:
	//Car의 생성자는 이미 실행이 끝났기 때문에 호출 할 수 없다.
	//그렇기 때문에 SpeedValue()로 직접 할당을 해 줘야한다.
	SportCar(int s, bool t) {
		SpeedValue(s, 1);
		turbo = t;
	};
	void Accelerate() {
		int nowSpeed = SpeedValue();
		if (turbo) {
			SpeedValue(++nowSpeed, 1);
		}
		SpeedValue(++nowSpeed, 1);
	}
};

int main(int argc, char const* argv[])
{
	//정상적으로 작동 한다.
	SportCar MyCar(0, true);
	cout << "NOW SPEED : " << MyCar.SpeedValue() << endl;
	MyCar.Accelerate();
	cout << "NOW SPEED : " << MyCar.SpeedValue() << endl;
	return 0;
}