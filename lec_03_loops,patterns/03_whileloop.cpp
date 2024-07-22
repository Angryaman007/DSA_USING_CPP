#include<iostream>
using namespace std;

int main()
{

//----print 1 to n numbers----//
    /* int n; 
     cin>>n;
    
     int i=1;
    
     while (i<=n)
     {
         cout<<i<<" ";
         i=i+1;
     }
   
//----print sum of  1 to n numbers----//

int n;
cin>>n;
int i=1;
int sum=0;

while (i<=n)
{
     i=i+1;
    sum=sum+i;
}  
 
cout<<"value of sum is "<<sum<<endl;

 */
//----------HOMEWORK-------//
//------find the sum of n even numbers------//



//-----print  given number is prime numbers or not-----//

int n;
cin>>n;

int i=2;

while (i<n)
{
    //divide hogya, not prime

    if(n%i==0)
    {
        cout<<"Not prime for "<<i<<endl;
    }else{
        cout<<"prime for "<<i<<endl;
    }
    i=i+1;
}



}