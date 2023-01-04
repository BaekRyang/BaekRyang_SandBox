#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	// 扩加 檬扁拳
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		cout << "WSAStartup failed: " << result << endl;
		return 1;
	}

	// 家南 积己
	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSocket == INVALID_SOCKET) {
		cout << "socket failed: " << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}

	// IP林家客 器飘甫 Bind
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(8080);
	result = bind(listenSocket, (SOCKADDR*)&service, sizeof(service));
	if (result == SOCKET_ERROR) {
		cout << "bind failed: " << WSAGetLastError() << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	// 立加 Listen 贸府
	result = listen(listenSocket, SOMAXCONN);
	if (result == SOCKET_ERROR) {
		cout << "listen failed: " << WSAGetLastError() << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	// 立加 accept
	SOCKET acceptSocket = accept(listenSocket, NULL, NULL);
	if (acceptSocket == INVALID_SOCKET) {
		cout << "accept failed: " << WSAGetLastError() << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	// Client俊霸 Message 傈崔
	const char* message = "Hello, client!";
	result = send(acceptSocket, message, strlen(message), 0);
	if (result == SOCKET_ERROR) {
		cout << "send failed: " << WSAGetLastError() << endl;
		closesocket(acceptSocket);
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	// 家南 辆丰
	closesocket(acceptSocket);
	closesocket(listenSocket);
	WSACleanup();

	return 0;
}
