#include <iostream>
#include <math.h>
using namespace std;

//1. 전역변수(global variable), 로컬변수(local variable), 정적변수(static variable), 자동 변수(auto variable), 외부변수(extern variable) 에 해당하는 변수를 선언하고 변수에 데이터의 유효 범위와 생명주기를 확인하는 프로그램을 작성하고 검증하시오.
//int increase();
////전역변수 : 해당 프로그램 어디서든지 접근이 가능하며 프로그램이 종료될때 까지 메모리를 유지한다. 
//int var1 = 10;
//int main() {
//	//지역변수 : 자신이 존재하는 괄호 안에서만 접근이 가능하다. (이 경우에는 main 함수 안)
//	//자동변수는 지역변수의 또 다른 표현으로 변수를 선언할 때 auto라는 명령어를 사용하지만 일반적으로는 생략한다. 
//	int var2 = 20;
//	//정적변수 :  프로그램이 끝나기 전까지는 메모리에 계속 존재한다. 초기화는 프로그램 시작시에 한번만 초기화 된다.
//	static int var3 = 30;
//	{
//		//var2라는 지역변수를 선언한다.
//		int var2 = 200;
//		//해당 변수는 현재 괄호에서만 유효 하기 때문에 문제없이 선언이 가능하며 출력을 할때 200을 출력한다.
//		cout << var2 << endl;
//	}
//	//위에있는 변수의 life-time은 만료되었기 때문에 아래 출력은 20이 출력된다.
//	cout << var2 << endl;
//	//외부 변수를 이용해서 var값을 증가시킨다.
//	increase();
//	cout << var1 << endl;
//}
////정적변수를 전역변수를 사용하면 extern으로 외부에서 참조를 할 수 없다.
//static int var4 = 40;
//
////void callValue() {
////	var1, var4는 전역변수이기 때문에 외부 함수에서도 참조할 수 있지만, var2, var3은 지역변수이기 때문에 외부에서 참조할 수 없다.
////	cout << var1 << endl << var2 << endl << var3 << endl << var4 << endl;
////}

//2. 일반 변수, 포인터 변수, 참조 변수, 배열 변수를 선언한 후 주소와 관련하는 연산자 (*, &)를 모두 활용하는 프로그램을 작성하시오.
//int main() {
//	//일반변수
//	int var1 = 10;
//	//포인터변수 : 주소값을 저장한다.
//	int* var2;
//	//참조변수 : 변수의 별명을 만들어서 사용한다.
//	int& var3 = var1;
//	//배열변수 : 같은 종류의 변수를 모아서 관리할 때 사용한다.
//	int var4[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//var3은 var1의 별명이기 때문에 var3을 변경하면 var1의 값이 바뀐다.
//	cout << var1 << endl;
//	var3 *= 5;
//	cout << var1 << endl;
//
//	//포인터변수에 배열변수 0번쨰 IDX를 주소값을 저장하려면 "&"을 사용해서 변수의 주소값을 반환해서 저장한다.
//	//배열변수의 첫번째 값을 저장한 후 출력하면 주소값이 출력된다. 이 때 값을 출력하고 싶다면 "*"을 사용하면 해당 주소에 저장된 값을 반환한다.
//	var2 = &var4[0];
//	cout << var2 << " , " << *var2 << endl << endl;
//	//배열변수의 주소값은 1씩 증가하면서 존재하기 때문에 주소값에 1씩 더한다면 다음 IDX의 값도 출력할 수 있다.
//	for (int i = 0; i < 10; i++) {
//		cout << var2 + i << " , " << *var2 + i << endl;
//	}
//}


//3 int myNumbers() 함수를 정의하고 main() 함수에서 호출하는 프로그램을 작성하시오.
//첫 번쨰 호출에는 0, 두 번째 호출에는 1, 세번 째 호출에는 2, 네번 째 호출에는 4, 다섯 번 쨰 호출에는 8 가 n 번째 호출에는 2 ^ (n - 2) 가 반환되는 함수를 정의하시오.
//main() 함수에서 호출하는 프로그램을 작성하시오.

