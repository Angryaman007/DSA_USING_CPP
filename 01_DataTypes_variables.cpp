#include<iostream>
using namespace std;

int main()
{
    int a=123;
    cout<<a<<endl;
    
    char b='v';

    cout<<b<<endl;
    
    bool bl=true;
    cout<<bl<<endl;

    float f=1.2;
    cout<<f<<endl;

    double d=1.23;
    cout<<d<<endl;


// to find the size of any element 
    
    int sizeA = sizeof(a);
    cout<<"Size of a is :"<<sizeA<<endl;

    int sizeD = sizeof(d);
    cout<<"Size of d is :"<<sizeD<<endl;

 
/*

----- how data is stored ------




*/

int g='g';
 cout<<f<<endl;
 
 char ch=98;
 cout<<ch<<endl;

 char ch1=123456;
 cout<<ch1<<endl;


// how to store negative numbers 
// do  not give (-) numbers for ex -112 insted give 112 else the result print output value will come very large =(4294967184)
unsigned int x=112;
cout<<x<<endl;

}


