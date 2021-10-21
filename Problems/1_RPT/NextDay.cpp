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
	//윤년 관련 함수
	bool isLeapYear() {
		//4로 나누어 떨어지지만 100으로는 나누어 떨어지지 않는 해와 400으로 나누어 떨어지는 해는 윤년이다
		if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
			return true;//맞으면 true반환
		return false;//아닐시 false반환

	};
	void setMonth(int m) { month = m; }
};

void printDate(Date& day) {
	day.printDay();
}

Date Date::nextDay() {
	Date returnDay(year, month, day);
	//값이 변하지 않도록 temp를 만들어준다.
	returnDay.day++;
	//만약 1일 뒤에도 윤년까지 계산하여 29일 미만이면 다음달로 넘어갈 수 없으므로 바로 반환해준다.
	if ((day) < 28) {
		return returnDay;
	}
	else { // 29일 이상이면 다음달로 넘어갈 가능성이 생겼으므로 달 계산을 해줘야한다.
		//1,3,5,7,8,10,12 달은 31일까지 있다.
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day == 32) {
				//32부터는 다음달로 넘어가므로 day를 1로 만들고 month를 1 더해준다.
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13부터는 내년으로 넘어가야하므로 month를 1로 만들고 year에 1을 더해준다.
					returnDay.month = 1;
					returnDay.year++;
				}
			}
			//4,6,9,11달은 30일까지 있다.
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 32) {
				//32부터는 다음달로 넘어가므로 day를 1로 만들고 month를 1 더해준다.
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13부터는 내년으로 넘어가야하므로 month를 1로 만들고 year에 1을 더해준다.
					returnDay.month = 1;
					returnDay.year++;
				}
			}
		}
		//마지막으로 2월일때
		else {
			//윤년이 맞을시와 아닐시를 나누어 준다.
			if (isLeapYear()) {
				if (day == 29) {
					//29부터는 다음달로 넘어가므로 day를 1로 만들고 month를 1 더해준다.
					returnDay.day = 1;
					returnDay.month++;
					if (month == 13) {
						//13부터는 내년으로 넘어가야하므로 month를 1로 만들고 year에 1을 더해준다.
						returnDay.month = 1;
						returnDay.year++;
					}
				}
			}//윤년이 아닐시 28일 까지 있다.위쪽에서 29일 이상이라는 것을 확인했기 때문에 바로 넘어가준다.
			else {
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13부터는 내년으로 넘어가야하므로 month를 1로 만들고 year에 1을 더해준다.
					returnDay.month = 1;
					returnDay.year++;
				}
			}
		}
	}
	return returnDay;
}


int main(int argc, char const* argv[])
{
	//윤년인 년과 아닌년을 5개씩 올려보며 비교한다.
	Date D1(2020, 2, 25);
	Date D2(2021, 2, 25);
	Date D3 = D1;
	Date D4 = D2;
	for (int i = 0; i < 5; i++) {
		D3 = D3.nextDay();
		D3.printDay();
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		D4 = D4.nextDay();
		D4.printDay();
	}
	
}


