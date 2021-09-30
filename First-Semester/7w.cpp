#include <iostream>
using namespace std;

//1. 10개의 정수를 저장할 수 있는 배열을 선언하고 반복문을 활용하고 첫번 째 저장 장소에는 2, 두번 째 저장 장소에는 3, …,
//마지막 저장 장소에는 11이 저장되도록 하는 프로그램 작성

////함수 선언
//void setAry(int[]);
//
//int main()
//{
//    //정수형 배열을 10의 크기로 선언한다.
//    int ary[10];
//    //함수를 실행한다.
//    setAry(ary);
//
//    for (int i = 0; i < 10; i++) {
//        cout << "ary[" << i << "] : " << ary[i] << endl;
//    }
//}
//
//void setAry(int arr[]) {
//    for (int i = 0; i < 10; i++) {
//        //반복문을 사용하여 배열에 모든 인덱스에다가 1씩 증가하는 값을 넣어준다.
//        arr[i] = i + 2;
//    }
//}



//2. 20개의 정수를 저장할 수 있는 배열을 선언한 후 첫 번째, 두 번째 저장 장소에는 1을 저장하고
//3번째 부터는 앞의 두 저장 장소에 저장된 값을 더하여 저장 장소에 저장하는 프로그램 작성
////함수선언
//void setAry(int[]);
//
//int main() {
//    //20개의 정수를 저장할 배열 선언
//    int ary[20];
//    //함수를 실행한다.
//    setAry(ary);
//}
//
//void setAry(int arr[]) {
//    for (int i = 0; i < 20; i++) {
//        //Switch-case문을 이용해본 조건문
//        //i가 0일때는 1을 저장(첫번째에 1저장)
//        switch (i) {
//        case 0:
//            arr[i] = 1;
//            break;
//        //i가 1일때도 1을 저장(두번째에 1저장)
//        case 1:
//            arr[i] = 1;
//            break;
//        //그 외의 경우에는 앞에 두 저장장소에 저장된 값을 더하여 저장장소에 대입한다.
//        //피보나치 수열
//        default:
//            arr[i] = arr[i - 2] + arr[i - 1];
//            break;
//        }
//        //값이 제대로 들어갔는지 확인해보기 위해 출력을 한다.
//        cout << arr[i] << endl;
//    }
//}


