#include <iostream>
#include "BasicClient.cpp"

using namespace std;

int main() {
	cout << "»ç¿ëÇÒ Client" << endl;
	cout << "Input : ";

	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		BasicClient bs;
		bs.Run();
		break;

	default:
		cout << "NotFound";
		break;
	}
}