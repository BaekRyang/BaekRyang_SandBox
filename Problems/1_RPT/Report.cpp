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

// Date �� ��ü�� �Ű� ������ �޾� ��ü�� �� ����ϴ� �Լ� 
// void printDate(Date day) {
//  	day.printDay();
//  }

void printDate(Date& day) {
	day.printDay();
}

// void printDate(Date* day){  //  ���ذ� ������ ����� �����ؼ� ���� 

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
	today.printDay();  // 2021: 9 : 11 ���
	Date tmp = today.nextDay();  // ��ü ���� tmp �� ����� �� 2021. 9 .12

	tmp.printDay(); // 2021: 9: 12

	tmp = today;    // tmp �� today ���� ���� ������ ���� 
	tmp.setMonth(10);

	today.printDay();  // 2021: 9: 11
	tmp.printDay();    // 2021: 10: 11 

	Date& r = today;  // ���� ���� 

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