////함수 선언
//void findEven(int[]);
//void findOdd(int[]);
//void findMul3(int[]);
//void findMax(int[]);
//void findMin(int[]);
//
//int main() {
//    //10개의 정수를 저장할 수 있는 배열을 선언한다.
//    int ary[10];
//    //실행할 때 마다 무작위 난수가 발생할 수 있도록 랜덤의 시드값을 설정해준다.
//    srand(std::time(NULL));
//    for (int i = 0; i < 10; i++) {
//        //최대 40까지의 난수가 발생할 수 있도록 41로 나눈 나머지를 사용한다.
//        ary[i] = rand() % 41;
//    }
//    //함수 실행
//    findEven(ary);
//    findOdd(ary);
//    findMul3(ary);
//    findMax(ary);
//    findMin(ary);
//}
//void findEven(int arr[]) {
//    cout << "--홀수 찾기--" << endl;
//    for (int i = 0; i < 10; i++) {
//        //홀수는 2로 나누었을때 나머지가 1이므로 그런 값들을 찾아서 출력한다.
//        if (arr[i] % 2 == 1) {
//            cout << "arr[" << i << "] : " << arr[i] << endl;
//        }
//    }
//}
//void findOdd(int arr[]) {
//
//    cout << "--짝수 찾기--" << endl;
//    for (int i = 0; i < 10; i++) {
//        //홀수와는 반대로 2로 나누어 나머지가 0이 되는 값들을 찾아 출력한다.
//        if (arr[i] % 2 == 0) {
//            cout << "arr[" << i << "] : " << arr[i] << endl;
//        }
//    }
//}
//
//void findMul3(int arr[]) {
//    int arySum = 0;
//    cout << "--3의 배수 찾기--" << endl;
//    for (int i = 0; i < 10; i++) {
//        //3의 배수는 3으로 나누어 떨어지는 수이므로 3으로 나누었을때 나머지가 0인 수를 찾는다.
//        //또한 그 조건에는 0이 무조건 포함되므로 0은 조건식을 이용하여 제외해준다.
//        if ((arr[i] % 3 == 0 && arr[i] !=0)) {
//            cout << "arr[" << i << "] : " << arr[i] << endl;
//            //조건에 해당된다면 arySum에 더해준다.
//            arySum += arr[i];
//        }
//    }
//    //3의 배수를 전부 더한 arySum을 출력한다.
//    cout << "합계 : " << arySum << endl;
//}
//
//void findMax(int arr[]) {
//    //최대값을 찾기 이전에 1번째 IDX에 있는 값을 aryMax에 넣어서 시작점을 만든다.
//    int aryMax = arr[0];
//    for (int i = 1; i < 10; i++) {
//        //현재최대값(aryMax)이 비교중인 배열보다 작다면 그 배열의 값을 aryMax에 대입한다.
//        //이를 모든 수에 반복해서 최대값을 찾는다.
//        if (arr[i] > aryMax) {
//            aryMax = arr[i];
//        }
//    }
//    //최대값 출력`
//    cout << "최대값 : " << aryMax << endl;
//}
//
//void findMin(int arr[]) {
//    //최소값을 찾기전 시작점을 생성한다.
//    int aryMin = arr[0];
//    for (int i = 1; i < 10; i++) {
//        //최대값 찾는것과 반대로 현재 최소값보다 비교중인 배열의 값이 작으면 그값을 현재 최소값에 대입한다.
//        if (arr[i] < aryMin) {
//            aryMin = arr[i];
//        }
//    }
//    //최소값 출력
//    cout << "최소값 : " << aryMin << endl;
//}



//4.“Hello World!” 를 저장할 수 있는 문자형 배열(strA)을 선언하고 초기화 한다. 같은 크기의 문자형 배열(strB)을 따로 선언하고 strA에 저장된 것을 strB에 복사한 후 strB를 출력하는 프로그램 작성 (strcpy 함수 사용하지 않고 작성)
//int main() {
//    //배열을 선언한 후 strA배열에만 "Hello World!"를 저장한다.
//    //두번째 배열은 strA와 같은 크기로 선언한다.
//    char strA[] = "Hello World!";
//    char strB[13];
//
//    //반복문을 통해서 strA에 있는 모든 값을 strB에다가 복사한다.
//    for (int i = 0; i < 13; i++) {
//        strB[i] = strA[i];
//        cout << strB[i];
//    }
//}



