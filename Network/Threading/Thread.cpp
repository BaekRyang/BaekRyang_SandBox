#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*로 받은 데이터를 int*로 바꾼뒤 앞에 "*"를 붙여 값 추출
	int end = *((int*)prm + 1);//그 다음 값을 받아오기 위해서는 포인터 +1 을 함.
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
		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg/*Arg를 주소값으로 넘겨줌*/, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);
	//WaitForMultipleObjects(반복할 횟수, 핸들의 값을 모아둔 주소값, 전부 실행할 때 까지 대기?, TIMEOUT 시간)

	//WaitForSingleObject(th, INFINITE);

	cout << "main : " << counter << endl;
	return 0;
}