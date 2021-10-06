#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <process.h>
#include <iostream>

using std::cout;
using std::endl;

void err_display(const char*);
void Print_IP(LPVOID);
unsigned __stdcall echo_server(LPVOID);

int main() {

	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll �ʱ�ȭ
		err_display("WSAStartup");
		return -1;
	}

	//���� ����
	SOCKET s_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Server Socket
	if (s_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}
	//bind() : LocalAddress(IP ADDR + Port NUM) + Socket �� Association
	//bind�� �ʿ�� �ϴ� Parameter = Socket Descripter, Local Address(SOCKADDR_IN), Size

	SOCKADDR_IN saddr; //Local Address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); //�� ��ǻ�Ϳ��� ����� �� �ִ� �����Ǹ� �ڵ����� ���

	if (bind(s_sock, (SOCKADDR*)&saddr, sizeof(saddr))) {
		err_display("bind()");
		return -1;
	}

	//Listen : ������ Listen���·� �����, ���ÿ� Listen Buffer(Wait Buffer)�� �����Ѵ�.
	if (listen(s_sock, SOMAXCONN/*�ִ밪�� Buffer�� �����*/)) {
		err_display("listen()");
		return -1;
	}

	SOCKADDR_IN caddr; //Ŭ���̾�Ʈ�� ������ ������ ����
	int namelen = sizeof(caddr); //accept()�� 3��°  Parameter
	 
	HANDLE th;
	while (1) { //������ �� ������ �Ҷ��� ���ѷ��� ���
		cout << "Waiting for connection....." << endl;
        /*                       IN            OUT         IN/OUT    */
		SOCKET c_sock = accept(s_sock, (SOCKADDR*)&caddr, &namelen); // c_socket�� caddr�� �����ϱ� ���� ���� ������
		if (c_sock == INVALID_SOCKET) {
			err_display("accept()");
			return -1;
		}
		cout << "Connected!" << endl;

		//Thread ����
		th = (HANDLE)_beginthreadex(NULL, 0, &echo_server, (LPVOID)c_sock, 0, NULL);
	}
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

unsigned __stdcall echo_server(LPVOID _input) {
	SOCKET c_sock = (SOCKET)_input;
	char buf[80];
	int recvlen;

	SOCKADDR_IN c_addr;
	int addr_len = sizeof(c_addr);
	getpeername(c_sock, (SOCKADDR*)&c_addr, &addr_len);
	cout << "Server connected by ";
	Print_IP(&c_addr.sin_addr);
	while (1) {
		//����
		recvlen = recv(c_sock, buf, 80, 0); //�������� ��쿡�� recvlen�� ���ŵ� ����Ʈ ���� �����. ���� 0�ϰ��� �������� ����
		if (recvlen == 0 || recvlen == SOCKET_ERROR) { //������, �������� ���ᰡ ����� break��
			cout << "Client connection close case" << endl;
			closesocket(c_sock);
			break;
		}

		//���� �����͸� ȭ���� ���
			//���� �����͸� ���ڿ��� ����� ���� ���������� �������� NULL ���� �Է�
		buf[recvlen] = '\0';
		cout << "From client : " << buf << endl;

		//���� �����͸� Ŭ���̾�Ʈ���� �۽�
		send(c_sock, buf, recvlen, 0);
	}
	return 0;
}