//5. 실수 두개, 연산 문자(+, -, *, /)를 입력 받아 연산의 결과를 반환하는 함수 calculate 를 정의
//float calculate(float, char, float);
//
//int main() {
//    //연산자와 실수 두개를 받아올 변수를 선언하고, float변수 두개는 초기화 한다.
//    char opr[10];
//    char opr1;
//    float numInput1 = 0.0f, numInput2 = 0.0f;
//    
//    //첫번째 실수를 입력받는다.
//    cout << "첫번째 실수를 입력해주세요 : ";
//    cin >> numInput1;
//    
//    //연산자를 입력받는다.
//    //처음에는 opr변수 하나만 사용했었는데 연산자 입력시 2개 이상을 입력하면 글자 수만큼 반복/진행 되는 문제가 있어서 하나만 받을 필요성이 있었다.
//    //그래서 맨 앞 하나만 받고 나머지는 버리기 위해 opr변수를 배열로 선언한뒤 IDX 0만 사용한다.
//    do {
//        cout << "연산자를 입력해주세요(+, -, *, /) : ";
//        cin >> opr;
//    }
//    //연산자가 설정된 연산자인지 확인한다. 제시된 연산자가 아닐경우 다시 입력을 받는다. 
//    //int이하의 변수타입을 사용하는 경우는 연산시 int로 자동변환 되므로 각 기호의 ASCII Code를 조건문으로 넣는다.
//    while (!(opr[0] == 43 || opr[0] == 45 || opr[0] == 42 || opr[0] == 47));
//    
//    //두번째 실수를 입력받는다.
//    cout << "두번째 실수를 입력해주세요 : ";
//    cin >> numInput2;
//
//    //입력받은 값들을 출력한다.
//    cout << numInput1 << " " << opr[0] << " " << numInput2 << " = ";
//    //calculate 함수를 호출하여 출력한다.
//    //실수 두개와 연산자를 인수로 넘겨준다.
//    cout << calculate(numInput1, opr[0], numInput2);
//}
//
////실수 두개와 연산자를 인수로 받는 함수를 생성한다.
//float calculate(float ipt1, char opr1, float ipt2) {
//    //Switch-case 문을 이용하여 각 기호마다의 연산을 진행시키고 반환한다.
//    //이미 main()에서 연산자를 확인했기 때문에 default를 사용하지 않는다.
//    switch (opr1)
//    {
//    case 43: //+
//        return ipt1 + ipt2;
//        break;
//    case 45: //-
//        return ipt1 - ipt2;
//        break;
//    case 42: //×
//        return ipt1 * ipt2;
//        break;
//    case 47: //÷
//        return ipt1 / ipt2;
//        break;
//    }
//}



//6.void copy(int arrA[], int arrB[], int len) 함수 구현
////함수 정의
//void copy(int[], int[], int);
//
//int main() {
//    //사용할 배열 두개를 선언한다.
//    int arrA[10];
//    int arrB[10];
//
//    //반목문을 사용하여 arrA 배열에 키보드 입력을 받아 데이터를 입력한다.
//    for (int i = 0; i < 10; i++) {
//        cout << i+1 << "번째 숫자를 입력해주세요";
//        cin >> arrA[i];
//    }
//    //함수를 실행
//    copy(arrA, arrB, 10);
//
//    //함수 실행이 제대로 됬는지 확인하기 위해 arrA와 arrB배열의 값을 확인해본다.
//    for (int i = 0; i < 10; i++) {
//        cout << "arrA[" << i << "] : " << arrA[i] << " - ArrB[" << i << "] : " << arrB[i] << endl;
//    }
//}
//void copy(int arrA[], int arrB[], int len) {
//    //반목문을 사용하여 arrB에 arrA의 값을 대입해준다.
//    for (int i = 0; i < len; i++) {
//        arrB[i] = arrA[i];
//    }
//}



//7. int arraySum(int arr[], int len) 함수 구현
////함수 선언
//int arraySum(int[], int);
//
//int main() {
//    //사용할 정수 배열을 하나 선언한다
//    int arr[10];
//
//    //반목문을 사용하여 arr 배열에 키보드 입력을 받아 정수 데이터를 입력한다.
//    for (int i = 0; i < 10; i++) {
//        cout << i + 1 << "번째 숫자를 입력해주세요";
//        cin >> arr[i];
//    }
//
//    //함수를 실행
//    cout << "배열의 합계 : " << arraySum(arr, 10);
//}
//
//int arraySum(int arr[], int len) {
//    //더한값을 저장할 정수형 변수 선언
//    int arrSum = 0;
//    
//    //반복문을 사용하여 배열의 모든 값을 arrSum에 더해준다.
//    for (int i = 0; i < len; i++) {
//        arrSum += arr[i];
//    }
//    //arrSum값을 반환해준다.
//    return arrSum;
//}


