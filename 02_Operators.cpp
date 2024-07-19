#include<iostream>
using namespace std;

int main()
{
    //divide(/) operator
    int a=2/5;
    cout <<a<< endl;

    /*output will be ='0'
    ---int/int=int
    ---float/int=float
    ---double/int=double
    */

   double b =2.300/5;
   cout<<b<<endl;

//---Relational Operators---(<, >, =, ==) //

int c =3;
int d=5;

bool  first=(c==d);
cout<<first<<endl;
bool  second=(c>d);
cout<<second<<endl;
bool third =(c<d);
cout<<third<<endl;
bool  fourth=(c<=d);
cout<<fourth<<endl;
bool  five=(c>=d);
cout<<five<<endl;


//logical operatords(&&, //, !) 
//---&&--- means sari condiiton fulfil honi chiye jaishe 23&&6ft&&80kgs then a person is fit agar inme se koi bhi nhihui to conditon fulfill nhi hai 
//---//---- means koi ek conditon bhi fulfil hogi to hojygea kaam for example 23//6ft//80kgs agar nme se koi bhi hoga to chal jyega kaam 
//----!----means something is false or worng so ture for exple int a=0 then cout <<!a<endl; gives as 1 means yes it is true 


}