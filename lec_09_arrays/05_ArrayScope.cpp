#include<iostream>
using namespace std;



void update(int arr[], int n){

cout<<"Inside the fuction"<<endl;
//updating arrays first element 
arr[0]=120;


//prinitng the array 
for(int i=0; i<3; i++){
    cout<<arr[i]<<" ";
}

cout<<endl;
cout<<"Going back to main fuction "<<endl;
}


int main()
{
    int arr[3]={1,2,3};
    update(arr,3);

    //printing the array 
    cout<<endl<<"printing in main fuctions"<<endl;
for(int i=0; i<3; i++){
    cout<<arr[i]<<" ";
}
return 0;

}