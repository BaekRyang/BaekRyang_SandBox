#include <iostream>

using namespace std;

 void fm(int** b) {

    int a = 50;
    *b = &a;

}

int main() {

    int * a = NULL;
    
    fm(&a);
    cout << *a << endl;
    cout << *a << endl;

    return 0;
}

//#include <iostream>
//
//using namespace std;
//
//void fm(int*);
//
//int main() {
//
//    int a = 50;
//
//    fm(&a);
//
//    cout << "a " << a << endl;
//
//    return 0;
//}
//
//void fm(int* a) {
//
//    *a = 20;
//
//}