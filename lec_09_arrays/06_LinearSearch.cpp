#include<iostream>

using namespace std;


bool search(int arr[], int size,int key ){


}
int main ()
{
    int arr[10]={5,6,7,-2,10,22,0,5,30,1};


    //whether 1 is present in it or not?

    cout<<"Enter the element to search for "<<endl;

    int key;
    cin>>key;

    bool found =search(arr,10,key);

    if(found){
        cout<<"Key is present "<<endl;

    }
    else{
        cout<<"key is absent "<<endl;
    }


    return 0;
    

}