#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    private:
    int age;

public:
    int getAge()
    {
        return this->age;
    }
    int setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : protected Human
{
public:
    string color;

    void sleep()
    {
        cout << " Male Sleeping " << endl;
    }
    int getHeight()
    {
        return this->height;
    }
};

int main()
{
Male m1;
cout<<m1.getHeight()<<endl;

    // Male object1;
    // cout << object1.age << endl;
    // cout << object1.height << endl;
    // cout << object1.weight << endl;
    // object1.setWeight(76);
    // cout << object1.weight << endl;
    // object1.sleep();

    return 0;
}
       