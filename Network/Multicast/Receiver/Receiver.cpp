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

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll �ʱ�ȭ
		err_display("WSAStartup");
		return -1;
	}

	//���� ����
	SOCKET s_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Server Socket
	if (s_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}

	SOCKADDR_IN saddr; //Local Address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); //�� ��ǻ�Ϳ��� ����� �� �ִ� �����Ǹ� �ڵ����� ���

	SOCKADDR_IN caddr; //Ŭ���̾�Ʈ�� ������ ������ ����
	int namelen = sizeof(caddr); //recvform�� ������ Parameter

	ip_mreq mreq;
	mreq.imr_interface.s_addr = htonl(INADDR_ANY);
	InetPton(AF_INET, "236.0.0.1", &mreq.imr_multiaddr);
	setsockopt(s_sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mreq, sizeof(mreq));

	if (bind(s_sock, (SOCKADDR*)&saddr, sizeof(saddr))) {
		err_display("bind()");
		return -1;
	}

	char buf[80];
	int recvlen;
	while (1) {
		//����
		recvlen = recvfrom(s_sock, buf, 80, 0, (SOCKADDR*)&caddr, &namelen); //�������� ��쿡�� recvlen�� ���ŵ� ����Ʈ ���� �����. ���� 0�ϰ��� �������� ����
		if (recvlen == 0) { //������, �������� ���ᰡ ����� break��
			cout << "Client connection normal close case" << endl;
			err_display("recvform()");
			break;
		}
		else if (recvlen == SOCKET_ERROR) {
			cout << "Client connection abnormal(RST) close case" << endl;
			err_display("recvform()");
			break;
		}


		//���� �����͸� ȭ���� ���
		//���� �����͸� ���ڿ��� ����� ���� ���������� �������� NULL ���� �Է�
		buf[recvlen] = '\0';
		cout << buf << endl;

	}
	//}
	closesocket(s_sock);


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