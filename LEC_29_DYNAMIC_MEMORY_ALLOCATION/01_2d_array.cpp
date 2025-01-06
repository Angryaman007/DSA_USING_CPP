//how to do dyanmic memory allocation in 2d array 

#include<iostream>
using namespace std;

int main()
{

int n;
cin>>n;
int** arr=new int*[n];
for(int i=0; i<n; i++)
{
    arr[i]=new int[n];

}

//creation done 



//taking input 

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        cin>>arr[i][j];
    }
}

//taking input
cout<<endl;
for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    
}
    return 0;
}