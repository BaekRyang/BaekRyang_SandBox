#include <iostream>
using namespace std;

class TwoDimension
{
	double x, y;
public:
	//초기화 리스트를 사용하여 멤버 변수를 초기화 해준뒤, 초기화 된 값을 출력한다.
	TwoDimension(double i, double j) : x(i), y(j) { cout << endl << this->x << ":" << y; };
};

//TwoDimension에 있는 x,y를 사용하기 위해 상속을 시켜준다.
//ThreeDimension은 TwoDimension()을 사용 할 수 없도록 private로 상속 접근자를 지정한다.
class ThreeDimension : private TwoDimension
{
	double z;
public:
	//TwoDimension이 초기화 리스트를 사용하고 있기 때문에
	//ThreeDimension에서 x, y를 초기화 할때 부모의 생성자를 호출하여 초기화 해준다.

	/*cout << x << ":" << y << ":" << z << endl; 로 출력을 하려고 했으나 x,y가 private로 선언되어 접근이 불가능 했다.*/
	/*자식 클래스를 생성할 때 부모 클래스의 생성자도 같이 호출이 되므로, x, y는 ThreeDimension의 생성자에서 접근할 필요가 없다.*/
	ThreeDimension(double i, double j, double k) : TwoDimension(i, j), z(k) { cout << ":" << z; };
};

int main() {
	TwoDimension twoDim(10, 10);
	ThreeDimension threeDim(20, 20, 20);
}

