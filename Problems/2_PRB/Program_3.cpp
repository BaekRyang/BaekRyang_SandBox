class Base {
	int v1;
protected:
	int v2;
public:
	int v3;

	// 접근자 (accessor)
	int getV1() { 
		return v1;
	};  
	int getV2() {
		return v2;
	};
	int getV3() {
		return v3;
	};

	// 설정자 (mutator)
	void setV1(int v) {
		v1 = v;
	};
	void setV2(int v) {
		v2 = v;
	};
	void setV3(int v) {
		v3 = v;
	};
};

class Derived1 : public Base {
public:
	int Dv1V = 0;
	void Dv1F() {
		v1 = 1; //Private 접근불가
		v2 = 2; //Protected 접근가능(상속받는 클래스에서는 접근가능)
		v3 = 3; //Public 접근가능

		getV1();
		getV2(); 
		getV3(); // 접근자와 호출자는 public으로 선언되어있기 때문에 접근가능
		setV1(1);
		setV2(2);
		setV3(3);

	}
};

class Derived2 : protected Base {
public:
	int Dv2V = 0;
	void Dv2F() {
		v1 = 1; //Private 접근불가
		v2 = 2; //Protected 접근가능(상속받는 클래스에서는 접근가능)
		v3 = 3; //Public 접근가능

		getV1();
		getV2();
		getV3(); // 접근자와 호출자는 public으로 선언되어있기 때문에 접근가능
		setV1(1);
		setV2(2);
		setV3(3);

	} 
};

class Derived3 : private Base {
public:
	int Dv3V = 0;
	void Dv3F() {
		v1 = 1; //Private 접근불가
		v2 = 2; //Protected 접근가능(상속받는 클래스에서는 접근가능)
		v3 = 3; //Public 접근가능

		getV1();
		getV2();
		getV3(); // 접근자와 호출자는 public으로 선언되어있기 때문에 접근가능
		setV1(1);
		setV2(2);
		setV3(3);

	}
};

int main(int argc, char const* argv[])
{
	Derived1 Dv1;
	Derived2 Dv2; //객체 생성에는 문제가 없음
	Derived3 Dv3;

	Dv1.getV1(); Dv1.getV2(); Dv1.getV3();   //접근자와 호출자가 Public이고 Derived1의 접근상속자도 Public이기 때문에 
	Dv1.setV1(1); Dv1.setV2(2); Dv1.setV3(3);//전부 접근 가능

	Dv2.getV1(); Dv2.getV2(); Dv2.getV3();   //접근자와 호출자가 Public이지만 Derived2의 접근상속자는 Protected이기 때문에
	Dv2.setV1(1); Dv2.setV2(2); Dv2.setV3(3);//접근 불가능

	Dv3.getV1(); Dv3.getV2(); Dv3.getV3();   //접근자와 호출자가 Public이지만 Derived3의 접근상속자는 Private이기 때문에
	Dv3.setV1(1); Dv3.setV2(2); Dv3.setV3(3);//접근 불가능
	
	/*
	Question : Private와 Protected의 차이?
	*/

}