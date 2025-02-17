#include<iostream>
using namespace std;
//single level inheritacne 
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
//multi level inheritacne 
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