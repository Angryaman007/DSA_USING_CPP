#include<iostream>
using namespace std;


int main()
{
    int i=5;
    int* p=&i;

// dounle pointer nomination here 
    int **p2=&p;
cout<<endl<<"Sab sahi chal rha hai dost "<<endl<<endl;

cout<<"printing p "<<p<<endl;
cout<<"address of p "<<&p<<endl;

cout<<*p2<<endl;

// agar i print karna hai to 3 tarike hai 

cout<<i<<endl;
cout<<*p<<endl;
cout<<**p2<<endl;
// agar p ko print krna hai to 3 tarike hai uske bhi 

cout<<&i<<endl;
cout<<p<<endl;
cout<<*p2<<endl;

return 0;

// agar p2 ko print karna hai t o 3 atarike ahi uske bhi 

cout<<&p<<endl;
cout<<p2<<endl;


}