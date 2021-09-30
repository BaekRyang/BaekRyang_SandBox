#include <iostream>
using namespace std;

//1.
int main() {
	struct Student
	{
		int ID;
		char name[20];
		char dpm[30];
	};

	Student stds[5];
	stds[0] = { 20200001, "Hong_Gil_Dong", "Cumputer_Enginereeing" };
	stds[1] = { 20200002, "Gang_Woo_Seok", "Bio_Technology" };
	stds[2] = { 20200003, "Nam_Chang_Mi", "English_Language" };
	stds[3] = { 20200004, "Im_Soo_Jung", "Public_Policy" };
	stds[4] = { 20200005, "Park_Ji_Sung", "Advertising" };

	//참조변수 선언 후 변경
	int& refid = stds[0].ID;
	refid = 20210005;

	//
	Student* pntName = &stds[0];
	cout << pntName << endl;

	for (int i = 0; i < 5; i++) {
		cout << stds[i].ID << endl;
		cout << stds[i].name << endl;
		cout << stds[i].dpm << endl << endl;
	}

}

//int main() {
//
//}
