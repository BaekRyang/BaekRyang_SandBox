#include <iostream>


//키와 체중을 cm와 kg 단위로 소수 첫째 자리까지 입력 받아 BMI를 계산하여 출력하시오. [BMI: 체중/(키(m) * 키(m))]
int main()
{
    using namespace std;
    short height;
    short weight;
    cout << "키를 입력하세요(cm) : ";
    cin >> height;
    cout << "몸무게를 입력하세요(kg) : ";
    cin >> weight;
    cout << "키 : " << height << "cm / 몸무게 : " << weight << "kg" << endl;
    cout << "BMI : " << weight / ((height / 100) ^ 2);
    cout << "height x height = " << (height ^ 2);
}

//정수 두 개 (a ,b)를 입력 받아 a/b를 계산하고 출력하고 발생하는 문제가 무엇인지 확인하시오.
/*int main()
{
    using namespace std;
    float a;
    float b;
    cout << "a를 입력하세요 : ";
    cin >> a;
    cout << "b를 입력하세요 : ";
    cin >> b;
    while (b == 0) {
        cout << "0으로 나눌수 없습니다." << endl;
        cout << "b를 입력하세요 : ";
        cin >> b;
    }
    auto c = a / b;
    cout << c << endl;
}*/

//short 형 변수 하나를 입력하고 언더플로우와 오버플로우가 발생하도록 값을 저장하고 확인하시오.
/*int main()
{
    using namespace std;
    short a;
    short b;
    a = 32768;
    b = -32769;
    cout << a << endl;
    cout << b << endl;
}*/

//정수 성적(0 ~ 100)을 입력받아 95점 이상 "A+", 90점 이상 94점 이하 "A",
//85점 이상 89점 이하 "B+", 80점 이상 84점 이하 "B", 75점 이상 79점 이하 "C+",
//70점 이상 74점 이하 "C", 65점 이상 69점 이하 "D+", 60점 이상 64점 이하 "D",
//60점 미만 "F" 로 출력하는 프로그램 작성하사오. (if-else if-else문 사용)
/*int main()
{
    using namespace std;
    short a;
    cout << "성적을 입력하십시오 : ";
    cin >> a;
    if (a >= 95) {
        cout << "A+";
    }
     else if (a >= 90) {
         cout << "A";
     }
     else if (a >= 85) {
         cout << "B+";
     }
     else if (a >= 80) {
         cout << "B";
     }
     else if (a >= 75) {
         cout << "C+";
     }
     else if (a >= 70) {
         cout << "C";
     }
     else if (a >= 65) {
         cout << "D+";
     }
     else if (a >= 60) {
         cout << "D";
     }
     else {
         cout << "F";
     }
}*/

//정수를 입력받아 절대값을 구하는 프로그램을 if-else문을 사용하여 작성하시오.
/*int main() {
    using namespace std;
    short num;
    cout << "숫자를 입력하세요";
    cin >> num;
    if (num >= 0) {
        cout << num << "의 절댓값 : " << num << endl;
    }
    else {
        cout << num << "의 절댓값 : " << num*-1 << endl;
    }
}*/

//while 문을 사용하여 "Hello World!" 문을 10번 출력하는 프로그램 작성하시오.
/*int main() {
    using namespace std;
    short count = 0;
    while (count < 10) {
        cout << "Hello World!" << endl;
        count++;
    }
}*/

//이전의 구구단 프로그램을 while 문을 사용하여 작성하시오.
/*int main()
{
    short count = 0;
    using namespace std;
    short in;
    cout << "input : ";
    cin >> in;

    while (count < 10) {
        cout << in << " X " << (count + 1) << " = " << in * (count + 1) << endl;
        count++;
    }
    //(count+1)을 사용하는 대신 새로운 변수를 사용해서 표현 가능
}*/