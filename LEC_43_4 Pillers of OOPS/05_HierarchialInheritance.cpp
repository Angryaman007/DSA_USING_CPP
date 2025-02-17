#include<iostream>
using namespace std;
//hierarchial inheritance 
class A{
    public: 
    void fuct1()
    {
        cout<<"inside function 1"<<endl;
    }
};

class B: public A{
    public:
    void fuc2()    
        {
            cout<<"inside function 2"<<endl;
        }
};

class C: public A{
    public:
    void fuct3()
    {
        cout<<"inside function 3"<<endl;
    }
};

int main()
{
 A object1;
 object1.fuct1();

 B object2;
 object2.fuct1();
 object2.fuc2();

 C object3;
 object3.fuct1();
 object3.fuct3 ();
    return 0;
}