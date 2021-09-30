#include <iostream>
using namespace std;

//0-1. arrCal.cc : 배열에 배열을 사용한 수식을 사용한 값을 저장
/*int main(int argc, char const* argv[])
{
	//5의 크기를 가진 배열을 선언
	int data[5];

	data[0] = 10; //idx0에 10 저장
	data[1] = 30 - 10; //idx1에 30-10 : 20 저장
	data[2] = data[0] + 2 * data[1]; //idx2에 idx0과 idx1*2 : 50를 저장
	data[3] = data[2] + 20;//idx3에 idx2 + 20 : 70저장
	data[4] = data[0] - data[3];//idx4에 idx0 - idx3 : -60 저장

	//반목문을 사용하여 배열에 있는 모든 값를 출력
	for (int i = 0; i < 5; i++)
		cout << "data[" << i << "]: " << data[i] << endl;

	//0 반환
	return 0;
}*/

//0-2. arrInitialize.cc : 범위기반 for문, element : array를 통해서 element에 선언된 변수에 array의 요소를 반복하여 할당한다.
/*int main(int argc, char const* argv[])
{
	//5의 크기의 배열을 선언후 idx0, 1, 2에 100, 200, 300을 저장. idx4, 5는 0이 저장
	int data[5] = { 100, 200, 300 };
	int a[50];

	//배열의 각 인덱스에 있는 값을 출력
	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;


	//5의 크기를 가진 배열을 선언후 0으로 초기화
	int zero[5] = { 0 };

	//범위 기반 for문을 사용하여 "zero"의 각 요소를 반복하여 data에 할당한다.
	//그런뒤 zero의 값이 할당된 data를 출력한다. "auto"를 사용한 이유는 element의 자료형은 뒤에오는 array와 같은 자료형을 사용해야하기 때문에
	//컴파일러에서 자동으로 자료형을 선택하는 auto를 사용한다.(zero의 자료형을 따라감)

	//zero에 있는 값들을 출력한다.
	for (auto data : zero)
		cout << data << endl;

	//0 반환
	return 0;
}*/


//0-3. arrPrint.cc
/*int main(int argc, char const* argv[])
{
	//5의 크기를 가진 배열을 선언후 0으로 초기화
	int data[5];

	//정수형 변수 선언
	int idx = 0;
	//idx를 0~4까지 반복
	while (idx < 5) {
		//각 data배열에 (idx + 1) * 10 : 10, 20, 30... 할당
		data[idx] = (idx + 1) * 10;
		idx++;
	}

	//data에 있는 값들을 출력
	//아래에 있는 cout을 사용한 것과 같은 역할을 함(효율적)
	for (idx = 0; idx < 5; idx++)
		cout << "data[" << idx << "]: " << data[idx] << endl;

	// cout << "data[0]: " << data[0] << endl;
	// cout << "data[1]: " << data[1] << endl;
	// cout << "data[2]: " << data[2] << endl;
	// cout << "data[3]: " << data[3] << endl;
	// cout << "data[4]: " << data[4] << endl;

	//0 반환
	return 0;
}*/

//0-4. arrSize.cc
/*int main(int argc, char const* argv[])
{
	//data배열을 선언후 1~13값으로 초기화
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

	cout << "배열에 할당된 메모리 크기: " << sizeof(data) << endl;//배열의 할당된 메모리 크기 출력 : int형 데이터는 하나당 4byte를 사용, 13개의 저장공간을 가지므로 52 출력
	cout << "배열의 데이터 요소에 할당된 메모리 크기: " << sizeof(data[0]) << endl;//배열 하나에 할당된 메모리 크기를 출력 : int형 데이터이기 때문에 4 출력
	cout << "배열의 크기: " << sizeof(data) / sizeof(data[0]) << endl;//배열의 크기를 출력 : 52/4이므로 배열의 크기인 13출력

	return 0;
}*/

