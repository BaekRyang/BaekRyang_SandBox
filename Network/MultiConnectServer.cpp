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

	if (WSAStartup(MAKEWORD(2, 2), &wsa)) { // ws2_32.dll 초기화
		err_display("WSAStartup");
		return -1;
	}

	//소켓 생성
	SOCKET s_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Server Socket
	if (s_sock == INVALID_SOCKET) {
		err_display("socket()");
		return -1;
	}
	//bind() : LocalAddress(IP ADDR + Port NUM) + Socket 의 Association
	//bind가 필요로 하는 Parameter = Socket Descripter, Local Address(SOCKADDR_IN), Size

	SOCKADDR_IN saddr; //Local Address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY); //이 컴퓨터에서 사용할 수 있는 아이피를 자동으로 등록

	if (bind(s_sock, (SOCKADDR*)&saddr, sizeof(saddr))) {
		err_display("bind()");
		return -1;
	}

	//Listen : 소켓을 Listen상태로 만들고, 동시에 Listen Buffer(Wait Buffer)를 생성한다.
	if (listen(s_sock, SOMAXCONN/*최대값의 Buffer를 만든다*/)) {
		err_display("listen()");
		return -1;
	}

	SOCKADDR_IN caddr; //클라이언트의 정보를 저장할 공간
	int namelen = sizeof(caddr); //accept()의 3번째  Parameter
	 
	HANDLE th;
	while (1) { //무한히 송 수신을 할때는 무한루프 사용
		cout << "Waiting for connection....." << endl;
        /*                       IN            OUT         IN/OUT    */
		SOCKET c_sock = accept(s_sock, (SOCKADDR*)&caddr, &namelen); // c_socket은 caddr와 연결하기 위한 전용 소켓임
		if (c_sock == INVALID_SOCKET) {
			err_display("accept()");
			return -1;
		}
		cout << "Connected!" << endl;

		//Thread 생성
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
		//수신
		recvlen = recv(c_sock, buf, 80, 0); //정상적인 경우에는 recvlen에 수신된 바이트 수가 저장됨. 만약 0일경우는 정상적인 종료
		if (recvlen == 0 || recvlen == SOCKET_ERROR) { //정상적, 비정상적 종료가 생기면 break함
			cout << "Client connection close case" << endl;
			closesocket(c_sock);
			break;
		}

		//수신 데이터를 화면의 출력
			//수신 데이터를 문자열로 만들기 위해 강제적으로 마지막에 NULL 문자 입력
		buf[recvlen] = '\0';
		cout << "From client : " << buf << endl;

		//수신 데이터를 클라이언트에게 송신
		send(c_sock, buf, recvlen, 0);
	}
	return 0;
}