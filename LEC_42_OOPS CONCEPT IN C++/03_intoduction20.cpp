#include<iostream>
using namespace std;

//properties

// there are 3 types of classes mainly public private and protected and the main diff btw public is that it can be acces from both inside and outside of class where private can only be access from inside the class...


class Hero

{


public:

int health;
char level;

private:

char type;
void print()
{
    cout<<type<<endl;

}


};



int main()
{

//creation of object

Hero Aman;
Aman.health=100;
Aman.level='A';

cout<<"health is :"<<Aman.health<<endl;
cout<<"level is : "<<Aman.level<<endl;
    return 0;
}
