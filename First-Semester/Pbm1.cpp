#include <iostream>
using namespace std;

//배열 반환
//int* test() {
//	int* array = new int[20];
//	for (int i = 0; i < 20; i++) {
//		array[i] = i;
//	}
//	return array;
//}
//
//int main() {
//	int* testArray;
//	testArray = test();
//	for (int i = 0; i < 20; i++) {
//		cout << testArray + i << " " << *(testArray + i) << endl;
//	}
//}


//1. 정수 두개를 입력받아 그 두 수를 "가로", "세로"의 길이로 하는 사각형을 출력하고 사각형의 넓이를 반환하는 함수 drawSquare(int width, int height)를 작성하시오
//단 사각형의 4개의 모서리는 "▣" 를, 4개의 변은 "■"를, 나머지는 "□"를 사용하여 출력할 것

//int drawsquare(int width, int height) {
//	for (int i = height; i > 0; i--) {
//		for (int j = 1; j <= width; j++) {
//			if (i == height || i == 1) {
//				if (j == 1 || j == width) {
//					cout << "▣";
//				}
//				else {
//					cout << "■";
//				}
//			}
//			else {
//				if (j == 1 || j == width) {
//					cout << "■";
//				}
//				else {
//					cout << "□";
//				}
//			}
//		}
//		cout << endl;
//	}
//	return width * height;
// }
//
//int main() {
//	cout << drawsquare(10, 10);
//}

//2. class Player를 생성하여 공격력, 체력, 방어력 을 설정해서 적과 싸우는 시뮬레이션 프로그램
//스탯 포인트는 키보드로 숫자를 입력받아 100을 나누어서 투자한다. (체력은 투자한 포인트 x 10 만큼 설정)
//class Player {
//	int str, hp, def;
//public:
//	Player(int h, int s, int d) : hp(h), str(s), def(d) {}
//	void stats() {
//		cout << "체력 : " << hp << endl;
//		cout << "공격력 :" << str << endl;
//		cout << "방어력 :" << def << endl;
//	}
//};
//
//int* setstats() {
//	int input = 0, checkstats = 0, totalpoint = 0, hp = 0, str = 0, def = 0;
//	bool checkcorrect = 1;
//	while (checkcorrect)
//	{
//		switch (checkstats)
//		{
//		case 0:
//			cout << "체력 : ";
//			cin >> input;
//			hp = input;
//			break;
//		case 1:
//			cout << "공격력 : ";
//			cin >> input;
//			str = input;
//			break;
//		case 2:
//			cout << "방어력 : ";
//			cin >> input;
//			def = input;
//			break;
//		case 3:
//			if (totalpoint == 100) {
//				int* stats = new int[3];
//				stats[0] = hp;
//				stats[1] = str;
//				stats[2] = def;
//				return stats;
//			}
//		}
//		totalpoint += input;
//		checkstats++;
//		cout << "현재 사용한 포인트 : " << totalpoint << endl;
//		if (totalpoint > 100) {
//			cout << "포인트 초과! 포인트는 최대 100까지 사용 가능합니다." << endl << "처음부터 다시 설정..." << endl;
//			checkstats = 0;
//			totalpoint = 0;
//			hp = 0;
//			str = 0;
//			def = 0;
//			continue;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	int* statsArray;
//	statsArray = setstats();
//	Player NewPlayer(*statsArray, *(statsArray+1), *(statsArray+2));
//	NewPlayer.stats();
//}