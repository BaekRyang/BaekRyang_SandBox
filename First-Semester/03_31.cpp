// 03_31.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//1.    
/*int main()
{
    int a = 0;
    for (int i = 0; i < 10; i++) {
        a += i + 1;
    }
    cout << a;
}*/

//2.
/*int main()
{
    int a = 0;
    int b = 0;
    cout << "1이상의 수를 입력해주세요 : ";
    cin >> a;
    while (a < 1) {
        cout << "유효하지 않은 숫자입니다." << endl << "1이상의 수를 입력해주세요.";
        cin >> a;
    }

    for (short i = 1; i < a+1; i++) {
        b += i;
    }
    cout << b;
}*/

//3.
/*int main()
{
    int even = 0;
    int odd = 0;

    for (short i = 1; i < 101; i++) {
        if (i % 2 == 0){
            even += (i);
        }
        else {
            odd += (i);
        }
    }

    cout << "짝수의 합 = " << even << endl;
    cout << "홀수의 합 = " << odd;
}*/

//4.
/*int main()
{
    int STR[5] = { };
    for (short i = 0; i < 5; i++) {
        cout << "STR[" << i << "] = " << STR[i] << endl;
    }
}*/

//5.
/*int main()
{
    int STR[] = {87, 92, 89, 98, 78};
    int SUM_STR = 0;
    for (short i = 0; i < 5; i++) {
        SUM_STR += STR[i];
    }
    cout << SUM_STR;
}*/

//6.
/*int main()
{
    int STR[10];
    cout << "숫자를 입력해주세요";
    cin >> STR[0];
    cout << "STR[0] = " << STR[0] << endl;
    for (short i = 1; i < 10; i++) {
        STR[i] = STR[i-1] + 10;
        cout << "STR[" << i << "] = " << STR[i] << endl;
    }
}*/

//7.
/*int main()
{
    char str[] = "Hello World!";
    for (short i = 0; i < sizeof(str); i++) {
        cout << "str[" << i << "] = " << str[i] << endl;
    }
}*/


//8-1. "Hello_World"를 문자 배열로 입력받은 뒤 거꾸로 출력하는 프로그램을 작성하시오.
/*int main()
{
    char str[] = { "Hello_World" };
    for (short i = sizeof(str)-1; i > -1; i--) {
        cout << str[i];
    }
}*/


//8-2. 정수형 데이터 20개를 저장할 수 있는 저장공간을 할당한 뒤 1~20를 저장한후 홀수가 들어있는 배열만 출력하는 프로그램을 작성하시오 (조건문이 아닌 반복문만 사용하여 작성)
/*int main()
{
    int arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 1; i < 20; i+=2)
    {
        cout << arr[i];
    }
}*/


//.
/*int main()
{

}
*/