//8. int arrayMax(int arr[], int len) 함수 구현
////함수 선언
//int arrayMax(int[], int);
//int main() {
//    //사용할 정수 배열을 하나 선언한다
//    int arr[10];
//
//    //반목문을 사용하여 arr 배열에 키보드 입력을 받아 정수 데이터를 입력한다.
//    for (int i = 0; i < 10; i++) {
//        cout << i + 1 << "번째 숫자를 입력해주세요";
//        cin >> arr[i];
//    }
//    //함수를 실행
//    cout << "배열중 최대값 : " << arrayMax(arr, 10);
//}
//
//int arrayMax(int arr[], int len) {
//    //최대값을 저장할 정수형 변수 하나를 선언한 뒤 배열의 첫번째 값을 대입한다.
//    int arrMax = arr[0];
//
//    //반복문을 사용하여 모든 배열의 값을 arrMax와 비교하여
//    //배열의 값이 arrMax보다 크다면 arrMax를 해당 배열의 값으로 대입하는 방식으로 최대값을 구한다.
//    for (int i = 1; i < len; i++) {
//        if (arr[i] > arrMax) {
//            arrMax = arr[i];
//        }
//    }
//    //arrMax를 반환해준다.
//    return arrMax;
//}


//9. int arrayMin(int arr[], int len) 함수 구현
////함수 선언
//int arrayMin(int[], int);
//
//int main() {
//    //사용할 정수 배열을 하나 선언한다
//    int arr[10];
//
//    //반목문을 사용하여 arr 배열에 키보드 입력을 받아 정수 데이터를 입력한다.
//    for (int i = 0; i < 10; i++) {
//        cout << i + 1 << "번째 숫자를 입력해주세요";
//        cin >> arr[i];
//    }
//    //함수를 실행
//    cout << "배열중 최소값 : " << arrayMin(arr, 10);
//}
//
//int arrayMin(int arr[], int len) {
//    //최소값을 저장할 정수형 변수 하나를 선언한 뒤 배열의 첫번째 값을 대입한다.
//    int arrMin = arr[0];
//
//    //반복문을 사용하여 모든 배열의 값을 arrMin와 비교하여
//    //배열의 값이 arrMin보다 작다면 arrMin를 해당 배열의 값으로 대입하는 방식으로 최대값을 구한다.
//    for (int i = 1; i < len; i++) {
//        if (arr[i] < arrMin) {
//            arrMin = arr[i];
//        }
//    }
//    //arrMax를 반환해준다.
//    return arrMin;
//}


//10. bool search(int arr[], int len, int x) 함수 구현
////함수 선언
//bool search(int[], int, int);
//
//int main() {
//    //사용할 정수 배열을 하나 선언한다
//    int arr[10];
//    int searchNum = 0;
//
//    //반목문을 사용하여 arr 배열에 키보드 입력을 받아 정수 데이터를 입력한다.
//    for (int i = 0; i < 10; i++) {
//        cout << i + 1 << "번째 숫자를 입력해주세요";
//        cin >> arr[i];
//    }
//
//    //찾고싶은 수를 입력받는다.
//    cout << "찾고싶은 수를 입력해주세요 : ";
//    cin >> searchNum;
//
//    //함수를 실행
//    cout << searchNum << " 검색결과 : " << search(arr, 10, searchNum);
//}
//
//bool search(int arr[], int len, int x) {
//    for (int i = 0; i < len; i++) {
//        //arr[i]가 x일 경우에는 true를 반환해준다.
//        if (arr[i] == x) {
//            //반환이 되었기 때문에 이후는 더이상 작동하지 않는다.
//            return true;
//        }
//    }
//    //위에서 true가 반환이 안되었다면 x를 찾지 못한것이기 때문에 false를 반환해준다.
//    return false;
//}

//11.int arrayMid(int arr[], int len) 함수 구현

