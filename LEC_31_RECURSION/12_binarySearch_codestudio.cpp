#include<iostream>
using namespace std;

void revers(string str, int i,int j)
{
    //base case

    if(i>j)
    return ;

    swap(str[i], str[j]);
    i++;
    j--;

}


int main()
{

string name="amam";

revers(name,0, name.length()-1);
cout<<name<<endl;


    return 0; 
}