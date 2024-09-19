
#include<iostream>
using namespace std;


int main()
{
    // create a 2D array 

    int arr[3][4];

//taking the input 
/*

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>arr[i][j];

        }
    }
    */
   // taking input -> col wise input

   for(int i=0; i<4; i++)
   {
    for(int j=0; j<3; j++)
    {
        cin>>arr[j][i];
    }
   }
    //print kardo 
 for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<arr[i][j]<<" ";
            

        }
        cout<<endl;
    }

    return 0;
     
}