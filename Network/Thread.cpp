#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*�� ���� �����͸� int*�� �ٲ۵� �տ� "*"�� �ٿ� �� ����
	int end = *((int*)prm + 1);//�� ���� ���� �޾ƿ��� ���ؼ��� ������ +1 �� ��.
	for (int i = start; i < end; i++) {
		counter++;
	} 
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,10000 };

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;

	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg/*Arg�� �ּҰ����� �Ѱ���*/, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);
	//WaitForMultipleObjects(�ݺ��� Ƚ��, �ڵ��� ���� ��Ƶ� �ּҰ�, ���� ������ �� ���� ���?, TIMEOUT �ð�)

	//WaitForSingleObject(th, INFINITE);

	cout << "main : " << counter << endl;
	return 0;
}