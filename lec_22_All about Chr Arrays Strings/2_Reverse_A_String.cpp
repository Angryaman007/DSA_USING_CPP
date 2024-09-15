#include<iostream>
using namespace std;


void reverse(char name[], int n )
{
    int s=0;
    int e=n-1;
    while (s<e)
    {
        swap(name[s++], name[e--]);
    }
    
}
int getLenght(char name[])
{
    int count=0;
    for(int i=0; name[i] !='\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
char name[20];
cout<<"ENter the string "<<endl;

cin>>name;

int len=getLenght(name);
cout<<"length "<<len<<endl;
cout<<"reverse string is ";
reverse(name,len);
cout<<name<<endl;

}