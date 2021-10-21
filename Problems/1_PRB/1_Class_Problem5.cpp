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
	//클래스의 인수로 가로세로의 넓이, x,y좌표를 받는다.
	void PrintAll() {
		cout << "기준점 (" << posX << ", " << posY << ")" << endl << "너비 : " << width << endl << "높이 : " << height << endl;
		//출력된 사각형이 너무 벽에 붙지않도록 ScreenSize를 사각형이 위치한 곳보다 3크게 해서 만들어줌
		int scrWidth = posX + width + 3;
		int scrHeight = posY + height + 3;
		
		//i는 y축을 그리는 loop임 y의 최대값은 srcHeight이고 최소값은 0으로 잡아준다.
		for (int i = scrHeight; i > -1; i--) {
			//j는 x축을 그리는 loop x의 최대값도 srcWidth이고 최소값은 0으로 해준다.
			for (int j = 0; j < scrWidth; j++) {
				//사각형이 없는 조건은 칸을 비워준다. 아래는 해당 조건들이다
				//현재 그리는 y 또는 x값이 기준점보다 작을때
				//현재 그리는 y 또는 x값이 기준점 + 너비높이보다 클때
				if (j < posX || i<posY || j>(posX + width) || i>(posY + height)) {
					if (!i || !j) {
						//x또는 y좌표가 0이면 좌표축이므로 다르게 표시한다.
						cout << "▣";
					}
					else {
						//이외에는 칸을 비워준다.
						cout << "□";
					}
				}
				else {
					//좌표축도 아니면서 사각형의 범위 안에 있으면 채워진 사각형을 출력한다.
					cout << "■";
				}
			}
			//한줄을 출력하고나서 줄 바꿈을 해준다.
			cout << endl;
		}
	}
	//클래스의 내부 설정을 반환한다.
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
	//다른 CDNPlane과의 비교, 인수를 CDNPlane형을 받는다.
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
