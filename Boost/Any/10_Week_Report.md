# Boost::Any Algorithm 분석

## 사용방법

Vector를 사용하는 프로그램에서의 Any 사용
```C++
#include "stdafx.h"
#include "AnyExample.h"
 
#include <boost/any.hpp>
#include <vector>
#include <iostream>
#include <string>
 
AnyExample::AnyExample()
{
}
 
 
AnyExample::~AnyExample()
{
}
 
void AnyExample::doExample()
{
    std::vector<boost::any> some_values;
    some_values.push_back(10);
    const char* c_str = "Hello there!";
    some_values.push_back(c_str);
    some_values.push_back(std::string("Wow!"));
    //vector 컨테이너 확인
    if (some_values.empty())
    {
        std::cout << "boost any vector is empty" << std::endl;
        return;
    }
    else
    {
        std::cout << "boost any vector is vaild" << std::endl;
    }
 
    std::string& s = boost::any_cast<std::string&>(some_values.back());
    s += " That is great!\n";
    std::cout << s << std::endl;
 
    // 명시적으로 정확한 캐스팅이 필요하다
    boost::any var2 = some_values.at(1);
    const char* s2 = boost::any_cast<const char*>(var2);
    std::cout << s2 << std::endl;
 
    boost::any var3 = some_values.at(0);
    int s3 = boost::any_cast<int>(var3);
    std::cout << s3 << std::endl;
 
    boost::any variable(std::string("Hello world!"));
    // 변수의 실제 값이 std::string이 아니라면
    // 아래 메소드가 boost::bad_any_cast 예외를 던질 수도 있다    
    std::string s11 = boost::any_cast<std::string>(variable);
    std::cout << s11 << std::endl;
    // 변수의 실제 값이 std::string이 아니라면    
    // NULL 포인터 반환
    std::string* s12 = boost::any_cast<std::string>(&variable);
    std::cout << (*s12) << std::endl;
}
```