//0-5. arrSum.cc
/*int main(int argc, char const* argv[])
{
	//5의 크기의 배열을 선언후 100, 200, 300... 으로 초기화
	int data[5] = { 100, 200, 300, 400, 500 };

	//정수형 변수 선언
	int sum = 0;

	//배열에 있는 모든 값을 sum에 더함
	sum += data[0];
	sum += data[1];
	sum += data[2];
	sum += data[3];
	sum += data[4];

	//값들을 모두 더한 sum 값을 출력 : 1500 출력
	cout << "sum: " << sum << endl;

	return 0;
}*/



//0-6. arrayFor.cc
/*int main(int argc, char const* argv[])
{
	//배열을 선언후 50, 40, 30으로 초기화(배열의 크기는 3으로 자동 설정)
	int score[] = { 50, 40, 30 };

	//범위 기반 for문을 사용하여 score의 있는 값들을 출력
	for (auto data : score)
		cout << data << endl;
		//50
		//40
		//30

	return 0;
}*/

//0-7. arrayWhile.cc : arrPrint.cc 와 같은 코드이지만 출력부분이 for문을 사용하지 않음
/*int main(int argc, char const* argv[])
{
	//5의 크기의 배열 선언
	int data[5];

	//정수형 변수 선언
	int idx = 0;

	//data배열에 10, 20, 30.. 할당
	while (idx < 5) {
		data[idx] = (idx + 1) * 10;
		idx++;
	}

	//배열의 각 데이터 출력
	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	return 0;
}*/

//0-8. charArray.cc
/*int main(int argc, char const *argv[])
{
	//문자 배열 선언후 "Hello World!" 저장
	char str[] = "Hello World!";
	
	//문자 배열 출력 : "Hello World!" 출력
	cout << str << endl;

	return 0;
}*/

//0-9. simpleArrAssign.cc
/*int main(int argc, char const* argv[])
{
	//5의 크기의 배열 선언
	int data[5];

	//배열에 값 저장
	//세미콜론으로 줄을 구분하지 않고도 ,를 이용해서 값 저장 가능
	data[0] = 10, data[1] = 20;				  // assign value
	data[2] = 30, data[3] = 40, data[4] = 50; // assign value

	//배열의 값 출력
	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	return 0;
}*/

//0-10. simpleArray.cc
/*int main(int argc, char const* argv[])
{
	//5의 크기를 가진 정수형 배열 선언(초기화X)
	int data[5];

	//각 배열에 있는 값 출력
	//배열이 초기화 되지 않았기 때문에 쓰레기 값이 출력됨 (-858993460)
	cout << "1st data: " << data[0] << endl;
	cout << "2nd data: " << data[1] << endl;
	cout << "3rd data: " << data[2] << endl;
	cout << "4th data: " << data[3] << endl;
	cout << "5th data: " << data[4] << endl;

	//배열의 크기가 5이기 때문에 data[5]는 존재하지 않기에 이것도 쓰레기 값이 출력된다.(배열을 0으로 초기화 하여도 쓰레기값 출력)
	//cout << "6th data: " << data[5] << endl;

	return 0;
}*/


//1.문자열 배열에 "Game Engineering Major"를 저장하고 문자의 갯수를 구해 출력하는 프로그램을 작성하시오.
/*int main()
{
	char str[] = "Game Engineering Major";
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		len += 1;
	}

	cout << "문자열 길이 : (공백포함)" << len << "개";
}*/

//2."Game Engineering Major"를 문자열 배열에 저장하고 문자열 배열에서 문자 'a'의 게수와 문자 'e'의 개수를 구하여 출력하는 프로그램을 작성하시오.
/*int main()
{
	char str[] = "Game Engineering major";
	int count_a = 0;
	int count_e = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'a') {
			count_a += 1;
		}
		else if (str[i] == 'e') {
			count_e += 1;
		}
	}

	cout << "a의 갯수 : " << count_a << endl;
	cout << "e의 갯수 : " << count_e ;
}*/

