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

	//���� �ɼ� ���� (Broadcastĳ��Ʈ ����� ����)
	bool bbroad = true;
	int retval = setsockopt(c_sock, SOL_SOCKET, SO_BROADCAST, (char*)&bbroad, sizeof(bbroad));
	if (retval == SOCKET_ERROR) {
		err_display("setsockopt()");
		return -1;
	}

	SOCKADDR_IN multicast_addr;
	multicast_addr.sin_family = AF_INET;
	InetPton(AF_INET, "236.0.0.1", &multicast_addr.sin_addr);
	multicast_addr.sin_port = htons(8000);

	//��ۿ� ������ �о ���پ� Receiver���� �۽�
	//1. ������ ����
	FILE* fptr = NULL;
	fopen_s(&fptr, "news.txt", "r");
	if (fptr == NULL) {
		cout << "File not found" << endl;
		return -1;
	}

	//ȭ�鿡 ���÷���
	char buf[80];
	int sendlen;
	int recvlen;
	int namelen = sizeof(multicast_addr);

	while (1) {
		fgets(buf, 79, fptr); //������ �Է��ϰ� Enter�� �ϸ� '\n'�� �ٰ� �ڵ������� �������� '\0' �Էµ�
		sendlen = strlen(buf);
		sendto(c_sock, buf, sendlen, 0, (SOCKADDR*)&multicast_addr, sizeof(multicast_addr));

		//file�� ���� fptr�� ������ ����
		if (feof(fptr)) {
			sendto(c_sock, "", 0, 0, (SOCKADDR*)&multicast_addr, sizeof(multicast_addr));
			break;
		}
		Sleep(100);
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