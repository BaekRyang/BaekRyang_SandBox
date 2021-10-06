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
	//���� ���� �Լ�
	bool isLeapYear() {
		//4�� ������ ���������� 100���δ� ������ �������� �ʴ� �ؿ� 400���� ������ �������� �ش� �����̴�
		if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
			return true;//������ true��ȯ
		return false;//�ƴҽ� false��ȯ

	};
	void setMonth(int m) { month = m; }
};

void printDate(Date& day) {
	day.printDay();
}

Date Date::nextDay() {
	Date returnDay(year, month, day);
	//���� ������ �ʵ��� temp�� ������ش�.
	returnDay.day++;
	//���� 1�� �ڿ��� ������� ����Ͽ� 29�� �̸��̸� �����޷� �Ѿ �� �����Ƿ� �ٷ� ��ȯ���ش�.
	if ((day) < 28) {
		return returnDay;
	}
	else { // 29�� �̻��̸� �����޷� �Ѿ ���ɼ��� �������Ƿ� �� ����� ������Ѵ�.
		//1,3,5,7,8,10,12 ���� 31�ϱ��� �ִ�.
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day == 32) {
				//32���ʹ� �����޷� �Ѿ�Ƿ� day�� 1�� ����� month�� 1 �����ش�.
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13���ʹ� �������� �Ѿ���ϹǷ� month�� 1�� ����� year�� 1�� �����ش�.
					returnDay.month = 1;
					returnDay.year++;
				}
			}
			//4,6,9,11���� 30�ϱ��� �ִ�.
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 32) {
				//32���ʹ� �����޷� �Ѿ�Ƿ� day�� 1�� ����� month�� 1 �����ش�.
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13���ʹ� �������� �Ѿ���ϹǷ� month�� 1�� ����� year�� 1�� �����ش�.
					returnDay.month = 1;
					returnDay.year++;
				}
			}
		}
		//���������� 2���϶�
		else {
			//������ �����ÿ� �ƴҽø� ������ �ش�.
			if (isLeapYear()) {
				if (day == 29) {
					//29���ʹ� �����޷� �Ѿ�Ƿ� day�� 1�� ����� month�� 1 �����ش�.
					returnDay.day = 1;
					returnDay.month++;
					if (month == 13) {
						//13���ʹ� �������� �Ѿ���ϹǷ� month�� 1�� ����� year�� 1�� �����ش�.
						returnDay.month = 1;
						returnDay.year++;
					}
				}
			}//������ �ƴҽ� 28�� ���� �ִ�.���ʿ��� 29�� �̻��̶�� ���� Ȯ���߱� ������ �ٷ� �Ѿ�ش�.
			else {
				returnDay.day = 1;
				returnDay.month++;
				if (month == 13) {
					//13���ʹ� �������� �Ѿ���ϹǷ� month�� 1�� ����� year�� 1�� �����ش�.
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
	//������ ��� �ƴѳ��� 5���� �÷����� ���Ѵ�.
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


