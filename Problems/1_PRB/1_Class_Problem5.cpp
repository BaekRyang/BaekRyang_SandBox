#include <iostream>

using namespace std;
class CDNPlane
{
private:
	int posX, posY, width, height, area;

public:
	CDNPlane(int x, int y, int w, int h) : posX(x), posY(y), width(w), height(h) {
		area = width * height;
	}
	//Ŭ������ �μ��� ���μ����� ����, x,y��ǥ�� �޴´�.
	void PrintAll() {
		cout << "������ (" << posX << ", " << posY << ")" << endl << "�ʺ� : " << width << endl << "���� : " << height << endl;
		//��µ� �簢���� �ʹ� ���� �����ʵ��� ScreenSize�� �簢���� ��ġ�� ������ 3ũ�� �ؼ� �������
		int scrWidth = posX + width + 3;
		int scrHeight = posY + height + 3;
		
		//i�� y���� �׸��� loop�� y�� �ִ밪�� srcHeight�̰� �ּҰ��� 0���� ����ش�.
		for (int i = scrHeight; i > -1; i--) {
			//j�� x���� �׸��� loop x�� �ִ밪�� srcWidth�̰� �ּҰ��� 0���� ���ش�.
			for (int j = 0; j < scrWidth; j++) {
				//�簢���� ���� ������ ĭ�� ����ش�. �Ʒ��� �ش� ���ǵ��̴�
				//���� �׸��� y �Ǵ� x���� ���������� ������
				//���� �׸��� y �Ǵ� x���� ������ + �ʺ���̺��� Ŭ��
				if (j < posX || i<posY || j>(posX + width) || i>(posY + height)) {
					if (!i || !j) {
						//x�Ǵ� y��ǥ�� 0�̸� ��ǥ���̹Ƿ� �ٸ��� ǥ���Ѵ�.
						cout << "��";
					}
					else {
						//�̿ܿ��� ĭ�� ����ش�.
						cout << "��";
					}
				}
				else {
					//��ǥ�൵ �ƴϸ鼭 �簢���� ���� �ȿ� ������ ä���� �簢���� ����Ѵ�.
					cout << "��";
				}
			}
			//������ ����ϰ��� �� �ٲ��� ���ش�.
			cout << endl;
		}
	}
	//Ŭ������ ���� ������ ��ȯ�Ѵ�.
	int GetSpec(int _input) {
		switch (_input)
		{
		case 1:
			return width;
			break;
		case 2:
			return height;
			break;
		case 3:
			return posX;
			break;
		case 4:
			return posY;
			break;
		default:
			cout << "1. Width" << endl << "2. Height" << endl << "3. X Position" << endl << "4. Y Position" << endl;
			return 0;
			break;
		}
	}
	//�ٸ� CDNPlane���� ��, �μ��� CDNPlane���� �޴´�.
	bool BiggerThan(CDNPlane _other) {
		if ((_other.width * _other.height) > area) {
			return false;
		}
		return true;
	}
};

int main() {
	CDNPlane firstPlane(5, 0, 10, 10);
	CDNPlane secondPlane(0, 5, 7, 7);
	firstPlane.PrintAll();
	
	cout << firstPlane.BiggerThan(secondPlane) << endl;
	cout << secondPlane.BiggerThan(firstPlane) << endl;
}
