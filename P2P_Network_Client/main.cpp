#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h> // inet_pton �Լ��� ���ǵ� ���

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // ���� �ʱ�ȭ
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup() failed" << std::endl;
        return 1;
    }

    // ���� ����
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "socket() failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // ���� �ּ� ����
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;

    // ���� IP �ּҸ� �ּ� ��Ʈ������ �Է¹���

    //char* serverIp = "127.0.0.1";
    //�� ����� �ּҸ� �ʱ�ȭ �Ҽ��� ����.
    // 
    //�Ʒ��� ����� �ϳ� ����

    char serverIp[16] = "127.0.0.1";
    // std::string serverIp = "127.0.0.1";

    // �ּ� ��Ʈ���� �ּ� ����ü�� ��ȯ
    if (inet_pton(AF_INET, serverIp, &serverAddr.sin_addr) != 1)
    {
        std::cerr << "inet_pton() failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    serverAddr.sin_port = htons(8080); // ���� ��Ʈ ��ȣ

    // ������ ����
    if (connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        std::cerr << "connect() failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server!" << std::endl;

    // ���� ����
    closesocket(sock);
    WSACleanup();

    return 0;
}