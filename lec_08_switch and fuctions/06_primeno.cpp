#include<iostream>
using namespace std;

//1-> prime no
// 0-> Not  a prime no 
bool isPrime(int n){

for(int i=2; i<2; i++)
{
    // divide hogya h, not prime no.
    if(n%i==0){
        return 0;
    }
}
return 1;
}

int main()
{

int n;
cin>>n;
if(isPrime(n)){
    cout<<"is a prime number"<<endl;

}
else{cout<<"not a prime number "<<endl;
    }
    return 0;
}
