#include<iostream>
using namespace std;

int main()
{
    /*
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    int sum=0;
    
    for(int i=0; i<=n; i++)
    {
        //sum=sum+1;
        //or
        sum+=i;
    }
    cout<<sum<<endl;



//----Fibonacci Series----//


// eg---: 0,1,1,2,3,5,8,13,21,.........
// sum of last two number makes the new number for example n=(n-1)+(n-2) where n is the new number.


int n=10;
int a=0;
int b=1;

cout<<a<<" "<<b<<" ";

for(int i=1; i<=n; i++)
{

int nextNumber=a+b;
cout<<nextNumber<<" ";

a=b;
b=nextNumber;

}
*/

int n;
cout<<"enter the value of n"<<endl;
cin>>n;
bool isPrime=1;

for(int i=2; i<n; i++)
{
    if(n%i==0){
        // cout<<"Not a prime Number"<<endl;
        isPrime=0;
        break;
    }
}
if(isPrime==0){
    cout<<"not a prime number"<<endl;
}
else{
    cout<<"is  a prime number"<<endl;
}

}