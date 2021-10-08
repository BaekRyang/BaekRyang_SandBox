#include <WinSock2.h>
#include <process.h>
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

int counter;

HANDLE h_mutex; //CreateMutex에서 나온 HANDLE을 받을 변수 생성

unsigned __stdcall func(LPVOID prm) {
	int start = *((int*)prm);//LPVOID*로 받은 데이터를 int*로 바꾼뒤 앞에 "*"를 붙여 값 추출
	int end = *((int*)prm + 1);//그 다음 값을 받아오기 위해서는 포인터 +1 을 함.
	for (int i = start; i < end; i++) {
		WaitForSingleObject(h_mutex, INFINITE);
		//핸들값으로 받아온 h_mutex를 준다
		//Auto Reset으로 인해 h_mutex는 non-signal로 초기화 됨

		counter++;

		if (counter == 1) {
			return 0; //제일 처음 counter가 1일때 return을 시킴
			//1500001이 나옴
		}

		ReleaseMutex(h_mutex);
		//h_mutex의 상태를 Signalled로 변환
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100000 };

	//뮤텍스 커널 오브젝트를 생성
	h_mutex = CreateMutex(NULL, false, NULL);//(보안값, Owner를 Create를 호출한 사람이 갖는가?, 이름) 핸들값 반환
	

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