#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int,string>m;

    m[1]="aman";
    m[10]="sana";
    m[14]="anu";
    m[21]="anchal";

    m.insert({5,"bheem"});
cout<<"befor erase "<<endl;

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"finding 13 "<<m.count(13)<<endl;
    cout<<"finding 14 "<<m.count(14)<<endl;

m.erase(14);
    cout<<"afer erase "<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it=m.find(5);

for( auto i=it; i!=m.end(); i++)
{
    cout<<(*i).first<<endl;
}
}