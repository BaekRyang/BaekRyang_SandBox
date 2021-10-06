#include <boost/bind.hpp>
#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;
using boost::bind;

//간단한 함수
int add(int a, int b) {
	return a + b;
}


int main() {

	int x = 10;
	int y = 10;

	auto add_5_10 = bind(add, 5, 10);
	/* Bind_1과 같은 소스 코드 사용*/

	//add_5_10은 auto라는 자료형을 사용하는데 실제 자료형을 알아보기로함

	//자료형을 알아볼때는 typeid().name()을 사용
	cout << typeid(add_5_10).name() << endl;

	/* 결과 */
	// class boost::_bi::bind_t<int,int (__cdecl*)(int,int),class boost::_bi::list2<class boost::_bi::value<int>,class boost::_bi::value<int> > >


	cout << sizeof(add_5_10) << endl;
	/* 결과 : 12*/
	//크기는 12 byte를 차지함
	//add함수의 경우에는 4 byte 차지
	//자료형을 long long으로 바꾸면 8 byte, short로 바꾸면 2 byte를 차지
	//자료형의 크기를 따라가는 것을 알 수 있음

	return 0;
}