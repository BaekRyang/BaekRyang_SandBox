#include <iostream>
using namespace std;

class TwoDimension
{
	double x, y;
public:
	//�ʱ�ȭ ����Ʈ�� ����Ͽ� ��� ������ �ʱ�ȭ ���ص�, �ʱ�ȭ �� ���� ����Ѵ�.
	TwoDimension(double i, double j) : x(i), y(j) { cout << endl << this->x << ":" << y; };
};

//TwoDimension�� �ִ� x,y�� ����ϱ� ���� ����� �����ش�.
//ThreeDimension�� TwoDimension()�� ��� �� �� ������ private�� ��� �����ڸ� �����Ѵ�.
class ThreeDimension : private TwoDimension
{
	double z;
public:
	//TwoDimension�� �ʱ�ȭ ����Ʈ�� ����ϰ� �ֱ� ������
	//ThreeDimension���� x, y�� �ʱ�ȭ �Ҷ� �θ��� �����ڸ� ȣ���Ͽ� �ʱ�ȭ ���ش�.

	/*cout << x << ":" << y << ":" << z << endl; �� ����� �Ϸ��� ������ x,y�� private�� ����Ǿ� ������ �Ұ��� �ߴ�.*/
	/*�ڽ� Ŭ������ ������ �� �θ� Ŭ������ �����ڵ� ���� ȣ���� �ǹǷ�, x, y�� ThreeDimension�� �����ڿ��� ������ �ʿ䰡 ����.*/
	ThreeDimension(double i, double j, double k) : TwoDimension(i, j), z(k) { cout << ":" << z; };
};

int main() {
	TwoDimension twoDim(10, 10);
	ThreeDimension threeDim(20, 20, 20);
}

