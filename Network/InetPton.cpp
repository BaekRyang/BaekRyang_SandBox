#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

using std::cout;
using std::endl;

void err_display(const char*);
void Print_IP(LPVOID);

int main() {

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) {
		err_display("WSAStartup");
		return -1;
	}

	////IP주소, 포트 번호를 생성 -> 소켓 API함수에 전달하기 위해
	////1. SOCKADDR_IN 타입의 메모리 생성
	//SOCKADDR_IN saddr;

	////2. 생성 메모리에 IP주소, 포트번호, 주소체계를 채워넣는다.
	////2.1 주소 체계 입력(IPV4, Host byte order)
	//saddr.sin_family = AF_INET;
	////2.2 포트번호 입력(Network Byte order)
	//saddr.sin_port = htons(8000);
	////2.3 IP주소 입력 : InetPton() 사용
	//if (InetPton(AF_INET, "11.22.33.44", &saddr.sin_addr) != 1) {
	//	err_display("InetPton");
	//	return -1;
	//}

	//char buf[20];

	//if (!InetNtop(AF_INET, &saddr.sin_addr, buf, 20)) { // = if(InetNtop() == NULL)
	//	err_display("InetNtop");
	//	return -1;
	//}

	//cout << "IP addr : " << buf << endl;

	//Hint를 준다(반드시 0, 또는 NULL 로 초기화
	ADDRINFOA hints;
	ZeroMemory(&hints, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_CANONNAME;

	//Result를 받아야 할 포인터를 생성해야함
	PADDRINFOA result = NULL;

	if (getaddrinfo("baekryang.live", "http", & hints, &result)) {
		err_display("getaddrinfo()");
		return -1;
	}

	//포인터 변수 생성
	PADDRINFOA ptr = NULL;
	SOCKADDR_IN* qtr = NULL;
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
		qtr = (SOCKADDR_IN*)(ptr->ai_addr);
		Print_IP(&qtr->sin_addr);
	}

	WSACleanup();
	return 0;
}

void err_display(const char* mes) {
	LPVOID out;

	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&out, 0, NULL);
	cout << mes << " : " << (LPSTR)out << endl;
	LocalFree(out);
}

void Print_IP(LPVOID addr) {
	char buf[20];
	if (!InetNtop(AF_INET, addr, buf, 20)) {
		err_display("InetNtop");
		return;
	}
	cout << "IP addr : " << buf << endl;
}