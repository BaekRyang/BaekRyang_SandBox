#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

public:
	Date() {};  
	~Date() {}; 
	Date(int y, int m, int d) : year(y), month(m), day(d) {};
	Date nextDay(); 
	void printDay() { cout << year << ":" << month << ":" << day << endl; }
	bool isLeapYear();
	void setMonth(int m) { month = m; }
};

// Date 의 객체를 매개 변수로 받아 객체의 값 출력하는 함수 
// void printDate(Date day) {
//  	day.printDay();
//  }

void printDate(Date& day) {
	day.printDay();
}

// void printDate(Date* day){  //  이해가 가능한 사람은 구현해서 검증 

// }

// Animal, Cat, Dog, Chiken

class Animal
{
	int legs;

public:
	Animal(int l) : legs(l) {};
	~Animal() {};
	int getLegs() { return legs; }
	void setLegs(int l) { legs = l; }
	//void setLegs(int l) : legs(l) {}

};

class Cat : public Animal
{
public:
	void changelegs() { setLegs(3); }
	Cat(int l) : Animal(l) {};
	~Cat() {};

};

int main(int argc, char const* argv[])
{
	Date day;
	Date today(2021, 9, 11);
	day.printDay();
	today.printDay();  // 2021: 9 : 11 출력
	Date tmp = today.nextDay();  // 객체 복사 tmp 에 저장된 값 2021. 9 .12

	tmp.printDay(); // 2021: 9: 12

	tmp = today;    // tmp 와 today 같은 값을 가지고 있음 
	tmp.setMonth(10);

	today.printDay();  // 2021: 9: 11
	tmp.printDay();    // 2021: 10: 11 

	Date& r = today;  // 참조 변수 

	r.setMonth(12);
	today.printDay();  // 2021: 12: 11
	r.printDay();	//    2021: 12: 11


	Cat m(4);
	cout << m.getLegs() << endl;  // 4

//	printDate(today);
	return 0;
}


Date Date::nextDay() {

	Date returnDay(year, month, day);
	returnDay.day++;

	return returnDay;

}







