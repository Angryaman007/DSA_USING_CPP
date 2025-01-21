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

    // Parameterized constructor
    Hero(int health)
    {
        this->health = health;
        name = new char[100]; // Allocate memory for name
    }

    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
        name = new char[100]; // Allocate memory for name
    }
    // copy constructor
    Hero(Hero& temp)
    {
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;

        cout<<"copy constuctor called "<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    // Custom copy constructor (Deep Copy)
    Hero(const Hero &temp)
    {
        cout << "Copy constructor called (Deep Copy)" << endl;
        this->health = temp.health;
        this->level = temp.level;

        // Deep copy for the name
        this->name = new char[strlen(temp.name) + 1];
        strcpy(this->name, temp.name);
    }

    // Destructor
    Hero()
    {
        cout << "Destructor called for " << name << endl;
        delete[] name; // Free allocated memory for name
    }

    void print()
    {
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << " ]" << endl;
    }

    // Getters and Setters
    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }

    void setName(const char *name)
    {
        strcpy(this->name, name); // Copy the provided name into the object's name
    }
};

int main()
{
    // Using parameterized constructor
    Hero suresh(60, 'C');
    suresh.setName("Suresh");
    suresh.print();

    // Copy constructor
    Hero aman(suresh);
    aman.print();

    // Object creation using default constructor
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    hero1.setName("Amandeep");

    hero1.print();
     
    Hero hero2(hero1);
    hero2.print();
    
    hero1.name[0]='G';
    hero1.print();
    hero2.print();

    return 0;
}
