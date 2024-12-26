#include<iostream>
using namespace std;

//     int arr[6]={1, 21,12};
//     cout<<(arr+1)<<endl;


    // int arr[6]={1, 21,31};
    // int *p=arr;
    // cout<<p[2]<<endl;
// int arr[6]={11,12,13,14,15};
// cout<<*(arr)<<" "<<*(arr+3);

// char ch='a';
// char*ptr=&ch;
// ch++;
// cout<<*ptr<<endl;

// char arr[]="abcde";
// char *p=&arr[0];
// cout<<p<<endl;

// char str[]="babbar";
// char *p=str;
// cout<<str[0]<<" "<<p[0]<<endl;

void update(int *p){
    *p=(*p)*2;
}

int main()

{
    int i=10;
    update(&i);
    cout<<i<<endl;

    return 0; 
}