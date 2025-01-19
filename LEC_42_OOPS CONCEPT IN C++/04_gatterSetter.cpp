
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

    // creation of object

    Hero Aman;

    // getter
    cout << "Aman type  is :" << Aman.getType() << endl;
    Aman.health = 100;
    Aman.setType('X');
    Aman.level = 'A';

    cout << "health is :" << Aman.health << endl;
    cout << "level is : " << Aman.level << endl;
    // we can use getter and setter to acces the private class outside the defined calass.
    cout << "type is : " << Aman.getType() << endl;

    return 0;
}
