class Base {
	int v1;
protected:
	int v2;
public:
	int v3;

	// ������ (accessor)
	int getV1() { 
		return v1;
	};  
	int getV2() {
		return v2;
	};
	int getV3() {
		return v3;
	};

	// ������ (mutator)
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
		v1 = 1; //Private ���ٺҰ�
		v2 = 2; //Protected ���ٰ���(��ӹ޴� Ŭ���������� ���ٰ���)
		v3 = 3; //Public ���ٰ���

		getV1();
		getV2(); 
		getV3(); // �����ڿ� ȣ���ڴ� public���� ����Ǿ��ֱ� ������ ���ٰ���
		setV1(1);
		setV2(2);
		setV3(3);

	}
};

class Derived2 : protected Base {
public:
	int Dv2V = 0;
	void Dv2F() {
		v1 = 1; //Private ���ٺҰ�
		v2 = 2; //Protected ���ٰ���(��ӹ޴� Ŭ���������� ���ٰ���)
		v3 = 3; //Public ���ٰ���

		getV1();
		getV2();
		getV3(); // �����ڿ� ȣ���ڴ� public���� ����Ǿ��ֱ� ������ ���ٰ���
		setV1(1);
		setV2(2);
		setV3(3);

	} 
};

class Derived3 : private Base {
public:
	int Dv3V = 0;
	void Dv3F() {
		v1 = 1; //Private ���ٺҰ�
		v2 = 2; //Protected ���ٰ���(��ӹ޴� Ŭ���������� ���ٰ���)
		v3 = 3; //Public ���ٰ���

		getV1();
		getV2();
		getV3(); // �����ڿ� ȣ���ڴ� public���� ����Ǿ��ֱ� ������ ���ٰ���
		setV1(1);
		setV2(2);
		setV3(3);

	}
};

int main(int argc, char const* argv[])
{
	Derived1 Dv1;
	Derived2 Dv2; //��ü �������� ������ ����
	Derived3 Dv3;

	Dv1.getV1(); Dv1.getV2(); Dv1.getV3();   //�����ڿ� ȣ���ڰ� Public�̰� Derived1�� ���ٻ���ڵ� Public�̱� ������ 
	Dv1.setV1(1); Dv1.setV2(2); Dv1.setV3(3);//���� ���� ����

	Dv2.getV1(); Dv2.getV2(); Dv2.getV3();   //�����ڿ� ȣ���ڰ� Public������ Derived2�� ���ٻ���ڴ� Protected�̱� ������
	Dv2.setV1(1); Dv2.setV2(2); Dv2.setV3(3);//���� �Ұ���

	Dv3.getV1(); Dv3.getV2(); Dv3.getV3();   //�����ڿ� ȣ���ڰ� Public������ Derived3�� ���ٻ���ڴ� Private�̱� ������
	Dv3.setV1(1); Dv3.setV2(2); Dv3.setV3(3);//���� �Ұ���
	
	/*
	Question : Private�� Protected�� ����?
	*/

}