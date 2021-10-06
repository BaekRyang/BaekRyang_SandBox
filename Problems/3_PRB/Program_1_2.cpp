#include <iostream>
using namespace std;

//�ʱ�ȭ ����Ʈ �̻��
class Car
{
	int speed;
public:
	Car() {};
	//�̹����� �μ��� ���� ���� �����Ͽ� speed�� �Ҵ��� ���ش�.
	Car(int s) { speed = s; };
	//�̹� ���ÿ��� ������ �̷� ����� ���� �ȵǴ� ��찡 �ִ�.
	//�ٷ� ����� ���ÿ� �ʱ�ȭ�� �ؾ��ϴ� �����͵��ε� const �� ���������� �ִ�.
	//�� �ΰ����� �Է��� �޾� �ʱ�ȭ�� �ϱ� ���ؼ��� �ʱ�ȭ ����Ʈ�� ����ؾ��Ѵ�.
	void Accelerate() {
		speed++;
	}
	//�̹����� �ʱ�ȭ����Ʈ�� ������� �ʱ�ȭ�� ���� �ʾ����Ƿ�
	//speed�� ����, ��ȯ�ϴ� �Լ��� ������ش�.
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
	//Car�� �����ڴ� �̹� ������ ������ ������ ȣ�� �� �� ����.
	//�׷��� ������ SpeedValue()�� ���� �Ҵ��� �� ����Ѵ�.
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
	//���������� �۵� �Ѵ�.
	SportCar MyCar(0, true);
	cout << "NOW SPEED : " << MyCar.SpeedValue() << endl;
	MyCar.Accelerate();
	cout << "NOW SPEED : " << MyCar.SpeedValue() << endl;
	return 0;
}