#include<iostream>
using namespace std;

int main()
{
/*
// to print this type of pattern //

A
BB
CCC

 int n;
 cin>>n;

 int row=1;
 while (row<=n)
 {
    int col=1;
    while (col<=row)
    {
        char ch=('A'+row-1);
        cout<<ch;
        col=col+1;
    }
    cout<<endl;
    row=row+1;
 }


 
// to print a pattern like this 
A
BC
CDE
DEFG
EFGHI

int n;
cin>>n;

int row=1;
while (row<=n)
{
    int col=1;
    while (col<=row)
    {
        char ch =('A'+row+col-2);
        cout<<ch;
        col =col+1;
    }
    cout<<endl;
    row=row+1;
}


// to print a pattern like this 
D
CD
BCD
ABCD

int n;
cin>>n;

int row=1;
while (row<=n)
{
    int col=1;
    char start='A'+n-row;
    while (col<=row)
    {
        cout<<start;
        start=start+1;
        col=col+1;
    }
    cout<<endl;
    row=row+1;

}
*/

int n;

cin>>n;
int row=1;
while (row<=n)
{
int space=n-row;
while (space)
{
    cout<<" ";
    space=space-1;
}
int col=1;
while (col<=row)
{
    cout<<"*";
    col=col+1;
}
cout<<endl;
row=row+1;
}
}
