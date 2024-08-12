#include<iostream>
using namespace std;


void printArray(int arr[],int size)
{
    cout<<"printing the array "<<endl;

    //print the array 
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"printing done"<<endl;

}

int main()
{
//intilising the array 
int third[15]={2,7};
int n=15;
printArray(third, 15);

//intilising all the location with zero 
int fourth[10]={0};
 n =10;
printArray(fourth, 10);


//intilising all the loction with zero doest work with below line 
int fifth[10]={1};
 n =10;

printArray(fifth,10);
return 0;

}