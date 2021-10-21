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

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll 초기화
		err_display("WSAStartup");
		return -1;
	}

	//소켓 생성
	SOCKET s_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Server Socket
	if (s_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}

	SOCKADDR_IN saddr; //Local Address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); //이 컴퓨터에서 사용할 수 있는 아이피를 자동으로 등록

	SOCKADDR_IN caddr; //클라이언트의 정보를 저장할 공간
	int namelen = sizeof(caddr); //recvform의 마지막 Parameter

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
		//수신
		recvlen = recvfrom(s_sock, buf, 80, 0, (SOCKADDR*)&caddr, &namelen); //정상적인 경우에는 recvlen에 수신된 바이트 수가 저장됨. 만약 0일경우는 정상적인 종료
		if (recvlen == 0) { //정상적, 비정상적 종료가 생기면 break함
			cout << "Client connection normal close case" << endl;
			err_display("recvform()");
			break;
		}
		else if (recvlen == SOCKET_ERROR) {
			cout << "Client connection abnormal(RST) close case" << endl;
			err_display("recvform()");
			break;
		}


		//수신 데이터를 화면의 출력
		//수신 데이터를 문자열로 만들기 위해 강제적으로 마지막에 NULL 문자 입력
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