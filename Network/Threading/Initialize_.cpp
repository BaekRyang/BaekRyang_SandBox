#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

CRITICAL_SECTION cs; //임계영역 키 생성

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*로 받은 데이터를 int*로 바꾼뒤 앞에 "*"를 붙여 값 추출
	int end = *((int*)prm + 1);//그 다음 값을 받아오기 위해서는 포인터 +1 을 함.
	for (int i = start; i < end; i++) {
		EnterCriticalSection(&cs); //Key를 흭득
		counter++;
		if (counter == 1) {
			return 0; //counter 가 1일때 return시킨다.
		}
		//Key 반납이 이루어지지 않아 counter가 1인 상태로 DeadLock이 발생함
		LeaveCriticalSection(&cs); //Key 반납
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100000 };

	InitializeCriticalSection(&cs); //생성된 키를 초기화

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;

	clock_t stime = clock();
	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg/*Arg를 주소값으로 넘겨줌*/, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);
	clock_t etime = clock();
	//WaitForMultipleObjects(반복할 횟수, 핸들의 값을 모아둔 주소값, 전부 실행할 때 까지 대기?, TIMEOUT 시간)

	//WaitForSingleObject(th, INFINITE);

	cout << "main : " << counter << endl
		<< "Time : " << (double)((etime)-(stime)) / CLOCKS_PER_SEC << endl;
	return 0;
}