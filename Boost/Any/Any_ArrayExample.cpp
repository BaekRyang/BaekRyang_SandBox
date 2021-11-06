#include <boost/any.hpp>
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using boost::any;
using boost::any_cast;

void ArrayExample()
{
    any ExampleArray[10]; //any 타입의 배열을 선언한다.

    ExampleArray[0] = 23;
    ExampleArray[1] = "How old are you?"; //순서대로 int, String, Float형 데이터를 집어넣었다.
    ExampleArray[2] = 178.7;

    int* i1 = any_cast<int>(&ExampleArray[0]);
    int* i2 = any_cast<int>(&ExampleArray[1]);
    int* i3 = any_cast<int>(&ExampleArray[2]);

    cout << "  " << i1 << endl << "  " << i2 << endl << "  " << i3 << endl;

    try {
        string s1 = any_cast<string>(ExampleArray[1]);
        cout << s1 << endl;
    }
    catch (boost::bad_any_cast& except) {
        cout << except.what() << endl;

    }
}

int main() {
    ArrayExample();

    return 0;
}
