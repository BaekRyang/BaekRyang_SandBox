# Boost::Any Algorithm 분석

## Array를 통한 Any의 기본적인 사용

```C++
any ExampleArray[10];
```
boost:any를 DataType으로 하여 Container, 또는 배열을 선언할 수 있다.

```C++
ExampleArray[0] = 23;
ExampleArray[1] = "How old are you?";
ExampleArray[2] = 178.7;
```
순서대로 `int`,`string`,`float`형 데이터를 배열에 대입하였다.

```C++
int i = any_cast<int>(ExampleArray[0]);
```
만약 이렇게 저장된 데이터를 특정 자료형이 필요한 곳으로 가져오려면 casting이 필요하다.
이때 any_cast function를 사용하여 Casting해주면 된다.
이때 any_cast 뒤에 <>로 Casting 할 자료형을 명시해줘야 한다.

```C++
//ExampleArray[1] 에는 String 데이터가 들어있다.
any_cast<int>(ExampleArray[1]);
```
만약 변환할 수 없는 자료형으로 Casting을 시도할 경우 `bad_any_cast` Exception을 Throw 한다.
<img src="images/bad_any_cast_exception.png">

boost:any는 값을 2가지 방법으로 가져올 수 있는데, 값을 반환하는 방식 그리고 포인터를 반환하는 방식이다.
값을 반환하는 방식은 위와 같고 변환하는 타입이 맞지 않으면 bad_any_cast exception을 던진다.
포인터를 반환하는 방식은 아래와 같으며 타입이 맞지 않더라도 Exception을 던지지않고, NULL 포인터를 반환한다.

```C++
int* i1 = any_cast<int>(&ExampleArray[0]);
int* i2 = any_cast<int>(&ExampleArray[1]);
int* i3 = any_cast<int>(&ExampleArray[2]);
```
위와 같이 코드를 작성한뒤 실행을 시킨 결과는 다음과 같다.
<img src="images/pointer_cast">