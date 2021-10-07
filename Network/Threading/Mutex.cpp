#include <WinSock2.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

int counter;

HANDLE h_mutex; //CreateMutex���� ���� HANDLE�� ���� ���� ����

unsigned __stdcall func(LPVOID prm) {
	/* Argment ó�� */
	int start = *((int*)prm);//LPVOID*�� ���� �����͸� int*�� �ٲ۵� �տ� "*"�� �ٿ� �� ����
	int end = *((int*)prm + 1);//�� ���� ���� �޾ƿ��� ���ؼ��� ������ +1 �� ��.

	//Argment�� �޾ƿ� Start���� end���� �ݺ�
	for (int i = start; i < end; i++) {
		//Key �ޱ�
		WaitForSingleObject(h_mutex, INFINITE);
		//�ڵ鰪���� �޾ƿ� h_mutex�� �ش�
		//Auto Reset���� ���� h_mutex�� non-signal�� �ʱ�ȭ �� ** ResetEvent()�� �ٸ��� �ϵ���������� ���� �Ǿ����� **

		counter++;

		//Key �ݳ�
		ReleaseMutex(h_mutex); //���� ReleaseMutex�� ������ �ڵ����� O/S���� Signalled ���·� ������ش�.
		//h_mutex�� ���¸� Signalled�� ��ȯ
	}
	return 0;
}

int main() {
	HANDLE th[16];
	int arg[] = { 0,100 }; //func()�� �Ҷ� �Ѱ��� Argment�� ����

	//���ؽ� Ŀ�� ������Ʈ�� ����
	h_mutex = CreateMutex(NULL, false, NULL);//(���Ȱ�, Owner�� Create�� ȣ���� ����� ���°�?, �̸�) �ڵ鰪 ��ȯ


	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cout << "Number of Proccessors is " << info.dwNumberOfProcessors << endl;

	clock_t stime = clock(); //�ð� ������

	//Thread ����
	for (DWORD i = 0; i < info.dwNumberOfProcessors; i++) {
		//HANDLE �迭 th�� Thread�� �����Ͽ� handle�� �־��ش�.
		//Parameter�� [Security], [Buf������], [�Լ��ּ�], [Argment] [FLAG], [Thread �ּ�]�� ����Ѵ�. 

		th[i] = (HANDLE)_beginthreadex(NULL, 0, &func, arg, 0, NULL);
	}

	WaitForMultipleObjects(info.dwNumberOfProcessors, th, true, INFINITE);


	clock_t etime = clock(); //�ð� ������

	cout << "main : " << counter << endl
		 << "Time : " << (double)((etime)-(stime)) / CLOCKS_PER_SEC << endl;
	return 0;
}