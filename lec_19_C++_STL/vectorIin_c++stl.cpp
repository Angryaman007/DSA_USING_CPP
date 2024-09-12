#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "hellow world duniya sana cow \n";

    vector<int> v;

    vector<int>a(5,1);

    vector<int>last(a);
    cout << "print last" << endl;
    for (int i : last)
    {
        cout << i << " "<<endl;
    }

    cout << "capacity:: " << v.capacity() << endl;

    // push_back is used to insert elemnts in vector

    v.push_back(1);
    cout << "capacity:: " << v.capacity() << endl;
    v.push_back(2);
    cout << "capacity:: " << v.capacity() << endl;
    v.push_back(3);
    cout << "capacity:: " << v.capacity() << endl;

    cout << "size:: " << v.size() << endl;

    cout << "element at 2nd index :: " << v.at(2) << endl;

    // pop_back is used to take out the last inserted element
    cout << "before pop" << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();

    cout << "after pop" << endl;
    for (int i : v)
    {
        cout << i << " "<<endl;
    }

    //.clear is used to empty the vector or to make the size of vector =0 

    cout<<"befor clear size "<<v.size()<<endl;

    v.clear();

    cout<<"after clear size "<<v.size()<<endl;

}
