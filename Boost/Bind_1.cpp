//bind.hpp 헤더 Import
#include <boost/bind.hpp>
#include <iostream>

using std::cout;
using std::endl;
//bind 관련이기 때문에 편하게 쓰기위해서 bind만 네임스페이스를 선언해준다.
using boost::bind; 

//간단한 함수
int add(int a, int b) {
	return a + b;
}


int main() {

	int x = 10;
	int y = 10;

	//add_5_10을 만들어 add(5, 10)기능을 하는 함수를 Bind 시킨다.
	auto add_5_10 = bind(add, 5, 10);

	//add_5_10은 add(5, 10)만 사용하도록 Bind되었다.
	cout << add_5_10() << endl; /* 15 */

	//입력 Parameter 받기
	auto plus_5 = bind(add, _1, 5);
	//_1, _2 와 같은 Placeholder를 사용하여 인수를 받을 수 있다.
	//값이 10인 x에 5를 더하기
	plus_5(x); /* 15 */ 

	return 0;
}