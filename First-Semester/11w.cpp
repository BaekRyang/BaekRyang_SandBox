#include <iostream>
using namespace std;

//1.학생 정보(학번, 이름, 학과)를 구성하는 Student 구조체를 정의하고 학생 정보 5개를 저장할 수 있는 배열 변수를 선언하고 할당된 저장 공간에 데이터를 저장한 후 참조변수와 포인터 변수를 선언하고 배열의 인덱스, 참조변수, 포인터 변수를 통해 저장된 데이터를 수정한 후 출력하는 프로그램을 작성하시오.
//int main() {
//	struct Student
//	{
//		int ID;
//		char name[20];
//		char dpm[30];
//	};
//	Student stds[5];
//	stds[0] = { 20200001, "Hong_Gil_Dong", "Cumputer_Enginereeing" };
//	stds[1] = { 20200002, "Gang_Woo_Seok", "Bio_Technology" };
//	stds[2] = { 20200003, "Nam_Chang_Mi", "English_Language" };
//	stds[3] = { 20200004, "Im_Soo_Jung", "Public_Policy" };
//	stds[4] = { 20200005, "Park_Ji_Sung", "Advertising" };
//
//	//배열의 인덱스를 이용해여 변경
//	stds[0].ID = 20210009;
//
//	//참조변수 선언 후 변경
//	int& refid = stds[1].ID;
//	refid = 20200005;
//
//	//포인터변수 선언후 변경
//	Student* pntName = &stds[2];
//	pntName->ID = 20210010;
//
//	for (int i = 0; i < 5; i++) {
//		cout << stds[i].ID << endl;
//		cout << stds[i].name << endl;
//		cout << stds[i].dpm << endl << endl;
//	}
//
//}

//2.최대공약수를 구하는 알고리즘으로 유클리드 호제법이 존재한다. 유클리드 호제법을 활용해서 최대 공약수를 구해주는 함수 int GCD(int a, int b)를 구현하고 main() 함수에서 이 함수를 호출하여 함수 구현을 검증하시오. (반환 값은 최대 공약수를 반환하며 서로소인 경우 1을 반환하시오)
//int GCD(int, int);
//
//int main() {
//	cout << "최대공약수 : " << GCD(78696, 19332);
//}
//
//int GCD(int a, int b) {
//	//계산에 사용할 변수 3개를 선언후 초기화 한다.
//	int denominator = 0, rmdNum = 0, dnmTemp = 0;
//	//a/b의 나머지가 0이면 b가 최대공약수 이므로 IF문으로 분기를 나누어 준다.
//	if (a % b != 0) {
//		//나누어 떨어지지 않는다면 나머지와 분모를 저장한다.
//		rmdNum = a % b;
//		denominator = b;
//		//두 수가 나누어 떨어질 때 까지 반복한다.
//		while (denominator % rmdNum != 0) {
//			dnmTemp = denominator;
//			denominator = rmdNum;
//			rmdNum = dnmTemp % rmdNum;
//			//계산이 끝났을 때 두 수가 나누어 떨어진다면 두번째 수가 최대 공약수 이므로 rmdNum을 반환한다.
//			if (denominator % rmdNum == 0) {
//				return rmdNum;
//			}
//		}
//	}
//	else {
//		return b;
//	}
//}

//3. 포인터 변수를 활용한 프로그램을 작성하시오.
//void multiplyNum(int*, int);
//int main() {
//	//사용할 변수 두개를 선언한다.
//	int input = 0;
//	int num = 2;
//	//포인터 변수를 선언한다.
//	int* pointer;
//	//포인터 변수에 num의 주소값을 저장한다.
//	pointer = &num;
//	cin >> input;
//	cout << num << "^" << input << "=";
//	//num의 값을 입력받은 값 만큼 제곱시켜주는 코드
//	multiplyNum(pointer, input);
//	cout << num;
//
//}
//
//void multiplyNum(int* num, int mltNum) {
//	int temp = *num;
//	//num을 mltNum으로 받은 만큼 반복해서 제곱 시켜준다.
//	for (int i = 1; i < mltNum; i++) {
//		*num *= temp;
//	}
//}

//4. bool search(int arr[], int len, int x) 함수를 구현하시오.
//bool search(int[], int, int);
//int main() {
//	//찾을 값을 저장할 변수와 배열을 선언한다.
//	int src = 0;
//	int array[10] = { 0 };
//	//배열에 키보드로 입력을 받아 저장한다.
//	for (int i = 0; i < 10; i++) {
//		cout << "Array : ";
//		cin >> array[i];
//	}
//	//찾을 값을 입력받는다.
//	cout << "Find ? : ";
//	cin >> src;
//	cout << search(array, 10, src);
//}
//
//bool search(int arr[], int len, int x) {
//	//배열에 반복문을 이용하여 값=찾는 값이 생기면 true를 반환한다.
//	for (int i = 0; i < len; i++) {
//		if (arr[i] == x) {
//			return 1;
//		}
//	}
//	//true를 반환하지 못하고 반복문이 끝나면 false를 반환한다.
//	return 0;
//}

//5.int primeNum(int N) 함수를 구현하시오.
int primeNum(int);

int main() {
	int num = 0;
	cin >> num;
	cout << "최대크기의 소수 : "<<primeNum(num);
}

int primeNum(int N) {
	int maxPrime = 0;
	//동적 할당으로 배열을 N개만큼 생성해준다.
	int* array = new int[N];

	//배열에 값들을 초기화 시킨다.
	for (int i = 2; i < N; i++) {
		array[i] = i;
	}
	
	//첫번째 for문은 나누는 값을 정해준다.
	for (int i = 2; i < N; i++) {
		//두번째 for문은 배열을 순환한다.
		for (int j = 2; j < N; j++) {
			//만약 순환중인 배열의 값이 나누는 값이랑 같지 않은데 나누어 떨어진다면 소수가 아니므로 0으로 만들어준다.
			//자신이 아닌 자신의 배수를 제거해준다.
			if (array[j] != i && array[j] % i == 0) array[j] = 0;
		}
	}

	//남은 값들중 가장 큰 수를 위에서 부터 순환하며 제일 먼저 나오는 수가 제일 큰 수이므로 그 수를 저장한다.
	for (int i = N-1; i > 1; i--) {
		if (array[i] != 0) {
			maxPrime = array[i];
			break;
		}
	}
	//동적 할당했던 배열을 삭제한다.
    //delete array를 했더니 "array가 new[]를 이용해 할당되었지만 스칼라 delete로 삭제되었습니다." 라고 나온다.
	//delete[] array로 삭제해준다.
	delete[] array;
	//최고값 반환
	return maxPrime;
}