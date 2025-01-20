
// gatter and setter
// are special types of fuction

#include <iostream>
using namespace std;

// properties

// there are 3 types of classes mainly public private and protected and the main diff btw public is that it can be acces from both inside and outside of class where private can only be access from inside the class...

class Hero

{

    // properties
private:
    char type;

    void print()
    {
        cout << type << endl;
    }

public:
    int health;
    char level;

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    char getType()
    {
        return type;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    void setType(char ty)
    {
        type = ty;
    }
};

int main()
{
    // static allocation
    Hero a;
    cout << "level is : "
         << a.level << endl;
    cout << " health is : "
         << a.health << endl;
    cout << " Type of : "
         << a.getType() << endl;
cout<<"\n"<<endl;
    // dyanimacally allocation
    Hero *b = new Hero;

    b->setHealth(12);
    b->setType('X');
    b->setLevel('C');
cout<<"\n"<<endl;

 cout << "level is : "
         << (*b).level << endl;
    cout << " health is : "
         << (*b).health << endl;
    cout << " Type of : "  
         << (*b).getType() << endl;
cout<<"\n"<<endl;

/// or we can write this as 
 cout << "lever is : "
         << b->level << endl;
    cout << " health is : "
         << b->health << endl;
    cout << " Type of : "
         << b->getType() << endl;

    return 0;
}
