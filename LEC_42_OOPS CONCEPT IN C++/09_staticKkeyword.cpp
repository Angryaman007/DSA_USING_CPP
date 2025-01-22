#include <iostream>
#include <cstring> // For strcpy
using namespace std;

class Hero
{
    // Properties
private:
    int health;

public:
    char *name;
    char level;
    static int timeToComplete;
    // Default constructor
    Hero()
    {
        cout << "Simple constructor called" << endl;
        name = new char[100]; // Allocate memory for name
    }
    //static fuction can only acces static member 
    static int random()
    {
return timeToComplete;
    }
//destructor
    ~Hero()
    {
        cout << "destructor bhai called " << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{
    //for static fuction onect creation is not needed and there is no this keyword 
    cout << Hero::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl;
    
    Hero b;
    b.timeToComplete=10;
    cout<<a.timeToComplete<<endl;
    cout<<b.timeToComplete<<endl;

    return 0;
}