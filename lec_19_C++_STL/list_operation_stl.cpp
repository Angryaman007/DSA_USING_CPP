#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> l;
    // to copy list in other list 
    // n(5,100) means print 100 five times 
list<int>n(5,100);
cout<<"prinitng the n "<<endl;
for(int i:n){
    cout<<i<<" "<<endl;
}


    l.push_back(1);
    l.push_front(2);

    for(int i:l){
        cout<<i<<" ";

    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after ersse"<<endl;
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"size of list "<<l.size()<<endl;
}