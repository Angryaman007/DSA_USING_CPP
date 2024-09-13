//-------IMPORTENT-----------//

//set is used to store only unique elemnts 
//we can not modify elements that are already inserted 
//Elements return in sorted manner 
#include<iostream>
#include<set>
using namespace std; 
int main()
{
set<int>s;
//how many times we insert the same elemnet it will take it as one unique elemnt to store 

s.insert(5);
s.insert(5);
s.insert(5);
s.insert(1);
s.insert(6);
s.insert(0);
s.insert(3);

for(auto i:s)
{
    cout<<i<<endl;
}
//output is 
/*
0
1
3
5
6
*/
cout<<endl;
set<int>::iterator it=s.begin();
it++;
s.erase(it);

for(auto i:s)
{
    cout<<i<<endl;
}

cout<<"5 is present or Not "<<s.count(5)<<endl;
cout<<"-5 is present or Not "<<s.count(-5)<<endl;

//find is used to find the elemnt and it prints the refrence of that elemnt given below code is used to give the refrence of the find elemnt 
set<int>::iterator itr=s.find(5);

for(auto it=itr; it!=s.end(); it++)
{
    cout<<*it<<" ";

}
cout<<endl;
}
