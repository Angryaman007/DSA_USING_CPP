#include <iostream>
using namespace std;

int main()
{
    int num = 51;
    cout << num << endl;
    // addresss of operator -&

    cout << "address of num is " << &num << endl;

    int *ptr = &num;

    cout << "Address is : " << ptr << endl;
    cout << "Vlaue  is : " << *ptr << endl;

    double d = 4.33;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;
    cout << "Address is : " << *p2 << endl;

    cout<<"size of integer is  "<<sizeof(num)<<endl;
    cout<<"size of pointer  is  "<<sizeof(ptr)<<endl;
    cout<<"size of poimter  is  "<<sizeof(p2)<<endl;



    return 0;
}