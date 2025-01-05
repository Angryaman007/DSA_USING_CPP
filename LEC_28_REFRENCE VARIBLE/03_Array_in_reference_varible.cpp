#include<iostream>
using namespace std;

//large size array 
//using heap memory
//we have to use 'new' keyword to create in heap memory 
//we can not give names in heap memory so we use pointer to acces the address of the blok for ex.. new char; then we use char* ch=new char; to acces the new char; in the heap memory and this is known as dynamic memory allocation and where we use stack then it is known as static memory alloation .






int main()
{
char ch='q';
cout<<sizeof(ch)<<endl;

char* c=&ch;
cout<<sizeof(c)<<endl;

// how to create array in heap memory 

int* arr=new int [5];
//it has 24 bit memory 

    return 0;
}