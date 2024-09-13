#include<iostream>
#include<queue>
using namespace std; 

int main()
{
    queue<string>q;

    q.push("aman");
    q.push("sana");
    q.push("anchal ");


    cout<<"first element "<<q.front()<<endl;
    cout<<"size before  pop "<<q.size()<<endl; 

    q.pop();
    cout<<"first elemnt "<<q.front()<<endl;

    cout<<"size after pop "<<q.size()<<endl; 
}