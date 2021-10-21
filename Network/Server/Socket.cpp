#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	WSADATA wsa;

	WSAStartup(MAKEWORD(2, 2), &wsa);

	//IP Addr, Port Num
	//1. SOCKADDR_IN 메모리 생성
	SOCKADDR_IN saddr;

	//2. 생성된 메모리에 IP주소및 포트번호 입력
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);

	//둘다 같은 기능임
	InetPton(AF_INET, "1,2,3,4", &saddr.sin_addr);
	//inet_pton(2, "1,2,3,4", &saddr.sin_addr);

	WSACleanup();


	return 0;
}