//3-1. 피보나치 수열 [a(n) = a(n-1) + a(n-2); 1, 1, 2, 3, 5, 8, 13, 21, 34) 을 20항 까지 출력하는 프로그램을 작성하시오.
/*int main()
{
	int num1 = 0, num2 = 0, result = 1;
	for (int i = 1; i < 21; i++) {
		cout << i << "번째 : " << result << endl;
		num2 = result;
		result = num1 + num2;
		num1 = num2;
	}
}*/
//3-2. 피보나치 수열 [a(n) = a(n-1) + a(n-2); 1, 1, 2, 3, 5, 8, 13, 21, 34) 을 20항 까지 출력하는 프로그램을 작성하시오.(배열 사용)
/*int main()
{
	int num1 = 0, num2 = 0, result = 1;
	int pibo[20];
	for (int i = 1; i < 21; i++) {
		pibo[i - 1] = result;
		num2 = result;
		result = num1 + num2;
		num1 = num2;
	}
	for (int i = 0; i < 20; i++) {
		cout << i+1 << "번째 : " << pibo[i] << endl;
	}
}*/

//4. 키보드로 부터 정수를 하나 입력받아 피보나치 수열 [a(n) = a(n-1) + a(n-2); 1, 1, 2, 3, 5, 8, 13, 21, 34)을 N 항까지 출력하는 프로그램을 작성하시오. (정상적으로 출력되는 N의 값의 범위를 검토하시오.)
/*int main()
{
	int num = 0;

	cout << "정수를 입력해 주세요 : "; 
	cin >> num; //46번째 까지 정상적으로 출력됨

	float num1 = 0, num2 = 0, result = 1;
	for (int i = 1; i < num+1; i++) {
		cout << i << "번째 : " << result << endl;
		num2 = result;
		result = num1 + num2;
		num1 = num2;
	}
}*/

//5. 키보드로 부터 1 이상의 정수(n)를 하나 입력받은 후 다음과 같은 출력되는 프로그램을 작성하시오.
/*int main()
{
	int num = 0;
	cout << "정수를 입력하세요";
	cin >> num;

	for (int i = 0; i < num + 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
}*/

//6. 키보드로 부터 1 이상의 정수(n)를 하나 입력받은 후 다음과 같은 출력되는 프로그램을 작성하시오.(역순)
/*int main()
{
	int num = 0;
	cout << "정수를 입력하세요";
	cin >> num;

	//줄바꿈
	for (int i = 0; i < num; i++) { //위에서 입력한 수 만큼 줄바꿈이 일어날 것이므로 (5 입력시 4번 줄바꿈) i < num 으로 줄바꿈을 해줄 횟수를 정한다.

		//공백 출력 - 공백은 (입력받은 수 - 현재 라인에 필요한 * 개수) 이므로 조건식으로 num - ( i + 1 )을 사용한다.
		//아래 for문과는 다르게 i + 1 에 괄호를 사용하지 않으면 공백이 하나더 출력되는 문제가 생긴다.
		for (int j = 0; j < num - ( i + 1 ); j++) {
			cout << " ";
		}

		//"*"출력 - "*"의 개수는 n번째 줄에 n개가 들어가므로 조건식으로 k < i + 1 을 사용하여 "*" 을 출력한다.
		for (int k = 0; k < i + 1 ; k++) {
			cout << "*";
		}

		//위에 있는 과정들이 끝나면 endl을 해주어 다음 줄로 넘겨준다.
		cout << endl;
	}
}*/

