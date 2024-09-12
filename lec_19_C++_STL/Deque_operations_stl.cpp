#include<iostream>

#include<deque>

using namespace std;

int main()
{
    std::cout<<"hellow world \n";

    deque<int>d;
    d.push_back(1);
    d.push_front(2);


    for(int i:d){
        cout<<i<<" ";
    }
    // d.pop_front()
cout<<endl;
cout<<"print first elment :: "<<d.at(1)<<endl;

cout<<"front"<<d.front()<<endl;
cout<<"back"<<d.back()<<endl;

cout<<"empty or not "<<d.empty()<<endl;

//d.erase(d.begin(), d.begin()+1) is used to delete or erase elment from begin() to begin()+1.


cout<<"before erase "<<d.size()<<endl;
d.erase(d.begin(),d.begin()+1);
cout<<"after erase "<<d.size()<<endl;

}