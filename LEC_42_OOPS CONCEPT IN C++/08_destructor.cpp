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

    // Default constructor
    Hero()
    {
        cout << "Simple constructor called" << endl;
        name = new char[100]; // Allocate memory for name
    }
    //Destructor 
    ~Hero()
    {
        cout<<"desturcor bhai is called "
        <<endl;
    }
};

int main()
{
//static
    Hero a;
    // here destructor is called for hero a. it has no input parameter and no input 

    //dynaimicalyy

    Hero *b=new Hero();
    // manually destructor called 
    delete b;
   return 0;
}
