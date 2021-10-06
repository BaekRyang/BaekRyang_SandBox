#include <boost/bind.hpp>
#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;
using boost::bind;

//������ �Լ�
int add(int a, int b) {
	return a + b;
}


int main() {

	int x = 10;
	int y = 10;

	auto add_5_10 = bind(add, 5, 10);
	/* Bind_1�� ���� �ҽ� �ڵ� ���*/

	//add_5_10�� auto��� �ڷ����� ����ϴµ� ���� �ڷ����� �˾ƺ������

	//�ڷ����� �˾ƺ����� typeid().name()�� ���
	cout << typeid(add_5_10).name() << endl;

	/* ��� */
	// class boost::_bi::bind_t<int,int (__cdecl*)(int,int),class boost::_bi::list2<class boost::_bi::value<int>,class boost::_bi::value<int> > >


	cout << sizeof(add_5_10) << endl;
	/* ��� : 12*/
	//ũ��� 12 byte�� ������
	//add�Լ��� ��쿡�� 4 byte ����
	//�ڷ����� long long���� �ٲٸ� 8 byte, short�� �ٲٸ� 2 byte�� ����
	//�ڷ����� ũ�⸦ ���󰡴� ���� �� �� ����

	return 0;
}