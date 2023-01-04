#include <iostream>
#include "BasicServer.cpp"

using namespace std;

int main() {
	cout << "»ç¿ëÇÒ Server" << endl;
	cout << "Input : ";

	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		BasicServer bs;
		bs.Run();
		break;

	default:
		cout << "NotFound";
		break;
	}
}