//int myNumbers();
////myNumbers를 10번 호출하는 코드
//int main() {
//	for (int i = 0; i < 10; i++) {
//		cout << myNumbers() << endl;
//	}
//	
//}
////static변수는 프로그램 시작시 단 한번만 초기화 되므로 호출시마다 값을 변경하기 위해 정적변수로 선언한다.
//int myNumbers() {
//	static int num = -1;
//	//만약 처음 실행되서 값이 -1인 경우
//	if (num < 0) {
//		//num에 1을 더해서 반환
//		return ++num;
//	}
//	else {
//		//그 외의 경우에는 숫자들의 관계가 2의 제곱수들 이므로 pow함수를 사용하여 반환시킨후 값을 더해준다.
//		return pow(2, num++);
//	}
//}

//4. 일상 생활의 객체를 C++ 클래스로 정의하고 검증하는 프로그램을 작성하시오.
//class Computer {
//private:
//	string cpuMfr, vgaMfr, ramMfr;
//	int cpuGen, vgaGen, ramSiz, pwrWat;
//public:
//	Computer(string cm, int cg, string vm, int vg, string rm, int rs, int pw) : cpuMfr(cm), cpuGen(cg), vgaMfr(vm), vgaGen(vg), ramMfr(rm), ramSiz(rs), pwrWat(pw) {}
//	void status() {
//		cout << "CPU Manufacturer : " << this->cpuMfr << endl;
//		cout << "CPU Gen : " << this->cpuGen << endl;
//		cout << "VGA Manufacturer : " << this->vgaMfr << endl;
//		cout << "VGA Gen : " << this->vgaGen << endl;
//		cout << "RAM Manufacturer : " << this->ramMfr << endl;
//		cout << "RAM Size : " << this->ramSiz << "GB" << endl;
//		cout << "Power Watt : " << this->pwrWat << "W" << endl;
//	}
//};
//
//int main() {
//	Computer myComputer("Intel", 8, "NVIDIA", 3, "SAMSUNG", 16, 800);
//	myComputer.status();
//}

//5. 다음의 Car 클래스를 정의하고 검증하는 프로그램을 작성하시오.
//속도(speed), 기어(gear), 색상(color)을 속성(멤버 변수)로 가짐 // private 접근 지정자
//멤버 함수 // public 접근 지정자
//Car 클래스의 객체를 생성할 때 객체 속성의 값을 저장할 수 있도록 하는 생성자 Car(int s, int g, string c) 정의(구현)
//저장된 속성값을 접근하는 접근자(가져오는 접근자) (accessor) :
//	int getSpeed(), int getGear(), string getColor()
//	속성값을 설정하는 설정자(mutator) :
//	void setSpeed(int s), void setGear(int g), void setColor(string c)
//	void speedUp() 메소드 구현
//	gear에 관계없이 일정 속도 증가
//	gear에 따라 속도 변화량 차별
//	void speedDown() 메소드 구현
//	gear에 관계없이 일정 속도 증가
//	gear에 따라 속도 변화량 차별
//	void status() 메소드 구현 : 모든 속성 값을 화면에 출력해주는 메소드 // 검증용

