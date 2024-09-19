#include<iostream>
using namespace std;

  // to print row wise sum 
void printSum(int arr[][3],int row,int col)
{
  
    cout<<"printing the sum  row wise :"<<endl;
    for(int row=0; row<3; row++)
    {
        int sum =0;

        for(int col=0; col<3; col++)
        {
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    } 

// to print col  wise sum 
void printColsum(int arr[][3],int row,int col)
{


     cout<<"printing the sum col wise :"<<endl;
    for(int col=0; col<3; col++)
    {
        int sum =0;

        for(int row=0; row<3; row++)
        {
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
} 

int main()
{
    int arr[3][3];

    cout<<"Enter the elemnts "<<endl;

    for(int row=0; row<3; row++)
    {
        for(int col=0; col<3; col++)
        {
            cin>>arr[row][col];
        }
    }
    cout<<"printing the sum : "<<endl;
     for(int row=0; row<3; row++)
    {
        for(int col=0; col<4; col++)
        {
            cout<<arr[row][col];
        }
        cout<<endl;
    }
    printColsum(arr,3,3);
return 0;
}
