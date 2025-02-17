#include<iostream>
using namespace std;


class A{
public:
void sayHello()
{
    cout<<"helllo love babbar "<<endl;
}
//
int sayHello(string name,int n){
    cout<<"Hello love babbar "<<endl;
    return n;

}
void sayHello(string name)
{
    cout<<"Hello  "<<endl;
}
};

class B {
    public:
    int a;
    int b;

    public:
    int add()
    {
        return a+b;
    }
    void operator+ (B &obj){
        int value1=this->a;
        int value2=obj.a;
        cout<<"output "<<value2-value1<<endl;
    }
};


int main()
{
    A obj;
    obj.sayHello();
    B obj1, obj2;
    obj1.a=4;
    obj2.a=7;

    obj1+obj2;
    return 0;
}