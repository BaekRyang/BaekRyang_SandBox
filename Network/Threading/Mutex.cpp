#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

HANDLE h_mutex; //CreateMutex에서 나온 HANDLE을 받을 변수 생성

unsigned __stdcall func(LPVOID prm) {
	/* Argment 처리 */
	int start = *((int*)prm);//LPVOID*로 받은 데이터를 int*로 바꾼뒤 앞에 "*"를 붙여 값 추출
	int end = *((int*)prm + 1);//그 다음 값을 받아오기 위해서는 포인터 +1 을 함.

	//Argment로 받아온 Start부터 end까지 반복
	for (int i = start; i < end; i++) {
		//Key 받기
		WaitForSingleObject(h_mutex, INFINITE);
		//핸들값으로 받아온 h_mutex를 준다
		//Auto Reset으로 인해 h_mutex는 non-signal로 초기화 됨 ** ResetEvent()와 다르게 하드웨어적으로 보장 되어있음 **

		counter++;

		//Key 반납
		ReleaseMutex(h_mutex); //만약 ReleaseMutex가 없더라도 자동으로 O/S에서 Signalled 상태로 만들어준다.
		//h_mutex의 상태를 Signalled로 변환
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100 }; //func()을 할때 넘겨줄 Argment를 저장

	//뮤텍스 커널 오브젝트를 생성
	h_mutex = CreateMutex(NULL, false, NULL);//(보안값, Owner를 Create를 호출한 사람이 갖는가?, 이름) 핸들값 반환


	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;

	clock_t stime = clock(); //시간 측정용

	//Thread 생성
	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		//HANDLE 배열 th에 Thread를 생성하여 handle을 넣어준다.
		//Parameter로 [Security], [Buf사이즈], [함수주소], [Argment] [FLAG], [Thread 주소]를 사용한다. 

		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);


	clock_t etime = clock(); //시간 측정용

	cout << "main : " << counter << endl
		 << "Time : " << (double)((etime)-(stime)) / CLOCKS_PER_SEC << endl;
	return 0;
}