//7. 키보드로 부터 1 이상의 정수(n)를 하나 입력받은 후 다음과 같은 출력되는 프로그램을 작성하시오.(피라미드)
/*int main()
{
	int num = 0;
	cout << "정수를 입력하세요";
	cin >> num;

	//줄바꿈
	for (int i = 0; i < num; i++) { //위에서 입력한 수 만큼 줄바꿈이 일어날 것이므로 (5 입력시 4번 줄바꿈) i < num 으로 줄바꿈을 해줄 횟수를 정한다.

		//공백 출력 - 이번 식 에서의 공백은 " 출력 할 라인 수 - (출력중인 라인의 수 - 1) "을 사용하면 매 라인마다 공백의 수가 적당하게 출력된다.
		for (int j = 0; j < num - ( i + 1 ); j++) {
			cout << "  ";
		}

		//"*"출력 - "*"의 개수는 1, 3, 5 식으로 라인별로 증가하므로 i * 2 +1 을 사용한다.
		for (int k = 0; k < i * 2 + 1 ; k++) {
			cout << "* ";
		}

		//공백 출력 - 위에 공백 출력과 같은수의 공백을 출력해야하므로 같은 식을 사용
		for (int j = 0; j < num - (i + 1); j++) {
			cout << "  ";
		}

		//위에 있는 과정들이 끝나면 endl을 해주어 다음 줄로 넘겨준다.
		cout << endl;
	}
}*/

//8. 키보드로 부터 정수 두 개(a, b)를 입력받아 a를 b로 나누었을 때의 실수 값의 정수 값과 소수 값을 각각 구해서 출력하는 프로그램을 작성하시오.
/*int main()
{
	//정수를 입력받을 변수 2개(a, b) 선언
	int a = 0, b = 0;
	//정수 부분을 저장할 정수형 변수 선언
	int INT = 0;
	//소수 부분을 저장할 실수형 변수 선언
	float DEC = 0.0f;

	//분모가 될 a를 입력받음
	cout << "분모를 입력하세요 : ";
	cin >> a;

	//분자가 될 b를 입력받음
	cout << "분자를 입력하세요 : ";
	cin >> b;

	//정수부분은 간단히 a / b 를 통하여 구할 수 있음
	INT = a / b;

	//소수 부분은 (float)를 통하여 명시적 형변환을 함, 그리고 소수부분만 분리하기 위하여 정수부분인 "INT"를 뺌 
	DEC = (a / (float)b) - INT;

	//결과값 출력
	cout << "정수값 : " << INT << endl;
	cout << "소수값 : " << DEC;
}*/

//9. 정수 5개를 저장 할 수 있는 저장공간을 할당한 후 키보드로 부터 서로 다른 정수를 입력받아 저장한 후 최소값과 최대값을 찾아 출력하는 프로그램을 작성하시오.
/*int main()
{
	//정수 5개를 저장 할 수 있는 공간 할당
	int ary[5];

	//for문을 통하여 배열에 하나하나 정수를 입력해준다.
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 정수를 입력해주세요 : ";
		cin >> ary[i];
	}

	//최대값과 최소값을 저장한 정수형 변수 선언 및 비교할 대상이 필요하므로 첫번쨰 인덱스의 값을 할당
	int MAX = ary[0];
	int MIN = ary[0];

	//배열에 있는 각 숫자마다 비교를 하기 위해 반복문 사용
	for (int i = 1; i < 5; i++) {
		//비교중인 수(ary[i])가 현재 최대값으로 저장된수(MAX)보다 크면 MAX에 ary[i]를 저장하는 방식으로 제일 큰 수를 MAX에 저장한다.
		if (MAX < ary[i]) {
			MAX = ary[i];
		}
		//비교중인 수 가 최대값보다 작다면 그 다음으로는 최소값보다 작은지 확인한다.
		//비교중인 수(ary[i])가 현재 최소값으로 저장된수(MIN)보다 작으면 MIN에 ary[i]를 저장하는 방식으로 제일 작은 수를 MIN에 저장한다.
		else if (MIN > ary[i]) {
			MIN = ary[i];
		}
	}

	//결과값 출력
	cout << MAX << endl;
	cout << MIN;
}*/

