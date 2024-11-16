#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    int a = num;
    cout << " a before " << num << endl;
    a++;
    cout << " a after " << num << endl;

    // cout << num << endl;

    int *p = &num;
    cout << "before " << num << endl;

    (*p)++;
    cout << "after " << num << endl;

//copying a pointer 

    int *q=p;
    cout<<p<<" _ "<<q<<endl;
    cout<<*p<<" _ "<<*q<<endl;

  
//importent  concept 
int i=3;
int *t=&i;

//cout<<(*t)++<<endl;
*t=*t +1;
cout<<*t<<endl;
cout<<"before"<<t<<endl;
t=t+1;
cout<<"after t "<<t<<endl; 
  return 0;
}