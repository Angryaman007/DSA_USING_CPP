#include<iostream>
using namespace std;

int main()
{

    
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"printig count from 1 to n"<<endl;
    /*
    for(int i=1; i<=n; i++)
    {
        cout<<i<<endl;
   }


   */
//----OR----//

int i=1;
for(; ;){
    if(i<=n)
    {
        cout<<i<<endl;
    }else{
        break;
    }
    i++;
}

}