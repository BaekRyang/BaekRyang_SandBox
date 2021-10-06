#include <iostream>

using namespace std;

//클래스 상속시 자식클래스의 객체 생성시 부모 클래스의 속성 초기화 방법

class Nums {
private:

public:
	int value1 = 0;
	int value2 = 0;
	int value3 = 0;
	void PrintNums() {
		cout << value1 << endl << value2 << endl << value3 << endl;
	}
	void Hello() {
		cout << "Hello!" << endl;
	}
	Nums() {};
	Nums(int _val1, int _val2, int _val3) : value1(_val1), value2(_val2), value3(_val3) {};
	~Nums() {};
};

////1차 시도 "Nums 레이블이 재정의 되었습니다." 오류로 컴파일 불가능
//class DerivedNums : public Nums {
//
//private:
//
//public:
//	int value4 = 0;
//	int value5 = 0;
//	int value6 = 0;
//	DerivedNums(int _val1, int _val2, int _val3, bool dev) {
//		if (dev) {
//		Nums:value1 = _val1;
//		Nums:value2 = _val2;
//		Nums:value3 = _val3;
//		}
//		else {
//			value4 = _val1;
//			value5 = _val2;
//			value6 = _val3;
//		}
//	};
//	~DerivedNums() {};
//}; 
//
//int main() {
//	Nums SC1(10,20,30);
//	SC1.PrintNums();
//	DerivedNums SC2(40, 50, 60, false);
//	DerivedNums SC2(40, 50, 60, true);
//	SC2.PrintNums();
//	return 0;
//}

////2차 시도 ":"를 하나만 사용해서 레이블로 인식하여 나온 오류
////"::"를 사용하니 문제없이 컴파일됨
//class DerivedNums : public Nums {
//private:
//
//public:
//	int value4 = 0;
//	int value5 = 0;
//	int value6 = 0;
//	DerivedNums(int _val1, int _val2, int _val3, bool dev) {
//		//dev가 true이면 부모클래스의 속성을 초기화해준다.
//		if (dev) {
//		Nums::value1 = _val1;
//		Nums::value2 = _val2;
//		Nums::value3 = _val3;
//		}
//		else {
//			value4 = _val1;
//			value5 = _val2;
//			value6 = _val3;
//		}
//	};
//	~DerivedNums() {};
//};

class DerivedNums : public Nums {
private:

public:
	int value4 = 0;
	int value5 = 0;
	int value6 = 0;
	DerivedNums(int _val1, int _val2, int _val3, bool dev) {
		//dev가 true이면 부모클래스의 속성을 초기화해준다.
		if (dev) {
			Nums::value1 = _val1;
			Nums::value2 = _val2;
			Nums::value3 = _val3;
		}
		else {
			value4 = _val1;
			value5 = _val2;
			value6 = _val3;
		}
	};
	//3번째로 부모클래스에 있는 함수도 자식 클래스에서 재정의하면
	//덮어씌워져서 작동함을 알 수 있다.
	void Hello() {
		cout << "Greeting!" << endl;
	}
	~DerivedNums() {};
};

int main() {
	Nums SC1(10, 20, 30);
	DerivedNums SC2(40, 50, 60, false);
	SC1.Hello();
	SC2.Hello();
	return 0;
}



