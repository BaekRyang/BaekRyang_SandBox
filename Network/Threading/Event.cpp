#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

HANDLE h_evt;

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*�� ���� �����͸� int*�� �ٲ۵� �տ� "*"�� �ٿ� �� ����
	int end = *((int*)prm + 1);//�� ���� ���� �޾ƿ��� ���ؼ��� ������ +1 �� ��.

	for (int i = start; i < end; i++) {
		//key ŉ��
		WaitForSingleObject(h_evt, INFINITE); //Manual Reset
		//��� Signalled ����
		ResetEvent(h_evt);
		//non-signalled ���·� �ٲ���. ��, ������ ���� �� ����
		counter++;

		//key �ݳ�
		SetEvent(h_evt);
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100000 };

	h_evt = CreateEvent(NULL, true, false, NULL);

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;


	clock_t stime = clock();

	//Thread ����
	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg/*Arg�� �ּҰ����� �Ѱ���*/, 0, NULL);
	}

	//Event ��ü�� Non_signalled ���� Signalled�� ��ȯ
	SetEvent(h_evt);

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);

	clock_t etime = clock();
	//WaitForMultipleObjects(�ݺ��� Ƚ��, �ڵ��� ���� ��Ƶ� �ּҰ�, ���� ������ �� ���� ���?, TIMEOUT �ð�)

	//WaitForSingleObject(th, INFINITE);

	cout << "main : " << counter << endl
		<< "Time : " << (double)((etime)-(stime)) / CLOCKS_PER_SEC << endl;
	return 0;
}