#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

using std::cout;
using std::endl;

void err_display(const char*);
void Print_IP(LPVOID);
void Insert_IP(PCSTR, PVOID);

int main() {

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll �ʱ�ȭ
		err_display("WSAStartup");
		return -1;
	}

	//���� ����
	SOCKET c_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Server Socket
	if (c_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}

	//������ IP�ּ� �� ��Ʈ��ȣ ����
	SOCKADDR_IN saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	Insert_IP("127.0.0.1", &saddr.sin_addr);

	//���� �䱸
	/*if (connect(c_sock, (SOCKADDR*)&saddr, sizeof(saddr))) {
		err_display("connect()");
		return -1;
	}*/

	//Ű����� ���� �Է¹��� ������ ������ �۽��ϰ�, �ٽ� �����κ��� �۽��� ����
	//ȭ�鿡 ���÷���
	char buf[80];
	int sendlen;
	int recvlen;
	int namelen = sizeof(saddr);

	while (1) {
		fgets(buf, 79, stdin); //������ �Է��ϰ� Enter�� �ϸ� '\n'�� �ٰ� �ڵ������� �������� '\0' �Էµ�
		sendlen = strlen(buf);
		sendto(c_sock, buf, sendlen, 0, (SOCKADDR *)&saddr, namelen);
		recvlen = recvfrom(c_sock, buf, 80, 0, (SOCKADDR *)&saddr, &namelen);
		buf[recvlen] = '\0';
		cout << "From Server : " << buf << endl;
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

void Insert_IP(PCSTR str, PVOID addr) {
	if (!InetPton(AF_INET, str, addr)) {
		err_display("InetPton()");
	}
}