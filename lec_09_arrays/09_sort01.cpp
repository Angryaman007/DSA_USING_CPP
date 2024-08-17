#include<iostream>
using namespace std;


void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}

void sortOne(int arr[], int n){
    int left=0 ,right=n-1;

int step=0;


while (left<right)
{
    cout<<"step"<<step<<endl;
    printArray(arr,n);
    cout<<endl;
    while (arr[left]==0)
    {
        left++;
    }
    while (arr[right]==1)
    {
        right--;
    }
    //agar yaha pouch gye ho ,iska matlab 
    //arr[i]==1; anf arr[j]==o'

    swap(arr[left], arr[right]);

    left++;
    right--;
    
}

}

int main()
{
    int arr[8]={1,1,0,0,0,1,0};

    sortOne(arr,0);
    printArray(arr,0);

    
    return 0;
}