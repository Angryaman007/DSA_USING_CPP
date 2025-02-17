#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void speak()
    {
      cout<<"Speaking "<<endl;  
    }
};

class Dog: public Animal{

};
 // germanshephered is inheriing dog class 
class GermanShephered: public Dog{ 


};

int main()
{
    Dog d;
    d.speak();
    cout<<d.age<<endl;
    GermanShephered g;
    g.speak();

    return 0;

}