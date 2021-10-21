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

	//Multicast Addr("236.0.0.1") 및 Port Num 설정
	SOCKADDR_IN multicast_addr;
	multicast_addr.sin_family = AF_INET;
	Insert_IP("236.0.0.1", &multicast_addr.sin_addr); //"236.0.0.1" 주소로 Multicast를 사용하기 위해 IP를 입력해준다.
	multicast_addr.sin_port = htons(8000);

	int ttlVar = 16;
	if (setsockopt(c_sock, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&ttlVar, sizeof(ttlVar)) == SOCKET_ERROR) { //TTL을 ttlvar에 있는 값으로 설정한다.
		err_display("setsockopt()");
		return -1;
	}

	//방송용 파일을 읽어서 한줄씩 Receiver에게 송신
	//1. 파일을 연다
	FILE* fptr = NULL;
	fopen_s(&fptr, "news.txt", "r");
	if (fptr == NULL) {
		cout << "File not found" << endl;
		return -1;
	}

	//화면에 디스플레이
	char buf[80];
	int sendlen;

	while (1) {
		//file의 끝에 fptr이 있으면 종료
		if (feof(fptr)) {
			sendto(c_sock, "", 0, 0, (SOCKADDR*)&multicast_addr, sizeof(multicast_addr));
			cout << "전송이 완료되었습니다." << endl;
			break;
		}
		fgets(buf, 79, fptr); //문장을 입력하고 Enter을 하면 '\n'이 붙고 자동적으로 마지막에 '\0' 입력됨
		sendlen = strlen(buf);
		sendto(c_sock, buf, sendlen, 0, (SOCKADDR*)&multicast_addr, sizeof(multicast_addr));
		Sleep(1000);
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