//class Car {
//private:
//	//필요한 변수들을 선언
//	int speed, gear;
//	string color;
//
//public:
//	//외부에서 사용할 수 있는 함수이기 때문에 Public에서 선언해준다.
//	//Car은 클래스 생성시 기본으로 사용되는 함수다. 그렇기 때문에 클래스 내에서 필요한 값을 할당하는데 사용한다.
//	Car(int s, int g, string c) : speed(s), gear(g), color(c) {}
//
//	//변수의 값을 반환하는 함수
//	int getSpeed() { return this->speed; }
//	int getGear() { return this->gear; }
//	string getColor() { return this->color; }
//
//	//변수의 값을 변경하는 함수
//	void setSpeed(int s) { this->speed = s; }
//	//기어는 1~8까지만 변경 가능하게 하며 그 이상/이하로 설정시 최대/최소 값으로 설정한다.
//	void setGear(int g) {
//		if (g > 8) {
//			cout << "MAXIMUM GEAR! -> 8" << endl;
//			this->gear = 8;
//		}
//		else if(g < 1) {
//			cout << "MINIMUM GEAR! -> 1" << endl;
//			this->gear = 1;
//		}
//		else {
//			this->gear = g;
//		}
//	}
//	void setColor(string c) { this->color = c; }
//
//	//속도를 올리는 함수는 기어에 따라서 속도가 올라가는 폭이 달라진다.
//	void speedUp() { 
//		this->speed +=  this->gear * 5; 
//		cout << "NOW SPEED -> " << this->speed << endl;
//	}
//	//내리는 함수도 동일
//	void speedDown() { 
//		this->speed -= this->gear * 5;
//		cout << "NOW SPEED -> " << this->speed << endl;
//	}
//	//현재 상태를 보여주는 함수
//	void status() {
//		cout << this->speed << endl;
//		cout << this->gear << endl;
//		cout << this->color << endl;
//	}
//};
//
//int main() {
//	//인스턴스 생성
//	Car myCar(1, 1, "Black");
//	//속도를 50으로 변경
//	myCar.setSpeed(50);
//	//색상을 "White"로 변경
//	myCar.setColor("White");
//	//기어를 너무 낮거나 큰 수로 설정했을때 변화값을 확인
//	myCar.setGear(-3);
//	myCar.setGear(10);
//	myCar.setGear(5);
//	//기어에 따른 속도증가
//	myCar.speedUp();
//	myCar.speedUp();
//	myCar.speedUp();
//	//현재 상태 표시
//	myCar.status();
//}

//6다음의 Product 클래스를 정의한 후 검증하는 프로그램을 작성하시오.
//id: 상품 일련 번호 : name: 상품이름, price : 가격
//멤버함수
//Price 클래스의 객체를 생성할 때 객체 속성의 값을 저장할 수 있도록 하는 생성자 Price(int id, string n, int p) 정의(구현)
//저장된 속성값을 접근하는 접근자(accessor) :
//	속성값을 설정하는 설정자(mutator) :
//	bool isCheaper(Product other) 메소드 구현 : 이 객체와 입력 파러미터로 받은 객체와의 가격 비교
//	bool isSame(Product other) 메소드 구현 : 이 객체와 입력 파러미터로 받은 객체가 같은 속성을 가지고 있는지 비교

////클래스 생성
//class Product {
//	//특정 지시가 없으면 private로 생성됨
//	//필요한 변수들을 선언
//	int id;
//	string name;
//	int price;
//
//public:
//	//인스턴스를 생성하면서 값을 할당하는 함수 선언
//	Product(int i, string n, int p) : id(i), name(n), price(p) {}
//
//	//인스턴스내 변수를 반환하는 함수 선언
//	int getId() { return id; }
//	string getName() { return name; }
//	int getPrice() { return price; }
//
//	//변수를 변경하는 함수 선언
//	int setId(int i) { this->id = i; }
//	int setName(string n) { this->name = n; }
//	int setPrice(int p) { this->price = p; }
//
//	//인수로 다른 Product 인스턴스를 받아서 자신과 비교하여 자신의 Price가 더 낮은지 검증하는 함수
//	bool isCheaper(Product other) {
//		if (this->price < other.price) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	//인수로 다른 Product를 받아 자신과 비교하는데 Cheaper와 다르게 3가지 요소를 전부 비교해서 같은지 확인하는 함수
//	bool isSame(Product other) {
//		if (this->price == other.price && this->name == other.name && this->id == other.id) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//};
//
//int main() {
//	//Product인스턴스 3개 생성
//	Product firstProduct (10, "Sample", 1000);
//	Product secondProduct (10, "Sample", 1000);
//	Product thirdProduct (20, "OtherSample", 3000);
//
//	//가격 등의 요소 비교
//	cout << firstProduct.isCheaper(secondProduct) << endl;
//	cout << firstProduct.isCheaper(thirdProduct) << endl;
//	cout << firstProduct.isSame(secondProduct) << endl;
//	cout << firstProduct.isSame(thirdProduct) << endl;
//}

