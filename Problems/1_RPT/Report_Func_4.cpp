#include <iostream>

using namespace std;

//Ŭ���� ��ӽ� �ڽ�Ŭ������ ��ü ������ �θ� Ŭ������ �Ӽ� �ʱ�ȭ ���

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

////1�� �õ� "Nums ���̺��� ������ �Ǿ����ϴ�." ������ ������ �Ұ���
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

////2�� �õ� ":"�� �ϳ��� ����ؼ� ���̺�� �ν��Ͽ� ���� ����
////"::"�� ����ϴ� �������� �����ϵ�
//class DerivedNums : public Nums {
//private:
//
//public:
//	int value4 = 0;
//	int value5 = 0;
//	int value6 = 0;
//	DerivedNums(int _val1, int _val2, int _val3, bool dev) {
//		//dev�� true�̸� �θ�Ŭ������ �Ӽ��� �ʱ�ȭ���ش�.
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
		//dev�� true�̸� �θ�Ŭ������ �Ӽ��� �ʱ�ȭ���ش�.
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
	//3��°�� �θ�Ŭ������ �ִ� �Լ��� �ڽ� Ŭ�������� �������ϸ�
	//��������� �۵����� �� �� �ִ�.
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



