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
	//1. SOCKADDR_IN �޸� ����
	SOCKADDR_IN saddr;

	//2. ������ �޸𸮿� IP�ּҹ� ��Ʈ��ȣ �Է�
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);

	//�Ѵ� ���� �����
	InetPton(AF_INET, "1,2,3,4", &saddr.sin_addr);
	//inet_pton(2, "1,2,3,4", &saddr.sin_addr);

	WSACleanup();


	return 0;
}