////함수 선언
//int arrayMid(int[], int);
//
//int main() {
//    //입력받은 값을 저장할 배열을 선언한다.
//    int ary[9];
//    //선언한 배열에 키보드 입력을 통해 값을 받는다.
//    for (int i = 0; i < 9; i++) {
//        cout << i + 1 << "번 째 수를 입력하세요 : ";
//        cin >> ary[i];
//        cout << "ary[" << i << "] = " << ary[i] << endl;
//    }
//    //함수 실행
//    cout << arrayMid(ary, 9);
//}
//
//int arrayMid(int arr[], int len) {
//    //배열의 크기가 짝수일때와 홀수일때의 계산방법이 다르므로 조건문으로 분기를 나누어준다.
//    if (len % 2 == 0) {
//        //배열이 짝수개일때
//        //변수선언. 합계와 평균치에 가장 가까운 수의 IDX는 정수로 선언
//        int arrSum = 0, aveNum = 0;
//        //수의 평균, 계산에 사용되는 평균과 숫자의 차는 실수로 선언한다.
//        float arrAve = 0.0f, numDif = 0.0f, numDif2 = 0.0f;
//        //평균을 구해야 하기때문에 배열의 모든 값을 더한다.
//        for (int i = 0; i < len; i++) {
//            arrSum += arr[i];
//        }
//        //더한 값을 배열의 갯수로 나누어서 평균을 구한다.
//        //나누면 소수점이 생길 수 있으므로 float로 형변환 해준다.
//        arrAve = float(arrSum) / len;
//        //numDif(평균과 값의 차)에 평균 - 배열의 첫번째 값의 차를 대입하여 시작지점을 잡는다.
//        numDif = arrAve - arr[0];
//        //필요한 값은 두 수의 차가 얼마나 된것인지만 필요하기 때문에 절대값처리를 해준다.
//        if (numDif < 0) numDif *= -1;
//        //반복문을 이용하여 이 과정을 모든 배열에 실행한다.
//        for (int i = 1; i < len; i++) {
//            numDif2 = arrAve - arr[i];
//            if (numDif2 < 0) numDif2 *= -1;
//            //두번쨰로 구한 차가 그전에 구한 차보다 작을경우는 numDif를 현재 값으로 교체해준뒤
//            //aveNum에 현재 실행중인 인덱스를 저장한다.
//            if (numDif > numDif2) {
//                numDif = numDif2;
//                aveNum = i;
//            }
//        }
//        //이 과정이 끊나면 aveNum에 있는 인덱스가 평균에 가장 가까운(평균-값이 가장 작은)값이므로
//        //그 수를 반환해준다.
//        return arr[aveNum];
//    }
//    else {
//        //배열의 홀수 개 일때
//        //정수형 변수 2개를 선언 해주고 초기화한다.
//        int minNum = 0, temp = 0;
//        //홀수개일때는 평균에 가까운값이 아닌 순서적으로 가운데에 있는 값을 찾아야 하기떄문에
//        //선행조건으로 배열을 오름차순으로 정렬해주어야 한다.
//        for (int i = 0; i < len - 1; i++) {
//            //우선 제일 첫번째를 i로 둔다.
//            minNum = i;
//            //제일 첫번째를 제외한 다음 배열에서 첫번째(minNum)보다 작은수를 찾아서
//            //그것을 minNum으로 저장한다.
//            for (int j = i + 1; j < len; j++) {
//                if (arr[j] < arr[minNum]) minNum = j;
//            }
//            //가장 작은 값이 있는 IDX를 알았으니 그 IDX에 있는 값과 현재 코드를 실행중인 순서(i)IDX를 가진 값과 바꾼다.
//            //만약 지금 확인중인(i)값이 가장 작다면 i=minNum이므로 바뀌지 않고 넘어간다.
//            temp = arr[i];
//            arr[i] = arr[minNum];
//            arr[minNum] = temp;
//        }
//
//        //정렬이 제대로 됬는지 확인하며 중간값을 확인한다.
//        for (int i = 0; i < len; i++) {
//            if (i == (len / 2)) {
//                cout << "> arr[" << i << "] : " << arr[i] << endl;
//            }
//            else {
//                cout << "  arr[" << i << "] : " << arr[i] << endl;
//            }
//        }
//        //배열의 가운데IDX에 있는 값을 반환한다.
//        return arr[len / 2];
//    }
//}