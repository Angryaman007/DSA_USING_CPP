#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string>s;

    s.push("aman");
    s.push("sana");
    s.push("annu");

    cout<<"Top Element "<<s.top()<<endl;
    s.pop();


    cout<<"Top Element "<<s.top()<<endl;

    cout<<"size of the stack "<<s.size()<<endl;

    cout<<"Empty or Not "<<s.empty()<<endl;

}