#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h> // inet_pton 함수가 정의된 헤더

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // 윈속 초기화
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup() failed" << std::endl;
        return 1;
    }

    // 소켓 생성
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "socket() failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 서버 주소 지정
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;

    // 서버 IP 주소를 주소 스트링으로 입력받음

    //char* serverIp = "127.0.0.1";
    //이 방식은 주소를 초기화 할수가 없다.
    // 
    //아래의 방식중 하나 선택

    char serverIp[16] = "127.0.0.1";
    // std::string serverIp = "127.0.0.1";

    // 주소 스트링을 주소 구조체로 변환
    if (inet_pton(AF_INET, serverIp, &serverAddr.sin_addr) != 1)
    {
        std::cerr << "inet_pton() failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    serverAddr.sin_port = htons(8080); // 서버 포트 번호

    // 서버에 접속
    if (connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "connect() failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server!" << std::endl;

    // 접속 해제
    closesocket(sock);
    WSACleanup();

    return 0;
}