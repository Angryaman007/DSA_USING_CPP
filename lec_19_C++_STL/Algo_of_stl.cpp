#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{

    vector<int>v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 : "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"lower bound :" <<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
    cout<<"upper bound :" <<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;

    int a=3;
    int b=5;

    cout<<"max "<<max(a,b);
cout<<endl;
    cout<<"min "<<min(a,b);

    swap(a,b);

    cout<<endl<<"a :"<<a<<endl;

    string arr="abcd";

    reverse(arr.begin(), arr.end());
    cout<<"string : "<<arr<<endl;

rotate(v.begin(),v.begin()+1, v.end());
cout<<"after rotate : "<<endl;

for(int i:v)
{
    cout<<i<<" ";
}

//intro sort is used to fuction this sorting intro sort is combination of quick sort heap sort and insertion sort ....

cout<<endl;
sort(v.begin(),v.end());
cout<<"after sorting "<<endl;
for(int i:v)
{
    cout<<i<<" ";
}

}