//10. 정수 5개를 저장할 수 있는 저장공간을 할당한 후 키보드로 부터 서로 다른 정수를 입력받아 저장한 후 최소값과 최대값이 저장된 배열의 인덱스를 출력하는 프로그램을 작성하시오.
/*int main()
{
	//정수 5개를 저장 할 수 있는 공간 할당
	int ary[5];

	//for문을 통하여 배열에 하나하나 정수를 입력해준다.
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 정수를 입력해주세요 : ";
		cin >> ary[i];
	}

	//최대값과 최소값을 저장한 정수형 변수 선언 및 비교할 대상이 필요하므로 첫번쨰 인덱스의 값을 할당
	//또한 최대/최소값의 인덱스를 저장할 변수또한 선언
	int MAX = ary[0];
	int MAX_IDX = 0;
	int MIN = ary[0];
	int MIN_IDX = 0;

	//배열에 있는 각 숫자마다 비교를 하기 위해 반복문 사용
	for (int i = 1; i < 5; i++) {
		//비교중인 수(ary[i])가 현재 최대값으로 저장된수(MAX)보다 크면 MAX에 ary[i]를 저장하는 방식으로 제일 큰 수를 MAX에 저장한다.
		//그리고 그 수의 인덱스(i+1)를 변수에다 저장한다.
		if (MAX < ary[i]) {
			MAX = ary[i];
			MAX_IDX = i+1;
		}
		//비교중인 수 가 최대값보다 작다면 그 다음으로는 최소값보다 작은지 확인한다.
		//비교중인 수(ary[i])가 현재 최소값으로 저장된수(MIN)보다 작으면 MIN에 ary[i]를 저장하는 방식으로 제일 작은 수를 MIN에 저장한다.
		//그리고 그 수의 인덱스(i+1)를 변수에다 저장한다.
		else if (MIN > ary[i]) {
			MIN = ary[i];
			MIN_IDX = i+1;
		}
	}

	//결과값 출력
	cout << "최대값은 MAX[" << MAX_IDX << "]에 저장된 " << MAX << "입니다. INDEX : " << MAX_IDX << endl;
	cout << "최소값은 MIX[" << MIN_IDX << "]에 저장된 " << MIN << "입니다. INDEX : " << MIN_IDX << endl;
}*/

//11. 데이터를 반복문을 사용하여 2차원 배열에 저장한 후 출력되는 프로그램을 작성하시오.(가로)
/*int main()
{
	//2차원 배열에 데이터 저장
	int data[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	//반복문을 사용하여 저장된 값 출력
	//2차원 배열이므로 반복문도 두개를 사용하여 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 10미만 수의 줄맞춤을 위해 10미만의 수는 공백을 포함하여 출력
			if (data[i][j] < 10) {
				cout << " " << data[i][j] << " ";
			}
			//10이상 수는 그대로 출력
			else {
				cout << data[i][j] << " ";
			}
		}
		//배열의 한 행을 출력했으면 줄바꿈
		cout << endl;
	}
}*/

//12. 데이터를 반복문을 사용하여 2차원 배열에 저장한 후 출력되는 프로그램을 작성하시오.(세로)
/*int main()
{
	//2차원 배열에 데이터 저장
	int data[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	//반복문을 사용하여 저장된 값 출력
	//2차원 배열이므로 반복문도 두개를 사용하여 출력

	//위에 식과 방법은 똑같지만 출력하는 순서를 바꾸기 위해 data[i][j] → data[j][i] 를 통해 행이 아닌 열을 우선순서로 반복하여 출력함

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 10미만 수의 줄맞춤을 위해 10미만의 수는 공백을 포함하여 출력
			if (data[j][i] < 10) {
				cout << " " << data[j][i] << " ";
			}ㅋ
			//10이상 수는 그대로 출력
			else {
				cout << data[j][i] << " ";
			}
		}
		//배열의 한 행을 출력했으면 줄바꿈
		cout << endl;
	}
}*/