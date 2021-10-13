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

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll 초기화
		err_display("WSAStartup");
		return -1;
	}

	//소켓 생성
	SOCKET c_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Server Socket
	if (c_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}

	//서버의 IP주소 및 포트번호 지정
	SOCKADDR_IN saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	Insert_IP("127.0.0.1", &saddr.sin_addr);

	//연결 요구
	/*if (connect(c_sock, (SOCKADDR*)&saddr, sizeof(saddr))) {
		err_display("connect()");
		return -1;
	}*/

	//키보드로 부터 입력받은 내용을 서버로 송신하고, 다시 서버로부터 송신한 내용
	//화면에 디스플레이
	char buf[80];
	int sendlen;
	int recvlen;
	int namelen = sizeof(saddr);

	while (1) {
		fgets(buf, 79, stdin); //문장을 입력하고 Enter을 하면 '\n'이 붙고 자동적으로 마지막에 '\0' 입력됨
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