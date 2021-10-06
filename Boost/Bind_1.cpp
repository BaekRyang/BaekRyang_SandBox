//bind.hpp ��� Import
#include <boost/bind.hpp>
#include <iostream>

using std::cout;
using std::endl;
//bind �����̱� ������ ���ϰ� �������ؼ� bind�� ���ӽ����̽��� �������ش�.
using boost::bind; 

//������ �Լ�
int add(int a, int b) {
	return a + b;
}


int main() {

	int x = 10;
	int y = 10;

	//add_5_10�� ����� add(5, 10)����� �ϴ� �Լ��� Bind ��Ų��.
	auto add_5_10 = bind(add, 5, 10);

	//add_5_10�� add(5, 10)�� ����ϵ��� Bind�Ǿ���.
	cout << add_5_10() << endl; /* 15 */


	//�Է� Parameter �ޱ�
	auto plus_5 = bind(add, _1, 5);
	//_1, _2 �� ���� Placeholder�� ����Ͽ� �μ��� ���� �� �ִ�.
	//���� 10�� x�� 5�� ���ϱ�
	plus_5(x); /* 15 */ 

	return 0;
}