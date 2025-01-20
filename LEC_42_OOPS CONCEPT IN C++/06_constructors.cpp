//types of constructors 
#include <iostream>
using namespace std;
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
    //this is constructor 
    Hero()
    {
        cout<< "Constructor Called "<<endl;
    }
// paramerterised csntructor 
Hero(int health){
    cout<<"this -> "<<this <<endl;
   this-> health -health;
}
Hero(int health, char level ){
    this->level=level;
    this->health=health;
}
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
    //statically 
//object created 
cout<<"hi"
<<endl;
Hero Aman(10);
cout<<"helllo "<<endl;
cout<<"adrress of Aman "<< &Aman<<endl;
Aman.getHealth();
Aman.print();
//dynamically 
Hero *h=new Hero( );

h->print();
Hero temp(22,'b');
temp print();
    return 0;



}
