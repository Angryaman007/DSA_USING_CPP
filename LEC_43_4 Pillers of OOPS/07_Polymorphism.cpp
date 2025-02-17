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


int main()
{
    A obj;
    obj.sayHello();
    return 0;
}