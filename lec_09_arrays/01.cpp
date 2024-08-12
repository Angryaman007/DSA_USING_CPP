#include<iostream>
using namespace std;

int main()
{

// declare
int number[15];

//accesing an array

cout<<"value at 15 index "<<number[14]<<endl;


//intialising an array 

int second[3]={5,7,11};

//accesing th array 

cout<<"value at 2 index "<<second[2]<<endl;

//intilising the array 

int third[15]={11,22};

int n =15;

cout<<"printing the array "<<endl;

//print the array 

for(int i=0; i<n; i++){
    cout<<third[i]<<" ";
}

//intialising all locations with zero 0 
int fourth[10]={0};

n=10;
cout<<endl<<"printing the array "<<endl;
//print the array 
for(int i=0; i<n; i++){
    cout<<fourth[i]<<" ";

}
//intilaising  all location with zero is not posibble from belwo the line 
int fifth[10]={1};

n=10;
cout<<endl<<"printing the array "<<endl;
//print the array 
for(int i=0; i<n; i++){
    cout<<fifth[i]<<" ";

}

cout<<endl<<"Code by Amandeep singh "<<endl;
return 0;

}