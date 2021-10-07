#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

CRITICAL_SECTION cs; //�Ӱ迵�� Ű ����

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*�� ���� �����͸� int*�� �ٲ۵� �տ� "*"�� �ٿ� �� ����
	int end = *((int*)prm + 1);//�� ���� ���� �޾ƿ��� ���ؼ��� ������ +1 �� ��.
	for (int i = start; i < end; i++) {
		EnterCriticalSection(&cs); //Key�� ŉ��
		counter++;
		if (counter == 1) {
			return 0; //counter �� 1�϶� return��Ų��.
		}
		//Key �ݳ��� �̷������ �ʾ� counter�� 1�� ���·� DeadLock�� �߻���
		LeaveCriticalSection(&cs); //Key �ݳ�
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100000 };

	InitializeCriticalSection(&cs); //������ Ű�� �ʱ�ȭ

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;

	clock_t stime = clock();
	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg/*Arg�� �ּҰ����� �Ѱ���*/, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);
	clock_t etime = clock();
	//WaitForMultipleObjects(�ݺ��� Ƚ��, �ڵ��� ���� ��Ƶ� �ּҰ�, ���� ������ �� ���� ���?, TIMEOUT �ð�)

	//WaitForSingleObject(th, INFINITE);

	cout << "main : " << counter << endl
		<< "Time : " << (double)((etime)-(stime)) / CLOCKS_PER_SEC << endl;
	return 0;
}