//7. 2차원 평면의 점(좌표값)의 정보를 가지는 Point 클래스를 정의하고 main 함수에서 Point 클래스의 객체를 생성한 후 생성한 객체에 좌표값을 저장하고 확인하는 메소드를 사용하여 클래스 구현을 확인하는 프로그램 작성하시오.
//class Point {
//	int posX, posY;
//public:
//	Point(int x, int y) : posX(x), posY(y) {}
//	void status() {
//		cout << "x 좌표 : " << this->posX << endl;
//		cout << "y 좌표 : " << this->posY << endl;
//	}
//};
//
//int main() {
//	//좌표값을 저장
//	Point firstPoint(5, 10);
//	//저장된 값 확인
//	firstPoint.status();
//}

//8. 2차원 평면의 사각형의 정보를 저장하는 Rect 클래스 정의후 테스트하는 프로그램 작성하시오.
//class Rect {
//	int posX, posY, width, height;
//
//public:
//	Rect(int x, int y, int w, int h) : posX(x), posY(y), width(w), height(h) {}
//	//좌표를 저장하는 부분까지는 같지만 이번에는 시작점과 너비와 높이를 가지고 사각형의 정보를 저장
//	void squareStatus() {
//		cout << "기준점 (" << posX << ", " << posY << ")" << endl << "너비 : " << width << endl << "높이 : " << height << endl;
//		//출력된 사각형이 너무 벽에 붙지않도록 ScreenSize를 사각형이 위치한 곳보다 3크게 해서 만들어줌
//		int scrWidth = posX + width + 3;
//		int scrHeight = posY + height + 3;
//		
//		//i는 y축을 그리는 loop임 y의 최대값은 srcHeight이고 최소값은 0으로 잡아준다.
//		for (int i = scrHeight; i > -1; i--) {
//			//j는 x축을 그리는 loop x의 최대값도 srcWidth이고 최소값은 0으로 해준다.
//			for (int j = 0; j < scrWidth; j++) {
//				//사각형이 없는 조건은 칸을 비워준다. 아래는 해당 조건들이다
//				//현재 그리는 y 또는 x값이 기준점보다 작을때
//				//현재 그리는 y 또는 x값이 기준점 + 너비높이보다 클때
//				if (j < posX || i<posY || j>(posX + width) || i>(posY + height)) {
//					if (!i || !j) {
//						//x또는 y좌표가 0이면 좌표축으로 표시해준다.
//						cout << "▣";
//					}
//					else {
//						//이외에는 칸을 비워준다.
//						cout << "□";
//					}
//				}
//				else {
//					//위의 조건에 맞지 않는다면 사각형의 범위내에 있으므로 채워진 사각형을 출력한다.
//					cout << "■";
//				}
//			}
//			//한줄을 출력하고나서 줄 바꿈을 해준다.
//			cout << endl;
//		}
//		cout << endl << "!!▣은 좌표축 표시입니다.!!" << endl;
//	}
//};
//
//int main() {
//	Rect firstSquare(5, 8, 10, 10);
//	firstSquare.squareStatus();
//}

//9. 2차원 평면의 사각형의 정보를 저장하는 Rect 클래스를 Point 클래스를 사용하여 정의하고 테스트하는 프로그램 작성하시오.
//class Point {
//public:
//	//이번 변수들은 다른 클래스에서 참조할 수 있도록 public에 선언해준다.
//	int posX, posY;
//	Point(int x, int y) : posX(x), posY(y) {}
//};
//
//class Rect {
//	//이 클래스는 Point 자료형의 인스턴스를 두개 받아서 넓이를 구해준다.
//	int width, height;
//public:
//	//절대값을 통해 너비와 높이를 구해준다.
//	Rect(Point a, Point b) {
//		width = abs(a.posX - b.posX);
//		height = abs(a.posY - b.posY);
//	}
//	//범위를 구해주는 함수
//	int getArea() {
//		return this->width * this->height;
//	}
//};
//
//int main() {
//	Point firstPoint(1, 3);
//	Point secondPoint(5, 1);
//	Rect square(firstPoint, secondPoint);
//
//	cout << square.getArea() << endl;
//}